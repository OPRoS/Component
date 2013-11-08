#ifndef _GripperService_REQUIRED_PORT_H
#define _GripperService_REQUIRED_PORT_H

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

/*
 * 
 * GripperService : public RequiredServicePort
 *
 */
class GripperServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetParameterFuncType;
	SetParameterFuncType *SetParameterFunc;

	typedef RequiredMethod<Property> GetParameterFuncType;
	GetParameterFuncType *GetParameterFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef RequiredMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef RequiredMethod<ReturnType> SetPowerFuncType;
	SetPowerFuncType *SetPowerFunc;

	typedef RequiredMethod< vector<double> > GetPowerFuncType;
	GetPowerFuncType *GetPowerFunc;

	typedef RequiredMethod<ReturnType> SetVelocityFuncType;
	SetVelocityFuncType *SetVelocityFunc;

	typedef RequiredMethod< vector<double> > GetVelocityFuncType;
	GetVelocityFuncType *GetVelocityFunc;

	typedef RequiredMethod<ReturnType> SetPositionFuncType;
	SetPositionFuncType *SetPositionFunc;

	typedef RequiredMethod< vector<double> > GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;

	typedef RequiredMethod<ReturnType> StartGrippingFuncType;
	StartGrippingFuncType *StartGrippingFunc;

	typedef RequiredMethod<ReturnType> StopGrippingFuncType;
	StopGrippingFuncType *StopGrippingFunc;

	typedef RequiredMethod<bool> IsGrippedFuncType;
	IsGrippedFuncType *IsGrippedFunc;

public:
	//
	// Constructor
	//
	GripperServiceRequired()
	{
            SetParameterFunc = NULL;
            GetParameterFunc = NULL;
            GetErrorFunc = NULL;
            EnableFunc = NULL;
            DisableFunc = NULL;
            SetPowerFunc = NULL;
            GetPowerFunc = NULL;
            SetVelocityFunc = NULL;
            GetVelocityFunc = NULL;
            SetPositionFunc = NULL;
            GetPositionFunc = NULL;
            StartGrippingFunc = NULL;
            StopGrippingFunc = NULL;
            IsGrippedFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	ReturnType SetParameter(Property parameter)
	{
            opros_assert(SetParameterFunc != NULL);
	
            return (*SetParameterFunc)(parameter);
		
	}

	Property GetParameter()
	{
            opros_assert(GetParameterFunc != NULL);
	
            return (*GetParameterFunc)();
		
	}

	ReturnType GetError()
	{
            opros_assert(GetErrorFunc != NULL);
	
            return (*GetErrorFunc)();
		
	}

	ReturnType Enable()
	{
            opros_assert(EnableFunc != NULL);
	
            return (*EnableFunc)();
		
	}

	ReturnType Disable()
	{
            opros_assert(DisableFunc != NULL);
	
            return (*DisableFunc)();
		
	}

	ReturnType SetPower(vector<double> power,vector<unsigned long> time)
	{
            opros_assert(SetPowerFunc != NULL);
	
            return (*SetPowerFunc)(power,time);
		
	}

	vector<double> GetPower()
	{
            opros_assert(GetPowerFunc != NULL);
	
            return (*GetPowerFunc)();
		
	}

	ReturnType SetVelocity(vector<double> velocity,vector<unsigned long> time)
	{
            opros_assert(SetVelocityFunc != NULL);
	
            return (*SetVelocityFunc)(velocity,time);
		
	}

	vector<double> GetVelocity()
	{
            opros_assert(GetVelocityFunc != NULL);
	
            return (*GetVelocityFunc)();
		
	}

	ReturnType SetPosition(vector<double> position,vector<unsigned long> time)
	{
            opros_assert(SetPositionFunc != NULL);
	
            return (*SetPositionFunc)(position,time);
		
	}

	vector<double> GetPosition()
	{
            opros_assert(GetPositionFunc != NULL);
	
            return (*GetPositionFunc)();
		
	}

	ReturnType StartGripping()
	{
            opros_assert(StartGrippingFunc != NULL);
	
            return (*StartGrippingFunc)();
		
	}

	ReturnType StopGripping()
	{
            opros_assert(StopGrippingFunc != NULL);
	
            return (*StopGrippingFunc)();
		
	}

	bool IsGripped()
	{
            opros_assert(IsGrippedFunc != NULL);
	
            return (*IsGrippedFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::SetParameter,"SetParameter");
        opros_assert(ptr_method != NULL);
        addMethod("SetParameter",ptr_method);
        SetParameterFunc = reinterpret_cast<SetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::GetParameter,"GetParameter");
        opros_assert(ptr_method != NULL);
        addMethod("GetParameter",ptr_method);
        GetParameterFunc = reinterpret_cast<GetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::Enable,"Enable");
        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::Disable,"Disable");
        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::SetPower,"SetPower");
        opros_assert(ptr_method != NULL);
        addMethod("SetPower",ptr_method);
        SetPowerFunc = reinterpret_cast<SetPowerFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::GetPower,"GetPower");
        opros_assert(ptr_method != NULL);
        addMethod("GetPower",ptr_method);
        GetPowerFunc = reinterpret_cast<GetPowerFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::SetVelocity,"SetVelocity");
        opros_assert(ptr_method != NULL);
        addMethod("SetVelocity",ptr_method);
        SetVelocityFunc = reinterpret_cast<SetVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::GetVelocity,"GetVelocity");
        opros_assert(ptr_method != NULL);
        addMethod("GetVelocity",ptr_method);
        GetVelocityFunc = reinterpret_cast<GetVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::SetPosition,"SetPosition");
        opros_assert(ptr_method != NULL);
        addMethod("SetPosition",ptr_method);
        SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::GetPosition,"GetPosition");
        opros_assert(ptr_method != NULL);
        addMethod("GetPosition",ptr_method);
        GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::StartGripping,"StartGripping");
        opros_assert(ptr_method != NULL);
        addMethod("StartGripping",ptr_method);
        StartGrippingFunc = reinterpret_cast<StartGrippingFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::StopGripping,"StopGripping");
        opros_assert(ptr_method != NULL);
        addMethod("StopGripping",ptr_method);
        StopGrippingFunc = reinterpret_cast<StopGrippingFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GripperServiceRequired::IsGripped,"IsGripped");
        opros_assert(ptr_method != NULL);
        addMethod("IsGripped",ptr_method);
        IsGrippedFunc = reinterpret_cast<IsGrippedFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
