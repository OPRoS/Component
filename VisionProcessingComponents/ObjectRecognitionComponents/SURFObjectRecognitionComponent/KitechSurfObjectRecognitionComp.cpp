
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <OPRoSTypes.h>
#include <EventData.h>
#include <ServiceUtils.h>



#include "KitechSurfObjectRecognitionComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
KitechSurfObjectRecognitionComp::KitechSurfObjectRecognitionComp()
{

	
	portSetup();
}

//
// constructor declaration (with name)
//
KitechSurfObjectRecognitionComp::KitechSurfObjectRecognitionComp(const std::string &name):Component(name)
{

	
	portSetup();
}

//
// destructor declaration
//

KitechSurfObjectRecognitionComp::~KitechSurfObjectRecognitionComp() {
}
vector<VisionRecognitionResult> KitechSurfObjectRecognitionComp::Recognize(vector<unsigned char> image,int width,int height,int pixelBytes)
{
	vector<VisionRecognitionResult> _recognitionResult(0);

	IplImage *cvImage = cvCreateImageHeader( cvSize(width, height), 8, pixelBytes );
	cvImage->imageData = (char *)&image[0];

	IplImage *grayImage = cvCreateImage( cvGetSize(cvImage), 8, 1 );
	cvCvtColor( cvImage, grayImage, CV_BGR2GRAY );

    CvMemStorage *imageStorage = cvCreateMemStorage(0);
    CvSeq *imageKeypoints, *imageDescriptors;

	cvExtractSURF( grayImage, 0, &imageKeypoints, &imageDescriptors, imageStorage, cvSURFParams(500,1) );

	CvPoint src_corners[4] = {{0,0}, {_orgWidth,0}, {_orgWidth, _orgHeight}, {0, _orgHeight}};
	CvPoint dst_corners[4];

	if( LocatePlanarObject( _objectKeypoints, _objectDescriptors, imageKeypoints, imageDescriptors, src_corners, dst_corners ) ) {
		_recognitionResult.resize(1);

		_recognitionResult[0].name = _objName;
		_recognitionResult[0].point1X = dst_corners[0].x;
		_recognitionResult[0].point1Y = dst_corners[0].y;
		_recognitionResult[0].point2X = dst_corners[1].x;
		_recognitionResult[0].point2Y = dst_corners[1].y;
		_recognitionResult[0].point3X = dst_corners[2].x;
		_recognitionResult[0].point3Y = dst_corners[2].y;
		_recognitionResult[0].point4X = dst_corners[3].x;
		_recognitionResult[0].point4Y = dst_corners[3].y;
		//PrintMessage("KitechSurfObjectRecognitionComp::recognize() -> I found data.(%s)\n", _recognitionResult[0].name.c_str());
	}

	cvReleaseMemStorage( &imageStorage );

	cvReleaseImage( &grayImage );
	cvReleaseImageHeader( &cvImage );

	return _recognitionResult;
}

ReturnType KitechSurfObjectRecognitionComp::GetError()
{
	return OPROS_SUCCESS;
}

Property KitechSurfObjectRecognitionComp::GetParameter()
{
	return this->parameter;
}

ReturnType KitechSurfObjectRecognitionComp::SetParameter(Property parameter)
{
	this->parameter = parameter;
	return OPROS_SUCCESS;
}


double KitechSurfObjectRecognitionComp::CompareSURFDescriptors( const float* d1, const float* d2, double best, int length )
{
    double total_cost = 0;
    assert( length % 4 == 0 );
    for( int i = 0; i < length; i += 4 )
    {
        double t0 = d1[i] - d2[i];
        double t1 = d1[i+1] - d2[i+1];
        double t2 = d1[i+2] - d2[i+2];
        double t3 = d1[i+3] - d2[i+3];
        total_cost += t0*t0 + t1*t1 + t2*t2 + t3*t3;
        if( total_cost > best )
            break;
    }
    return total_cost;
}

int KitechSurfObjectRecognitionComp::NaiveNearestNeighbor( const float* vec, int laplacian, const CvSeq* model_keypoints, const CvSeq* model_descriptors )
{
   int length = (int)(model_descriptors->elem_size/sizeof(float));
    int i, neighbor = -1;
    double d, dist1 = 1e6, dist2 = 1e6;
    CvSeqReader reader, kreader;
    cvStartReadSeq( model_keypoints, &kreader, 0 );
    cvStartReadSeq( model_descriptors, &reader, 0 );

    for( i = 0; i < model_descriptors->total; i++ )
    {
        const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
        const float* mvec = (const float*)reader.ptr;
        CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
        CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
        if( laplacian != kp->laplacian )
            continue;
        d = CompareSURFDescriptors( vec, mvec, dist2, length );
        if( d < dist1 )
        {
            dist2 = dist1;
            dist1 = d;
            neighbor = i;
        }
        else if ( d < dist2 )
            dist2 = d;
    }
    if ( dist1 < 0.6*dist2 )
        return neighbor;
    return -1;
}

