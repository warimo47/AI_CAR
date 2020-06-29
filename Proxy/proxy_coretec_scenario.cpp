#include "proxy_coretec_scenario.h"

proxy_coretec_scenario::proxy_coretec_scenario()
{
}
proxy_coretec_scenario:: ~ proxy_coretec_scenario()
{
}
void proxy_coretec_scenario::on_object_create()
{
	this->get_override("on_object_create")();
}
void proxy_coretec_scenario::on_object_destroy()
{
	this->get_override("on_object_destroy")();
}

void proxy_coretec_scenario::on_CO00_MonitoringReady_disconnected()
{
	this->get_override("on_MonitoringReady_disconnected")();
}
void proxy_coretec_scenario::on_CO01_SpawnInfo_disconnected()
{
	this->get_override("on_SpawnInfo_disconnected")();
}
void proxy_coretec_scenario::on_CO02_ControlInfo_disconnected()
{
	this->get_override("on_ControlInfo_disconnected")();
}
void proxy_coretec_scenario::on_CO03_DeleteObjectInfo_disconnected()
{
	this->get_override("on_DeleteObjectInfo_disconnected")();
}
void proxy_coretec_scenario::on_CO04_StringInfo_disconnected()
{
	this->get_override("on_StringInfo_disconnected")();
}
void proxy_coretec_scenario::on_IN00_AllAgentsInformation_disconnected ()
{
	this->get_override("on_AllAgentsInformation_disconnected")();
}
void proxy_coretec_scenario::on_IN00_AllAgentsInformation_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::AA08_AllAgentsInformation const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_AllAgentsInformation_sync")(in_sync_model, in_elapsed, in_limit, pin_buffer);
}
void proxy_coretec_scenario::on_IN01_ScenarioSetting_disconnected ()
{
	this->get_override("on_ScenarioSetting_disconnected")();
}
void proxy_coretec_scenario::on_IN01_ScenarioSetting_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC00_ScenarioSetting const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_ScenarioSetting_sync")(in_sync_model, in_elapsed, in_limit, pin_buffer);
}
void proxy_coretec_scenario::on_IN02_CustomEventList_disconnected ()
{
	this->get_override("on_CustomEventList_disconnected")();
}
void proxy_coretec_scenario::on_IN02_CustomEventList_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::CE03_CustomEventList const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_CustomEventList_sync")(in_sync_model, in_elapsed, in_limit, pin_buffer);
}
void proxy_coretec_scenario::on_IN03_ScenarioSignalInfo_disconnected ()
{
	this->get_override("on_ScenarioSignalInfo_disconnected")();
}
void proxy_coretec_scenario::on_IN03_ScenarioSignalInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC01_ScenarioSignalInfo const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_ScenarioSignalInfo_sync")(in_sync_model, in_elapsed, in_limit, *pin_buffer);
}
void proxy_coretec_scenario::on_IN04_Tick_disconnected ()
{
	this->get_override("on_Tick_disconnected")();
}
void proxy_coretec_scenario::on_IN04_Tick_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC02_Tick const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_Tick_sync")(in_sync_model, in_elapsed, in_limit, *pin_buffer);
}
void proxy_coretec_scenario::on_IN05_CrashInfo_disconnected ()
{
	this->get_override("on_CrashInfo_disconnected")();
}
void proxy_coretec_scenario::on_IN05_CrashInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC03_CrashInfo const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_CrashInfo_sync")(in_sync_model, in_elapsed, in_limit, pin_buffer);
}
void proxy_coretec_scenario::on_IN06_InterruptAgentsList_disconnected ()
{
	this->get_override("on_InterruptAgentsList_disconnected")();
}
void proxy_coretec_scenario::on_IN06_InterruptAgentsList_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::IA01_InterruptAgentsList const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_InterruptAgentsList_sync")(in_sync_model, in_elapsed, in_limit, pin_buffer);
}
void proxy_coretec_scenario::on_IN07_TrafficPatternInfo_disconnected ()
{
	this->get_override("on_TrafficPatternInfo_disconnected")();
}
void proxy_coretec_scenario::on_IN07_TrafficPatternInfo_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::SC04_TrafficPatternInfo const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_TrafficPatternInfo_sync")(in_sync_model, in_elapsed, in_limit, *pin_buffer);
}
void proxy_coretec_scenario::on_IN08_TopographicEvent_disconnected ()
{
	this->get_override("on_TopographicEvent_disconnected")();
}
void proxy_coretec_scenario::on_IN08_TopographicEvent_sync(const sender_sync_model_t& in_sync_model, const double& in_elapsed, const double& in_limit,Nerv::Data::Dongguk::TE01_TopographicEvent const* const pin_buffer)
{
	if (pin_buffer) this->get_override("on_TopographicEvent_sync")(in_sync_model, in_elapsed, in_limit, *pin_buffer);
}
