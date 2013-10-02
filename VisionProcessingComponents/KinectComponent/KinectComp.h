
#ifndef _KinectComp_COMPONENT_H
#define _KinectComp_COMPONENT_H
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
#include <OprosLock.h>

#include "Kinect.h"

#include "KinectServiceProvided.h"

class KinectComp: public Component
	,public IKinectService
{
protected:
	// event
	OutputEventPort< KinectEvent > mKinectOutputEvent;

protected:
	// service
	// method for provider
	IKinectService *ptrKinectService;

public:
	KinectComp();
	KinectComp(const std::string &compId);
	virtual ~KinectComp();
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
	
public:
	virtual bool SetParameter(Property parameter);
	virtual Property GetParameter();
	virtual bool SetCameraAngle(float degree);
	virtual float GetCameraAngle();
	virtual vector<Skeleton> GetSkeletonAll();
	virtual Skeleton GetSkeleton(unsigned long id);
	virtual vector<unsigned long> GetSkeletonID();
	virtual ImageFrame GetImage();
	virtual DepthFrame GetDepthImage();
	virtual Position GetPixelDepth(int x,int y);

private:
	ReturnType SendEvent(const KinectEvent& event); 

private:
	Kinect* mpKinect;
	OprosApiHandle mhOprosAPI;
	
	vector<unsigned long> mSaveID;
};

#endif