void KitechSurfObjectRecognitionComp::FindPairs( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors, const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, vector<int>& ptpairs )
{
    int i;
    CvSeqReader reader, kreader;
    cvStartReadSeq( objectKeypoints, &kreader );
    cvStartReadSeq( objectDescriptors, &reader );
    ptpairs.clear();

    for( i = 0; i < objectDescriptors->total; i++ )
    {
        const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
        const float* descriptor = (const float*)reader.ptr;
        CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
        CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
        int nearest_neighbor = NaiveNearestNeighbor( descriptor, kp->laplacian, imageKeypoints, imageDescriptors );
        if( nearest_neighbor >= 0 )
        {
            ptpairs.push_back(i);
            ptpairs.push_back(nearest_neighbor);
        }
    }
}

int KitechSurfObjectRecognitionComp::LocatePlanarObject( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors, const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, const CvPoint src_corners[4], CvPoint dst_corners[4] )
{
    double h[9];
    CvMat _h = cvMat(3, 3, CV_64F, h);
    vector<int> ptpairs;
    vector<CvPoint2D32f> pt1, pt2;
    CvMat _pt1, _pt2;
    int i, n;

    FindPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
    n = ptpairs.size()/2;
    if( n < 4 )
        return 0;

    pt1.resize(n);
    pt2.resize(n);
    for( i = 0; i < n; i++ )
    {
        pt1[i] = ((CvSURFPoint*)cvGetSeqElem(objectKeypoints,ptpairs[i*2]))->pt;
        pt2[i] = ((CvSURFPoint*)cvGetSeqElem(imageKeypoints,ptpairs[i*2+1]))->pt;
    }

    _pt1 = cvMat(1, n, CV_32FC2, &pt1[0] );
    _pt2 = cvMat(1, n, CV_32FC2, &pt2[0] );
    if( !cvFindHomography( &_pt1, &_pt2, &_h, CV_RANSAC, 5 ))
        return 0;

    for( i = 0; i < 4; i++ )
    {
        double x = src_corners[i].x, y = src_corners[i].y;
        double Z = 1./(h[6]*x + h[7]*y + h[8]);
        double X = (h[0]*x + h[1]*y + h[2])*Z;
        double Y = (h[3]*x + h[4]*y + h[5])*Z;
        dst_corners[i] = cvPoint(cvRound(X), cvRound(Y));
    }

    return 1;
}


void KitechSurfObjectRecognitionComp::portSetup() {
	ProvidedServicePort *pa1;
	pa1=new VisionRecognitionServiceProvided(this);
	addPort("VisionRecognitionService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType KitechSurfObjectRecognitionComp::onInitialize()
{
	PrintMessage ("KitechSurfObjectRecognitionComp::onInitialize()\n");

	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);
	
	if(parameter.FindName("DBName") == false) {
		PrintMessage("ERROR : KitechSurfObjectRecognitionComp::onInitialize() -> Can't find the DBName in property\n");
		return OPROS_FIND_PROPERTY_ERROR;
	}
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onStart()
{
	PrintMessage ("SUCCESS : KitechSurfObjectRecognitionComp::onStart()\n");
	//	dll 파일이름을 확인하여 없으면 에러 리턴
	if( !parameter.FindName("DBName") ) {
		PrintMessage("ERROR : KitechSurfObjectRecognitionComp::onStart() -> Can't find DataBase %s.\n", parameter.GetValue("DBName").c_str());
		return OPROS_FIND_PROPERTY_ERROR;
	}

	_objName = parameter.GetValue("DBName").c_str();
	IplImage *cvImage = cvLoadImage( _objName.c_str() );
	if( cvImage ) 	{
		IplImage *grayImage = cvCreateImage( cvGetSize(cvImage), 8, 1 );
		cvCvtColor( cvImage, grayImage, CV_BGR2GRAY );

		_objectStorage = cvCreateMemStorage(0);

		cvExtractSURF( grayImage, 0, &_objectKeypoints, &_objectDescriptors, _objectStorage, cvSURFParams(500,1) );

		PrintMessage("SUCCESS:SURF_ObjectRecognition::onStart() -> Successfully load %s\n", _objName.c_str());

		_orgWidth = grayImage->width;
		_orgHeight = grayImage->height;

		cvReleaseImage( &grayImage );
		cvReleaseImage( &cvImage );
	}
	else {
		PrintMessage("ERROR:SURF_ObjectRecognition::enable() -> Fail to load %s\n", _objName.c_str());
		return OPROS_CALLER_ERROR;
	}

	return OPROS_SUCCESS;
}
	
ReturnType KitechSurfObjectRecognitionComp::onStop()
{
#if defined(WIN32)
	Sleep(100);
#endif
	if( _objectStorage )
		cvReleaseMemStorage( &_objectStorage );

	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onExecute()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType KitechSurfObjectRecognitionComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KitechSurfObjectRecognitionComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}







#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new KitechSurfObjectRecognitionComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new KitechSurfObjectRecognitionComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

