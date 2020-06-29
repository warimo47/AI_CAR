
#pragma once

#include <boost/python.hpp>
namespace py = boost::python;

// proxy header

#include "Proxy/proxy_coretec_scenario.h"


void export_proxy_coretec_scenario()
{
	py::class_<proxy_coretec_scenario, boost::noncopyable>("proxy_coretec_scenario")
		.def("create", &proxy_coretec_scenario::create)

		.def("on_object_create", &proxy_coretec_scenario::on_object_create)
		.def("on_object_destroy", &proxy_coretec_scenario::on_object_destroy)

		// COMMAND MonitorningReady
		// connection methods
		.def("MonitoringReady_connect", &proxy_coretec_scenario::CO00_MonitoringReady_connect)
		.def("MonitoringReady_shutdown", &proxy_coretec_scenario::CO00_MonitoringReady_shutdown)
		.def("on_MonitoringReady_disconnected", &proxy_coretec_scenario::on_CO00_MonitoringReady_disconnected)
		// write
		.def("MonitoringReady_write", &proxy_coretec_scenario::CO00_MonitoringReady_write)
		// get / post / read
		.def("MonitoringReady_get", &proxy_coretec_scenario::CO00_MonitoringReady_get, py::return_value_policy <py::reference_existing_object>())
		.def("MonitoringReady_post", &proxy_coretec_scenario::CO00_MonitoringReady_post)
		.def("MonitoringReady_read", &proxy_coretec_scenario::CO00_MonitoringReady_read)

		// COMMAND SpawnInfo
		// connection methods
		.def("SpawnInfo_connect", &proxy_coretec_scenario::CO01_SpawnInfo_connect)
		.def("SpawnInfo_shutdown", &proxy_coretec_scenario::CO01_SpawnInfo_shutdown)
		.def("on_SpawnInfo_disconnected", &proxy_coretec_scenario::on_CO01_SpawnInfo_disconnected)
		// write
		.def("SpawnInfo_write", &proxy_coretec_scenario::CO01_SpawnInfo_write)
		// get / post / read
		.def("SpawnInfo_get", &proxy_coretec_scenario::CO01_SpawnInfo_get, py::return_value_policy <py::reference_existing_object>())
		.def("SpawnInfo_post", &proxy_coretec_scenario::CO01_SpawnInfo_post)
		.def("SpawnInfo_read", &proxy_coretec_scenario::CO01_SpawnInfo_read)

        // COMMAND ControlInfo
        // connection methods
        .def("ControlInfo_connect", &proxy_coretec_scenario::CO02_ControlInfo_connect)
        .def("ControlInfo_shutdown", &proxy_coretec_scenario::CO02_ControlInfo_shutdown)
        .def("on_ControlInfo_disconnected", &proxy_coretec_scenario::on_CO02_ControlInfo_disconnected)
        // write
        .def("ControlInfo_write", &proxy_coretec_scenario::CO02_ControlInfo_write)
        // get / post / read
        .def("ControlInfo_get", &proxy_coretec_scenario::CO02_ControlInfo_get, py::return_value_policy <py::reference_existing_object>())
        .def("ControlInfo_post", &proxy_coretec_scenario::CO02_ControlInfo_post)
        .def("ControlInfo_read", &proxy_coretec_scenario::CO02_ControlInfo_read)
        
        // COMMAND DeleteObjectInfo
        // connection methods
        .def("DeleteObjectInfo_connect", &proxy_coretec_scenario::CO03_DeleteObjectInfo_connect)
        .def("DeleteObjectInfo_shutdown", &proxy_coretec_scenario::CO03_DeleteObjectInfo_shutdown)
        .def("on_DeleteObjectInfo_disconnected", &proxy_coretec_scenario::on_CO03_DeleteObjectInfo_disconnected)
        // write
        .def("DeleteObjectInfo_write", &proxy_coretec_scenario::CO03_DeleteObjectInfo_write)
        // get / post / read
        .def("DeleteObjectInfo_get", &proxy_coretec_scenario::CO03_DeleteObjectInfo_get, py::return_value_policy <py::reference_existing_object>())
        .def("DeleteObjectInfo_post", &proxy_coretec_scenario::CO03_DeleteObjectInfo_post)
        .def("DeleteObjectInfo_read", &proxy_coretec_scenario::CO03_DeleteObjectInfo_read)

        // COMMAND StringInfo
        // connection methods
        .def("StringInfo_connect", &proxy_coretec_scenario::CO04_StringInfo_connect)
        .def("StringInfo_shutdown", &proxy_coretec_scenario::CO04_StringInfo_shutdown)
        .def("on_StringInfo_disconnected", &proxy_coretec_scenario::on_CO04_StringInfo_disconnected)
        // write
        .def("StringInfo_write", &proxy_coretec_scenario::CO04_StringInfo_write)
        // get / post / read
        .def("StringInfo_get", &proxy_coretec_scenario::CO04_StringInfo_get, py::return_value_policy <py::reference_existing_object>())
        .def("StringInfo_post", &proxy_coretec_scenario::CO04_StringInfo_post)
        .def("StringInfo_read", &proxy_coretec_scenario::CO04_StringInfo_read)

        // INFORMATION AllAgentsInformation
        // connection methods
        .def("AllAgentsInformation_connect", &proxy_coretec_scenario::IN00_AllAgentsInformation_connect)
        .def("AllAgentsInformation_shutdown", &proxy_coretec_scenario::IN00_AllAgentsInformation_shutdown)
        .def("on_AllAgentsInformation_disconnected", &proxy_coretec_scenario::on_IN00_AllAgentsInformation_disconnected)
        // on_sync / read
        .def("on_AllAgentsInformation_sync", &proxy_coretec_scenario::on_IN00_AllAgentsInformation_sync)
        .def("AllAgentsInformation_read", &proxy_coretec_scenario::IN00_AllAgentsInformation_read)

		// INFORMATION ScenarioSetting
	    // connection methods
		.def("ScenarioSetting_connect", &proxy_coretec_scenario::IN01_ScenarioSetting_connect)
		.def("ScenarioSetting_shutdown", &proxy_coretec_scenario::IN01_ScenarioSetting_shutdown)
		.def("on_ScenarioSetting_disconnected", &proxy_coretec_scenario::on_IN01_ScenarioSetting_disconnected)
		// on_sync / read
		.def("on_ScenarioSetting_sync", &proxy_coretec_scenario::on_IN01_ScenarioSetting_sync)
		.def("ScenarioSetting_read", &proxy_coretec_scenario::IN01_ScenarioSetting_read)

		// INFORMATION CustomEvenList
		// connection methods
		.def("CustomEventList_connect", &proxy_coretec_scenario::IN02_CustomEventList_connect)
		.def("CustomEventList_shutdown", &proxy_coretec_scenario::IN02_CustomEventList_shutdown)
		.def("on_CustomEventList_disconnected", &proxy_coretec_scenario::on_IN02_CustomEventList_disconnected)
		// on_sync / read
		.def("on_CustomEventList_sync", &proxy_coretec_scenario::on_IN02_CustomEventList_sync)
		.def("CustomEventList_read", &proxy_coretec_scenario::IN02_CustomEventList_read)

		// INFORMATION ScenarioSignalInfo
		// connection methods
		.def("ScenarioSignalInfo_connect", &proxy_coretec_scenario::IN03_ScenarioSignalInfo_connect)
		.def("ScenarioSignalInfo_shutdown", &proxy_coretec_scenario::IN03_ScenarioSignalInfo_shutdown)
		.def("on_ScenarioSignalInfo_disconnected", &proxy_coretec_scenario::on_IN03_ScenarioSignalInfo_disconnected)
		// on_sync / read
		.def("on_ScenarioSignalInfo_sync", &proxy_coretec_scenario::on_IN03_ScenarioSignalInfo_sync)
		.def("ScenarioSignalInfo_read", &proxy_coretec_scenario::IN03_ScenarioSignalInfo_read)

		// INFORMATION Tick
		// connection methods
		.def("Tick_connect", &proxy_coretec_scenario::IN04_Tick_connect)
		.def("Tick_shutdown", &proxy_coretec_scenario::IN04_Tick_shutdown)
		.def("on_Tick_disconnected", &proxy_coretec_scenario::on_IN04_Tick_disconnected)
		// on_sync / read
		.def("on_Tick_sync", &proxy_coretec_scenario::on_IN04_Tick_sync)
		.def("Tick_read", &proxy_coretec_scenario::IN04_Tick_read)

        // INFORMATION CrashInfo
        // connection methods
        .def("CrashInfo_connect", &proxy_coretec_scenario::IN05_CrashInfo_connect)
        .def("CrashInfo_shutdown", &proxy_coretec_scenario::IN05_CrashInfo_shutdown)
        .def("on_CrashInfo_disconnected", &proxy_coretec_scenario::on_IN05_CrashInfo_disconnected)
        // on_sync / read
        .def("on_CrashInfo_sync", &proxy_coretec_scenario::on_IN05_CrashInfo_sync)
        .def("CrashInfo_read", &proxy_coretec_scenario::IN05_CrashInfo_read)
        
        // INFORMATION InterruptAgentsList
        // connection methods
        .def("InterruptAgentsList_connect", &proxy_coretec_scenario::IN06_InterruptAgentsList_connect)
        .def("InterruptAgentsList_shutdown", &proxy_coretec_scenario::IN06_InterruptAgentsList_shutdown)
        .def("on_InterruptAgentsList_disconnected", &proxy_coretec_scenario::on_IN06_InterruptAgentsList_disconnected)
        // on_sync / read
        .def("on_InterruptAgentsList_sync", &proxy_coretec_scenario::on_IN06_InterruptAgentsList_sync)
        .def("InterruptAgentsList_read", &proxy_coretec_scenario::IN06_InterruptAgentsList_read)
        
        // INFORMATION TrafficPatternInfo
        // connection methods
        .def("TrafficPatternInfo_connect", &proxy_coretec_scenario::IN07_TrafficPatternInfo_connect)
        .def("TrafficPatternInfo_shutdown", &proxy_coretec_scenario::IN07_TrafficPatternInfo_shutdown)
        .def("on_TrafficPatternInfo_disconnected", &proxy_coretec_scenario::on_IN07_TrafficPatternInfo_disconnected)
        // on_sync / read
        .def("on_TrafficPatternInfo_sync", &proxy_coretec_scenario::on_IN07_TrafficPatternInfo_sync)
        .def("TrafficPatternInfo_read", &proxy_coretec_scenario::IN07_TrafficPatternInfo_read)
			
		// INFORMATION TopographicEvent
		// connection methods
		.def("TopographicEvent_connect", &proxy_coretec_scenario::IN08_TopographicEvent_connect)
		.def("TopographicEvent_shutdown", &proxy_coretec_scenario::IN08_TopographicEvent_shutdown)
		.def("on_TopographicEvent_disconnected", &proxy_coretec_scenario::on_IN08_TopographicEvent_disconnected)
		// on_sync / read
		.def("on_TopographicEvent_sync", &proxy_coretec_scenario::on_IN08_TopographicEvent_sync)
		.def("TopographicEvent_read", &proxy_coretec_scenario::IN08_TopographicEvent_read)

		;

}

