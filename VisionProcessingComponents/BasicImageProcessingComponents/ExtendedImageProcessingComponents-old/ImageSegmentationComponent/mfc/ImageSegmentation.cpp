
#include "stdafx.h"
	
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <OPRoSTypes.h>
#include <EventData.h>
#include <ServiceUtils.h>



#include "ImageSegmentation.h"

//
// constructor declaration
//
ImageSegmentation::ImageSegmentation()
		:ImageIn(OPROS_LAST,1)
{

	
	portSetup();
}

//
// constructor declaration (with name)
//
ImageSegmentation::ImageSegmentation(const std::string &name):Component(name)
		,ImageIn(OPROS_LAST,1)
{

	
	portSetup();
}

//
// destructor declaration
//

ImageSegmentation::~ImageSegmentation() {
}

void ImageSegmentation::portSetup() {

	// data port setup

	addPort("ImageOut", &ImageOut);

	addPort("ImageIn", &ImageIn);



	// export variable setup


}

// Call back Declaration
ReturnType ImageSegmentation::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType ImageSegmentation::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onExecute()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType ImageSegmentation::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ImageSegmentation::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}







#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new ImageSegmentation();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new ImageSegmentation();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

