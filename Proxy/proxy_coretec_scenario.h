
#ifndef Define__Nerv__Data__proxy_coretec_scenario__proxy_coretec_scenario_h
#define Define__Nerv__Data__proxy_coretec_scenario__proxy_coretec_scenario_h

#include <Nerv/Method/CoretecScenario/CoretecScenario.h>

#include <boost/python.hpp>
namespace py = boost::python;

class proxy_coretec_scenario : public proxy_interface_CoretecScenario, public py::wrapper<proxy_coretec_scenario>
{
public :
	proxy_coretec_scenario();
	~proxy_coretec_scenario();

virtual void on_object_create();
virtual void on_object_destroy();



/********************************************************************************************************************************************
 Method      : CO00_MonitoringReady
 Input       : Coretec :: AI00_MonitoringReady
 Output      : 
 Method Type :	COMMAND
 Code        : 0x0000
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_CO00_MonitoringReady_disconnected();

/********************************************************************************************************************************************
 Method      : CO01_SpawnInfo
 Input       : Coretec :: AI06_SpawnInfo
 Output      : 
 Method Type :	COMMAND
 Code        : 0x0001
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_CO01_SpawnInfo_disconnected();

/********************************************************************************************************************************************
 Method      : CO02_ControlInfo
 Input       : Coretec :: AI12_ControlInfo
 Output      : 
 Method Type :	COMMAND
 Code        : 0x0002
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_CO02_ControlInfo_disconnected();

/********************************************************************************************************************************************
 Method      : CO03_DeleteObjectInfo
 Input       : Coretec :: AI14_DeleteObjectInfo
 Output      : 
 Method Type :	COMMAND
 Code        : 0x0003
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_CO03_DeleteObjectInfo_disconnected();

/********************************************************************************************************************************************
 Method      : CO04_StringInfo
 Input       : Coretec :: AI15_StringInfo
 Output      : 
 Method Type :	COMMAND
 Code        : 0x0004
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_CO04_StringInfo_disconnected();

/********************************************************************************************************************************************
 Method      : IN00_AllAgentsInformation
 Input       : 
 Output      : Dongguk :: AA08_AllAgentsInformation
 Method Type :	INFORMATION
 Code        : 0x1000
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN00_AllAgentsInformation_disconnected ();
virtual void on_IN00_AllAgentsInformation_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::AA08_AllAgentsInformation const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN01_ScenarioSetting
 Input       : 
 Output      : Dongguk :: SC00_ScenarioSetting
 Method Type :	INFORMATION
 Code        : 0x1001
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN01_ScenarioSetting_disconnected ();
virtual void on_IN01_ScenarioSetting_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC00_ScenarioSetting const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN02_CustomEventList
 Input       : 
 Output      : Dongguk :: CE03_CustomEventList
 Method Type :	INFORMATION
 Code        : 0x1002
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN02_CustomEventList_disconnected ();
virtual void on_IN02_CustomEventList_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::CE03_CustomEventList const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN03_ScenarioSignalInfo
 Input       : 
 Output      : Dongguk :: SC01_ScenarioSignalInfo
 Method Type :	INFORMATION
 Code        : 0x1003
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN03_ScenarioSignalInfo_disconnected ();
virtual void on_IN03_ScenarioSignalInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC01_ScenarioSignalInfo const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN04_Tick
 Input       : 
 Output      : Dongguk :: SC02_Tick
 Method Type :	INFORMATION
 Code        : 0x1004
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN04_Tick_disconnected ();
virtual void on_IN04_Tick_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC02_Tick const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN05_CrashInfo
 Input       : 
 Output      : Dongguk :: SC03_CrashInfo
 Method Type :	INFORMATION
 Code        : 0x1005
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN05_CrashInfo_disconnected ();
virtual void on_IN05_CrashInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC03_CrashInfo const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN06_InterruptAgentsList
 Input       : 
 Output      : Dongguk :: IA01_InterruptAgentsList
 Method Type :	INFORMATION
 Code        : 0x1006
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN06_InterruptAgentsList_disconnected ();
virtual void on_IN06_InterruptAgentsList_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::IA01_InterruptAgentsList const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN07_TrafficPatternInfo
 Input       : 
 Output      : Dongguk :: SC04_TrafficPatternInfo
 Method Type :	INFORMATION
 Code        : 0x1007
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN07_TrafficPatternInfo_disconnected ();
virtual void on_IN07_TrafficPatternInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC04_TrafficPatternInfo const* const pin_buffer);

/********************************************************************************************************************************************
 Method      : IN08_TopographicEvent
 Input       : 
 Output      : Dongguk :: TE01_TopographicEvent
 Method Type :	INFORMATION
 Code        : 0x1008
 User_id     : root
 Description : 
*******************************************************************************************************************************************/
virtual void on_IN08_TopographicEvent_disconnected ();
virtual void on_IN08_TopographicEvent_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::TE01_TopographicEvent const* const pin_buffer);

};

#endif // #ifdef Define__Nerv__Method__proxy_coretec_scenario__proxy_coretec_scenario_h