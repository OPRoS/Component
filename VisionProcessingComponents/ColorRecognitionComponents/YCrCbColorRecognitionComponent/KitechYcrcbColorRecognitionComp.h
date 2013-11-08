
#ifndef _KitechYcrcbColorRecognitionComp_COMPONENT_H
#define _KitechYcrcbColorRecognitionComp_COMPONENT_H
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

#include "VisionRecognitionServiceProvided.h"

class KitechYcrcbColorRecognitionComp: public Component
	,public IVisionRecognitionService
{
protected:
	Property parameter;
	std::vector<ColorRange>	_colorRange;

// service
// method for provider
	IVisionRecognitionService *ptrVisionRecognitionService;

public:
	virtual ReturnType SetParameter(Property parameter);
	virtual Property GetParameter();
	virtual ReturnType GetError();
	virtual vector<VisionRecognitionResult> Recognize(vector<unsigned char> image,int width,int height,int pixelBytes);

	void GetDataFromDB(const char* database);
	void SetDataToDB(const char* database);
protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	KitechYcrcbColorRecognitionComp();
	KitechYcrcbColorRecognitionComp(const std::string &compId);
	virtual ~KitechYcrcbColorRecognitionComp();
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

