/*************************************************************

 file: GripperComp.cpp
 author: E.C. Shin
 begin: January 31 2011
 copyright: (c) 2011 KITECH, OPRoS
 email: unchol@kitech.re.kr

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 Less GNU General Public License for more details. 

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see 
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see 
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

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

#include "GripperComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
GripperComp::GripperComp()
{
	hOprosAPI = NULL;
	gripper = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
GripperComp::GripperComp(const std::string &name):Component(name)
{
	hOprosAPI = NULL;
	gripper = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

GripperComp::~GripperComp() 
{
	onDestroy();
}

ReturnType GripperComp::SetParameter(Property parameter)
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::SetParameter() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->SetParameter(parameter) < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

Property GripperComp::GetParameter()
{
	Property parameter;

	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::GetParameter() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->GetParameter(parameter) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return parameter;
}

ReturnType GripperComp::GetError()
{
	return lastError;
}

ReturnType GripperComp::Enable()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::Enable() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->Enable() < 0) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}
	
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::Disable()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::Disable() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->Disable() < 0) {
		return lastError = OPROS_DISABLE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::SetPower(vector<double> power,vector<unsigned long> time)
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::SetPower() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->SetPower(power, time) < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

vector<double> GripperComp::GetPower()
{
	vector<double> power;

	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::ManipulatorComp() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->GetPower(power) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return power;
}

ReturnType GripperComp::SetVelocity(vector<double> velocity,vector<unsigned long> time)
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::SetVelocity() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->SetVelocity(velocity, time) < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

vector<double> GripperComp::GetVelocity()
{
	vector<double> velocity;

	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::GetVelocity() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->GetVelocity(velocity) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return velocity;
}

ReturnType GripperComp::SetPosition(vector<double> position,vector<unsigned long> time)
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::SetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->SetPosition(position, time) < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

vector<double> GripperComp::GetPosition()
{
	vector<double> position;

	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::GetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->GetPosition(position) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return position;
}

ReturnType GripperComp::StartGripping()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::StartGripping() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->StartGripping() < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::StopGripping()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::StopGripping() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->StopGripping() < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

bool GripperComp::IsGripped()
{
	bool isGripped;

	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::StopGripping() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->IsGripped(isGripped) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return isGripped;
}

void GripperComp::portSetup()
{
	ProvidedServicePort *pa1;
	pa1=new GripperServiceProvided(this);
	addPort("GripperService",pa1);

	// export variable setup
}

// Call back Declaration
ReturnType GripperComp::onInitialize()
{
	Property parameter;
	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);
	
	if(parameter.FindName("ApiName") == false) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't find the APIName in property\n");
		return lastError = OPROS_FIND_PROPERTY_ERROR;
	}

	
#if defined(WIN32)
	//	DLL 로드
	hOprosAPI = LoadLibrary((LPCSTR)parameter.GetValue("ApiName").c_str());
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}
	
	//	API 로드
	GET_OPROS_API getOprosAPI;
	getOprosAPI = (GET_OPROS_API)GetProcAddress(hOprosAPI, "GetAPI");
	if(getOprosAPI == NULL) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#else
	hOprosAPI = dlopen(parameter.GetValue("ApiName").c_str(), RTLD_LAZY);
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}

	GET_OPROS_API getOprosAPI;
	getOprosAPI = (GET_OPROS_API)dlsym(hOprosAPI, "GetAPI");
	char *error = dlerror();
	if(error != NULL) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		dlclose(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#endif
	
	gripper = dynamic_cast<Gripper *>(getOprosAPI());
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::onInitialize() -> Can't get a handle of Actuator API\n");
#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}

	if(gripper->Initialize(parameter) != API_SUCCESS) {
		delete gripper;
		gripper = NULL;

#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
		return lastError = OPROS_INITIALIZE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onStart()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::onStart() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->Enable() == API_ERROR) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}

	if(gripper->RunHoming() == API_ERROR) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}
	
ReturnType GripperComp::onStop()
{
	if(gripper == NULL) {
		PrintMessage("ERROR : GripperComp::onStop() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(gripper->Disable() < 0) {
		return lastError = OPROS_DISABLE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onReset()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onError()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onRecover()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onDestroy()
{
	if(gripper != NULL) {
		gripper->Finalize();
		delete gripper;
		gripper = NULL;
	}

	if(hOprosAPI != NULL) {
#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onEvent(Event *evt)
{
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onExecute()
{
	return lastError = OPROS_SUCCESS;
}
	
ReturnType GripperComp::onUpdated()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType GripperComp::onPeriodChanged()
{
	return lastError = OPROS_SUCCESS;
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
	return new GripperComp();
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
	return new GripperComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

