#ifndef _ForceTorqueSensorService_PROVIDED_PORT_H
#define _ForceTorqueSensorService_PROVIDED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>

#include "Property.h"
#include "ApiTypes.h"

#ifndef _IForceTorqueSensorService_CLASS_DEF
#define _IForceTorqueSensorService_CLASS_DEF
/*
 * IForceTorqueSensorService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IForceTorqueSensorService
{
public:
	virtual ReturnType SetParameter(Property parameter)=0;
	virtual Property GetParameter()=0;
	virtual ReturnType GetError()=0;
	virtual ReturnType Enable()=0;
	virtual ReturnType Disable()=0;
	virtual vector<ForceTorqueSensorData> GetSensorValue()=0;
};
#endif

/*
 * 
 * ForceTorqueSensorService : public ProvidedServicePort
 *
 */
class ForceTorqueSensorServiceProvided : public ProvidedServicePort, public IForceTorqueSensorService
{
protected:
	IForceTorqueSensorService *pcom;

	typedef ProvidedMethod<ReturnType> SetParameterFuncType;
	SetParameterFuncType *SetParameterFunc;

	typedef ProvidedMethod<Property> GetParameterFuncType;
	GetParameterFuncType *GetParameterFunc;

	typedef ProvidedMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef ProvidedMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef ProvidedMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef ProvidedMethod< vector<ForceTorqueSensorData> > GetSensorValueFuncType;
	GetSensorValueFuncType *GetSensorValueFunc;

public: // default method
	virtual ReturnType SetParameter(Property parameter)
	{
		opros_assert(SetParameterFunc != NULL);

		return (*SetParameterFunc)(parameter);
	}

	virtual Property GetParameter()
	{
		opros_assert(GetParameterFunc != NULL);

		return (*GetParameterFunc)();
	}

	virtual ReturnType GetError()
	{
		opros_assert(GetErrorFunc != NULL);

		return (*GetErrorFunc)();
	}

	virtual ReturnType Enable()
	{
		opros_assert(EnableFunc != NULL);

		return (*EnableFunc)();
	}

	virtual ReturnType Disable()
	{
		opros_assert(DisableFunc != NULL);

		return (*DisableFunc)();
	}

	virtual vector<ForceTorqueSensorData> GetSensorValue()
	{
		opros_assert(GetSensorValueFunc != NULL);

		return (*GetSensorValueFunc)();
	}

public:
    //
    // Constructor
    //
	ForceTorqueSensorServiceProvided(IForceTorqueSensorService *fn)
	{
		pcom = fn;

		SetParameterFunc = NULL;
		GetParameterFunc = NULL;
		GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		GetSensorValueFunc = NULL;

		setup();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::SetParameter,pcom,"SetParameter");
		opros_assert(ptr_method != NULL);
		addMethod("SetParameter",ptr_method);
		SetParameterFunc = reinterpret_cast<SetParameterFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::GetParameter,pcom,"GetParameter");
		opros_assert(ptr_method != NULL);
		addMethod("GetParameter",ptr_method);
		GetParameterFunc = reinterpret_cast<GetParameterFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::Enable,pcom,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::Disable,pcom,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IForceTorqueSensorService::GetSensorValue,pcom,"GetSensorValue");
		opros_assert(ptr_method != NULL);
		addMethod("GetSensorValue",ptr_method);
		GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
