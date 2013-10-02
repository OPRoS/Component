#ifndef _GripperService_PROVIDED_PORT_H
#define _GripperService_PROVIDED_PORT_H

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

#ifndef _IGripperService_CLASS_DEF
#define _IGripperService_CLASS_DEF
/*
 * IGripperService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IGripperService
{
 public:
    virtual ReturnType SetParameter(Property parameter)=0;
    virtual Property GetParameter()=0;
    virtual ReturnType GetError()=0;
    virtual ReturnType Enable()=0;
    virtual ReturnType Disable()=0;
    virtual ReturnType SetPower(vector<double> power,vector<unsigned long> time)=0;
    virtual vector<double> GetPower()=0;
    virtual ReturnType SetVelocity(vector<double> velocity,vector<unsigned long> time)=0;
    virtual vector<double> GetVelocity()=0;
    virtual ReturnType SetPosition(vector<double> position,vector<unsigned long> time)=0;
    virtual vector<double> GetPosition()=0;
    virtual ReturnType StartGripping()=0;
    virtual ReturnType StopGripping()=0;
    virtual bool IsGripped()=0;
 };
#endif

/*
 * 
 * GripperService : public ProvidedServicePort
 *
 */
class GripperServiceProvided
	:public ProvidedServicePort, public IGripperService
{
protected:
    IGripperService *pcom;


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

   typedef ProvidedMethod<ReturnType> SetPowerFuncType;
   SetPowerFuncType *SetPowerFunc;

   typedef ProvidedMethod< vector<double> > GetPowerFuncType;
   GetPowerFuncType *GetPowerFunc;

   typedef ProvidedMethod<ReturnType> SetVelocityFuncType;
   SetVelocityFuncType *SetVelocityFunc;

   typedef ProvidedMethod< vector<double> > GetVelocityFuncType;
   GetVelocityFuncType *GetVelocityFunc;

   typedef ProvidedMethod<ReturnType> SetPositionFuncType;
   SetPositionFuncType *SetPositionFunc;

   typedef ProvidedMethod< vector<double> > GetPositionFuncType;
   GetPositionFuncType *GetPositionFunc;

   typedef ProvidedMethod<ReturnType> StartGrippingFuncType;
   StartGrippingFuncType *StartGrippingFunc;

   typedef ProvidedMethod<ReturnType> StopGrippingFuncType;
   StopGrippingFuncType *StopGrippingFunc;

   typedef ProvidedMethod<bool> IsGrippedFuncType;
   IsGrippedFuncType *IsGrippedFunc;


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
   virtual ReturnType SetPower(vector<double> power,vector<unsigned long> time)
   {
		opros_assert(SetPowerFunc != NULL);
		
            return (*SetPowerFunc)(power,time);
		
   }
   virtual vector<double> GetPower()
   {
		opros_assert(GetPowerFunc != NULL);
		
            return (*GetPowerFunc)();
		
   }
   virtual ReturnType SetVelocity(vector<double> velocity,vector<unsigned long> time)
   {
		opros_assert(SetVelocityFunc != NULL);
		
            return (*SetVelocityFunc)(velocity,time);
		
   }
   virtual vector<double> GetVelocity()
   {
		opros_assert(GetVelocityFunc != NULL);
		
            return (*GetVelocityFunc)();
		
   }
   virtual ReturnType SetPosition(vector<double> position,vector<unsigned long> time)
   {
		opros_assert(SetPositionFunc != NULL);
		
            return (*SetPositionFunc)(position,time);
		
   }
   virtual vector<double> GetPosition()
   {
		opros_assert(GetPositionFunc != NULL);
		
            return (*GetPositionFunc)();
		
   }
   virtual ReturnType StartGripping()
   {
		opros_assert(StartGrippingFunc != NULL);
		
            return (*StartGrippingFunc)();
		
   }
   virtual ReturnType StopGripping()
   {
		opros_assert(StopGrippingFunc != NULL);
		
            return (*StopGrippingFunc)();
		
   }
   virtual bool IsGripped()
   {
		opros_assert(IsGrippedFunc != NULL);
		
            return (*IsGrippedFunc)();
		
   }


public:
    //
    // Constructor
    //
    GripperServiceProvided(IGripperService *fn)
    {
        pcom = fn;

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

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IGripperService::SetParameter,pcom,"SetParameter");

        opros_assert(ptr_method != NULL);
        addMethod("SetParameter",ptr_method);
        SetParameterFunc = reinterpret_cast<SetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::GetParameter,pcom,"GetParameter");

        opros_assert(ptr_method != NULL);
        addMethod("GetParameter",ptr_method);
        GetParameterFunc = reinterpret_cast<GetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::Enable,pcom,"Enable");

        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::Disable,pcom,"Disable");

        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::SetPower,pcom,"SetPower");

        opros_assert(ptr_method != NULL);
        addMethod("SetPower",ptr_method);
        SetPowerFunc = reinterpret_cast<SetPowerFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::GetPower,pcom,"GetPower");

        opros_assert(ptr_method != NULL);
        addMethod("GetPower",ptr_method);
        GetPowerFunc = reinterpret_cast<GetPowerFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::SetVelocity,pcom,"SetVelocity");

        opros_assert(ptr_method != NULL);
        addMethod("SetVelocity",ptr_method);
        SetVelocityFunc = reinterpret_cast<SetVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::GetVelocity,pcom,"GetVelocity");

        opros_assert(ptr_method != NULL);
        addMethod("GetVelocity",ptr_method);
        GetVelocityFunc = reinterpret_cast<GetVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::SetPosition,pcom,"SetPosition");

        opros_assert(ptr_method != NULL);
        addMethod("SetPosition",ptr_method);
        SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::GetPosition,pcom,"GetPosition");

        opros_assert(ptr_method != NULL);
        addMethod("GetPosition",ptr_method);
        GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::StartGripping,pcom,"StartGripping");

        opros_assert(ptr_method != NULL);
        addMethod("StartGripping",ptr_method);
        StartGrippingFunc = reinterpret_cast<StartGrippingFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::StopGripping,pcom,"StopGripping");

        opros_assert(ptr_method != NULL);
        addMethod("StopGripping",ptr_method);
        StopGrippingFunc = reinterpret_cast<StopGrippingFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGripperService::IsGripped,pcom,"IsGripped");

        opros_assert(ptr_method != NULL);
        addMethod("IsGripped",ptr_method);
        IsGrippedFunc = reinterpret_cast<IsGrippedFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
