
#include "ObjectTrackingApp.h"
	
#ifndef _ObjectTracking_COMPONENT_H
#define _ObjectTracking_COMPONENT_H
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

#include <vector>

#include <cv.h>
#include <highgui.h>

#include "RawImage.h"
#include "PositionDataType.h"
		


class ObjectTracking: public Component
{
protected:
// data

	InputDataPort< RawImage > ImageIn;
	OutputDataPort< std::vector<PositionDataType> > PositionOut;

//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	ObjectTracking();
	ObjectTracking(const std::string &compId);
	virtual ~ObjectTracking();
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

