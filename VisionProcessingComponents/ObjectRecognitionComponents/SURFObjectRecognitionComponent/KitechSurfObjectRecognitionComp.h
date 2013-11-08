
#ifndef _KitechSurfObjectRecognitionComp_COMPONENT_H
#define _KitechSurfObjectRecognitionComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <Event.h>
#include <OPRoSTypes.h>

#include "opencv/cv.h"
#include "opencv/highgui.h"


#include "VisionRecognitionServiceProvided.h"

class KitechSurfObjectRecognitionComp: public Component
	,public IVisionRecognitionService
{
protected:
	Property parameter;
	int _orgWidth, _orgHeight;
    CvMemStorage *_objectStorage;
    CvSeq *_objectKeypoints, *_objectDescriptors;
	std::string _objName;
// service
// method for provider
	IVisionRecognitionService *ptrVisionRecognitionService;

public:
	virtual ReturnType SetParameter(Property parameter);
	virtual Property GetParameter();
	virtual ReturnType GetError();
	virtual vector<VisionRecognitionResult> Recognize(vector<unsigned char> image,int width,int height,int pixelBytes);

protected :
	double CompareSURFDescriptors( const float* d1, const float* d2, double best, int length );
	int NaiveNearestNeighbor( const float* vec, int laplacian, const CvSeq* model_keypoints, const CvSeq* model_descriptors );
	void FindPairs( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors, const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, vector<int>& ptpairs );
	int LocatePlanarObject( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors, const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, const CvPoint src_corners[4], CvPoint dst_corners[4] );

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	KitechSurfObjectRecognitionComp();
	KitechSurfObjectRecognitionComp(const std::string &compId);
	virtual ~KitechSurfObjectRecognitionComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();


};

#endif

