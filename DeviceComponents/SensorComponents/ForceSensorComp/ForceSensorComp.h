#ifndef _ForceSensorComp_COMPONENT_H
#define _ForceSensorComp_COMPONENT_H
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

#include "ForceSensorServiceProvided.h"
#include "ForceSensor.h"
#include "OprosLock.h"

class ForceSensorComp : public Component, public IForceSensorService
{
protected:
	//	Data Port
	OutputDataPort< vector<double> > forceSensorData;

	//	Service Port
	IForceSensorService *ptrForceSensorService;

	//	Shared(Dynamic Linked) Library's Handle
	OprosApiHandle hOprosAPI;

	//	Last Error
	ReturnType lastError;

	//	API's Handle
	ForceSensor *forceSensor;

	OprosLock lock;

public:
	virtual ReturnType SetParameter(Property parameter);
	virtual Property GetParameter();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual vector<double> GetSensorValue();

public:
	ForceSensorComp();
	ForceSensorComp(const std::string &compId);
	virtual ~ForceSensorComp();
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

