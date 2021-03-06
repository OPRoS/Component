#ifndef _ForceTorqueSensorComp_COMPONENT_H
#define _ForceTorqueSensorComp_COMPONENT_H
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

#include "ForceTorqueSensorServiceProvided.h"
#include "ForceTorqueSensor.h"
#include "OprosLock.h"

class ForceTorqueSensorComp : public Component, public IForceTorqueSensorService
{
protected:
	//	Data Port
	OutputDataPort< vector<ForceTorqueSensorData> > forceTorqueSensorData;

	//	Service Port
	IForceTorqueSensorService *ptrForceTorqueSensorService;

	//	Shared(Dynamic Linked) Library's Handle
	OprosApiHandle hOprosAPI;

	//	Last Error
	ReturnType lastError;

	//	API's Handle
	ForceTorqueSensor *forceTorqueSensor;

	OprosLock lock;

public:
	virtual ReturnType SetParameter(Property parameter);
	virtual Property GetParameter();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual vector<ForceTorqueSensorData> GetSensorValue();

public:
	ForceTorqueSensorComp();
	ForceTorqueSensorComp(const std::string &compId);
	virtual ~ForceTorqueSensorComp();
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

