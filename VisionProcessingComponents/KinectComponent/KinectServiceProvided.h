

#ifndef _KinectService_PROVIDED_PORT_H
#define _KinectService_PROVIDED_PORT_H

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
#include "KinectDataType.h"		

#ifndef _IKinectService_CLASS_DEF
#define _IKinectService_CLASS_DEF
/*
 * IKinectService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IKinectService
{
 public:
    virtual bool SetParameter(Property parameter)=0;
    virtual Property GetParameter()=0;
    virtual bool SetCameraAngle(float degree)=0;
    virtual float GetCameraAngle()=0;
    virtual vector<Skeleton> GetSkeletonAll()=0;
    virtual Skeleton GetSkeleton(unsigned long id)=0;
    virtual vector<unsigned long> GetSkeletonID()=0;
    virtual ImageFrame GetImage()=0;
    virtual DepthFrame GetDepthImage()=0;
    virtual Position GetPixelDepth(int x,int y)=0;
 };
#endif

/*
 * 
 * KinectService : public ProvidedServicePort
 *
 */
class KinectServiceProvided
	:public ProvidedServicePort, public IKinectService
{
protected:
    IKinectService *pcom;


   typedef ProvidedMethod<bool> SetParameterFuncType;
   SetParameterFuncType *SetParameterFunc;

   typedef ProvidedMethod<Property> GetParameterFuncType;
   GetParameterFuncType *GetParameterFunc;

   typedef ProvidedMethod<bool> SetCameraAngleFuncType;
   SetCameraAngleFuncType *SetCameraAngleFunc;

   typedef ProvidedMethod<float> GetCameraAngleFuncType;
   GetCameraAngleFuncType *GetCameraAngleFunc;

   typedef ProvidedMethod<vector<Skeleton>> GetSkeletonAllFuncType;
   GetSkeletonAllFuncType *GetSkeletonAllFunc;

   typedef ProvidedMethod<Skeleton> GetSkeletonFuncType;
   GetSkeletonFuncType *GetSkeletonFunc;

   typedef ProvidedMethod<vector<unsigned long>> GetSkeletonIDFuncType;
   GetSkeletonIDFuncType *GetSkeletonIDFunc;

   typedef ProvidedMethod<ImageFrame> GetImageFuncType;
   GetImageFuncType *GetImageFunc;

   typedef ProvidedMethod<DepthFrame> GetDepthImageFuncType;
   GetDepthImageFuncType *GetDepthImageFunc;

   typedef ProvidedMethod<Position> GetPixelDepthFuncType;
   GetPixelDepthFuncType *GetPixelDepthFunc;


public: // default method
   virtual bool SetParameter(Property parameter)
   {
		opros_assert(SetParameterFunc != NULL);
		
            return (*SetParameterFunc)(parameter);
		
   }
   virtual Property GetParameter()
   {
		opros_assert(GetParameterFunc != NULL);
		
            return (*GetParameterFunc)();
		
   }
   virtual bool SetCameraAngle(float degree)
   {
		opros_assert(SetCameraAngleFunc != NULL);
		
            return (*SetCameraAngleFunc)(degree);
		
   }
   virtual float GetCameraAngle()
   {
		opros_assert(GetCameraAngleFunc != NULL);
		
            return (*GetCameraAngleFunc)();
		
   }
   virtual vector<Skeleton> GetSkeletonAll()
   {
		opros_assert(GetSkeletonAllFunc != NULL);
		
            return (*GetSkeletonAllFunc)();
		
   }
   virtual Skeleton GetSkeleton(unsigned long id)
   {
		opros_assert(GetSkeletonFunc != NULL);
		
            return (*GetSkeletonFunc)(id);
		
   }
   virtual vector<unsigned long> GetSkeletonID()
   {
		opros_assert(GetSkeletonIDFunc != NULL);
		
            return (*GetSkeletonIDFunc)();
		
   }
   virtual ImageFrame GetImage()
   {
		opros_assert(GetImageFunc != NULL);
		
            return (*GetImageFunc)();
		
   }
   virtual DepthFrame GetDepthImage()
   {
		opros_assert(GetDepthImageFunc != NULL);
		
            return (*GetDepthImageFunc)();
		
   }
   virtual Position GetPixelDepth(int x,int y)
   {
		opros_assert(GetPixelDepthFunc != NULL);
		
            return (*GetPixelDepthFunc)(x,y);
		
   }


public:
    //
    // Constructor
    //
    KinectServiceProvided(IKinectService *fn)
    {
        pcom = fn;

        SetParameterFunc = NULL;
        GetParameterFunc = NULL;
        SetCameraAngleFunc = NULL;
        GetCameraAngleFunc = NULL;
        GetSkeletonAllFunc = NULL;
        GetSkeletonFunc = NULL;
        GetSkeletonIDFunc = NULL;
        GetImageFunc = NULL;
        GetDepthImageFunc = NULL;
        GetPixelDepthFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IKinectService::SetParameter,pcom,"SetParameter");

        opros_assert(ptr_method != NULL);
        addMethod("SetParameter",ptr_method);
        SetParameterFunc = reinterpret_cast<SetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetParameter,pcom,"GetParameter");

        opros_assert(ptr_method != NULL);
        addMethod("GetParameter",ptr_method);
        GetParameterFunc = reinterpret_cast<GetParameterFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::SetCameraAngle,pcom,"SetCameraAngle");

        opros_assert(ptr_method != NULL);
        addMethod("SetCameraAngle",ptr_method);
        SetCameraAngleFunc = reinterpret_cast<SetCameraAngleFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetCameraAngle,pcom,"GetCameraAngle");

        opros_assert(ptr_method != NULL);
        addMethod("GetCameraAngle",ptr_method);
        GetCameraAngleFunc = reinterpret_cast<GetCameraAngleFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetSkeletonAll,pcom,"GetSkeletonAll");

        opros_assert(ptr_method != NULL);
        addMethod("GetSkeletonAll",ptr_method);
        GetSkeletonAllFunc = reinterpret_cast<GetSkeletonAllFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetSkeleton,pcom,"GetSkeleton");

        opros_assert(ptr_method != NULL);
        addMethod("GetSkeleton",ptr_method);
        GetSkeletonFunc = reinterpret_cast<GetSkeletonFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetSkeletonID,pcom,"GetSkeletonID");

        opros_assert(ptr_method != NULL);
        addMethod("GetSkeletonID",ptr_method);
        GetSkeletonIDFunc = reinterpret_cast<GetSkeletonIDFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetImage,pcom,"GetImage");

        opros_assert(ptr_method != NULL);
        addMethod("GetImage",ptr_method);
        GetImageFunc = reinterpret_cast<GetImageFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetDepthImage,pcom,"GetDepthImage");

        opros_assert(ptr_method != NULL);
        addMethod("GetDepthImage",ptr_method);
        GetDepthImageFunc = reinterpret_cast<GetDepthImageFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IKinectService::GetPixelDepth,pcom,"GetPixelDepth");

        opros_assert(ptr_method != NULL);
        addMethod("GetPixelDepth",ptr_method);
        GetPixelDepthFunc = reinterpret_cast<GetPixelDepthFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
