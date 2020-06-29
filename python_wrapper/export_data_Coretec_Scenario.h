
#pragma once

#include <boost/python.hpp>
namespace py = boost::python;

// array export helper
#include "python_wrapper/array_proxy.h"

// data header
    
#include "Nerv/Data/Dongguk/Dongguk.h"
    
#include "Nerv/Data/Coretec/Coretec.h"
    

// helper function
template <size_t N>
void set_str(::Nerv::char_t (&out_dest)[N], const ::Nerv::char_t* pin_val)
{
    // overflow check
    if (N > strlen(pin_val))
    {
        memset(out_dest, 0, N);
        strcpy_s(out_dest, pin_val);
    }
}

#define ADD_PROPERTY(TYPE, ATTR) add_property(#ATTR, GET_CHAR_P(TYPE, ATTR), SET_CHAR_P(TYPE, ATTR))
#define GET_CHAR_P(TYPE, ATTR) +[](const TYPE& self){ return self.ATTR;}
#define SET_CHAR_P(TYPE, ATTR) +[](TYPE& self, const ::Nerv::char_t* pin_val){set_str(self.ATTR, pin_val);}

/*
const ::Nerv::char_t* get_DeactiveEventList(AI01_DeactiveEventInfo& self, const int in_index)
{
	return self.DeactiveEventList[in_index];
}

void set_DeactiveEventList(AI01_DeactiveEventInfo& self, const int in_index, const ::Nerv::char_t* pin_val)
{
	set_str(self.DeactiveEventList[in_index], pin_val);
}
*/

// 구조체 배열을 사용하기 위한 operator == 정의
// xslt로 구조체 배열로 참조당하는 구조체를 선별해서 단 한번만 operator == 를 정의하기에 어려움이 있음
// 우선 모든 구조체의 operator == () 를 구현하도록 함..
// xslt 에서 런타임에 값을 저장/참조할 수 있는 방법 찾으면 다시 수정할 예정 (javascript)
namespace Nerv { namespace Data { namespace Dongguk {

    bool operator == (const AA00_AnimationInfo& lhs, const AA00_AnimationInfo& rhs)
    {
        return 
            lhs.AnimationID == rhs.AnimationID &&
            lhs.PartID == rhs.PartID &&
            lhs.AnimationPlayWidth == rhs.AnimationPlayWidth &&
            lhs.AnimationPlaySpeed == rhs.AnimationPlaySpeed &&
            lhs.AnimationLoop == rhs.AnimationLoop;
    }

	bool operator == (const AA01_AutomaticCarStatus& lhs, const AA01_AutomaticCarStatus& rhs)
	{
		return
			std::equal(std::begin(lhs.Position), std::end(lhs.Position), std::begin(rhs.Position)) &&
			std::equal(std::begin(lhs.ForwardVector), std::end(lhs.ForwardVector), std::begin(rhs.ForwardVector)) &&
			lhs.dVelocity == rhs.dVelocity;
	}

	bool operator == (const AA02_HumanStatus& lhs, const AA02_HumanStatus& rhs)
	{
		return
			std::equal(std::begin(lhs.NpcHumanID), std::end(lhs.NpcHumanID), std::begin(rhs.NpcHumanID)) &&
			lhs.NpcHumanType == rhs.NpcHumanType &&
			std::equal(std::begin(lhs.NpcHumanLocation), std::end(lhs.NpcHumanLocation), std::begin(rhs.NpcHumanLocation)) &&
			std::equal(std::begin(lhs.NpcHumanRotation), std::end(lhs.NpcHumanRotation), std::begin(rhs.NpcHumanRotation)) &&
			std::equal(std::begin(lhs.NpcHumanColliderSize), std::end(lhs.NpcHumanColliderSize), std::begin(rhs.NpcHumanColliderSize)) &&
			lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
			std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
			lhs.Speed == rhs.Speed;
	}

	bool operator == (const AA03_AnimalStatus& lhs, const AA03_AnimalStatus& rhs)
	{
		return
			std::equal(std::begin(lhs.NpcAnimalID), std::end(lhs.NpcAnimalID), std::begin(rhs.NpcAnimalID)) &&
			lhs.NpcAnimalType == rhs.NpcAnimalType &&
			std::equal(std::begin(lhs.NpcAnimalLocation), std::end(lhs.NpcAnimalLocation), std::begin(rhs.NpcAnimalLocation)) &&
			std::equal(std::begin(lhs.NpcAnimalRotation), std::end(lhs.NpcAnimalRotation), std::begin(rhs.NpcAnimalRotation)) &&
			std::equal(std::begin(lhs.NpcAnimalColliderSize), std::end(lhs.NpcAnimalColliderSize), std::begin(rhs.NpcAnimalColliderSize)) &&
			lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
			std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
			lhs.Speed == rhs.Speed;
	}

	bool operator == (const AA04_VehicleStatus& lhs, const AA04_VehicleStatus& rhs)
	{
		return
			std::equal(std::begin(lhs.NpcCarID), std::end(lhs.NpcCarID), std::begin(rhs.NpcCarID)) &&
			lhs.NpcCarType == rhs.NpcCarType &&
			std::equal(std::begin(lhs.NpcCarLocation), std::end(lhs.NpcCarLocation), std::begin(rhs.NpcCarLocation)) &&
			std::equal(std::begin(lhs.NpcCarRotation), std::end(lhs.NpcCarRotation), std::begin(rhs.NpcCarRotation)) &&
			std::equal(std::begin(lhs.NpcCarColliderSize), std::end(lhs.NpcCarColliderSize), std::begin(rhs.NpcCarColliderSize)) &&
			lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
			std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
			lhs.Speed == rhs.Speed;
	}

	bool operator == (const AA07_WeatherStatus& lhs, const AA07_WeatherStatus& rhs)
	{
		return
			lhs.IsWeatherRandom == rhs.IsWeatherRandom &&
			lhs.SeasonID == rhs.SeasonID &&
			lhs.WeatherID == rhs.WeatherID &&
			lhs.FogDensity == rhs.FogDensity &&
			lhs.CloudDensity == rhs.CloudDensity &&
			lhs.Precipitation == rhs.Precipitation;
	}

	bool operator == (const AA08_AllAgentsInformation& lhs, const AA08_AllAgentsInformation& rhs)
	{
		return
			// lhs.timestamp == rhs.timestamp &&
			lhs.AutomaticCarStatusMemory == rhs.AutomaticCarStatusMemory &&
			std::equal(std::begin(lhs.HumanStatusMemory), std::end(lhs.HumanStatusMemory), std::begin(rhs.HumanStatusMemory)) &&
			std::equal(std::begin(lhs.AnimalStatusMemory), std::end(lhs.AnimalStatusMemory), std::begin(rhs.AnimalStatusMemory)) &&
			std::equal(std::begin(lhs.VehicleStatusMemory), std::end(lhs.VehicleStatusMemory), std::begin(rhs.VehicleStatusMemory)) &&
			lhs.Hour == rhs.Hour &&
			lhs.WeatherStatusMemory == rhs.WeatherStatusMemory;
	}
    
	bool operator == (const CE00_Action& lhs, const CE00_Action& rhs)
    {
        return 
            lhs.Animation == rhs.Animation &&
			std::equal(std::begin(lhs.Destination), std::end(lhs.Destination), std::begin(rhs.Destination)) &&
			lhs.Time == rhs.Time;
    }
    
    bool operator == (const CE01_Subject& lhs, const CE01_Subject& rhs)
    {
		return
			lhs.Type == rhs.Type &&
			lhs.Mesh == rhs.Mesh &&
			std::equal(std::begin(lhs.StartPosition), std::end(lhs.StartPosition), std::begin(rhs.StartPosition)) &&
			lhs.ActionNum == rhs.ActionNum &&
			std::equal(std::begin(lhs.ActionArray), std::end(lhs.ActionArray), std::begin(rhs.ActionArray));
    }
    
    bool operator == (const CE02_CustomEvent& lhs, const CE02_CustomEvent& rhs)
    {
		return
			std::equal(std::begin(lhs.ID), std::end(lhs.ID), std::begin(rhs.ID)) &&
			std::equal(std::begin(lhs.Position), std::end(lhs.Position), std::begin(rhs.Position)) &&
			lhs.State == rhs.State &&
			lhs.StartDistance == rhs.StartDistance &&
			lhs.SubjectsNum == rhs.SubjectsNum &&
			std::equal(std::begin(lhs.SubjectsArray), std::end(lhs.SubjectsArray), std::begin(rhs.SubjectsArray));
    }
    
    bool operator == (const IA00_InterruptAgent& lhs, const IA00_InterruptAgent& rhs)
    {
		return
			std::equal(std::begin(lhs.ID), std::end(lhs.ID), std::begin(rhs.ID)) &&
			lhs.DeletionStatus == rhs.DeletionStatus &&
			std::equal(std::begin(lhs.Location), std::end(lhs.Location), std::begin(rhs.Location)) &&
			lhs.Mesh == rhs.Mesh &&
			lhs.Animation == rhs.Animation &&
			std::equal(std::begin(lhs.Destination), std::end(lhs.Destination), std::begin(rhs.Destination)) &&
			lhs.Time == rhs.Time;
    }

	bool operator == (const SC00_ScenarioSetting& lhs, const SC00_ScenarioSetting& rhs)
	{
		return
			lhs.FPS == rhs.FPS &&
			lhs.CAR_NUM == rhs.CAR_NUM &&
			lhs.HUMAN_NUM == rhs.HUMAN_NUM &&
			lhs.ANIMAL_NUM == rhs.ANIMAL_NUM &&
			lhs.MapType == rhs.MapType &&
			lhs.ObjectControlMode == rhs.ObjectControlMode &&
			lhs.HumanLayer == rhs.HumanLayer &&
			lhs.AnimalLayer == rhs.AnimalLayer &&
			lhs.VehicleLayer == rhs.VehicleLayer &&
			lhs.TrafficLightLayer == rhs.TrafficLightLayer &&
			lhs.WeatherLayer == rhs.WeatherLayer &&
			lhs.IsNew == rhs.IsNew &&
			std::equal(std::begin(lhs.HumanTypes), std::end(lhs.HumanTypes), std::begin(rhs.HumanTypes)) &&
			std::equal(std::begin(lhs.AnimalTypes), std::end(lhs.AnimalTypes), std::begin(rhs.AnimalTypes)) &&
			std::equal(std::begin(lhs.CarTypes), std::end(lhs.CarTypes), std::begin(rhs.CarTypes));
	}

	/*
	bool operator == (const SC01_ScenarioSignalInfo& lhs, const SC01_ScenarioSignalInfo& rhs)
	{
		return
			lhs == rhs;
	}
	*/

	/*
	bool operator == (const SC02_Tick& lhs, const SC02_Tick& rhs)
	{
		return
			lhs == rhs;
	}
	*/

	bool operator == (const SC03_CrashInfo& lhs, const SC03_CrashInfo& rhs)
	{
		return
			std::equal(std::begin(lhs.Location), std::end(lhs.Location), std::begin(rhs.Location)) &&
			lhs.Impulse == rhs.Impulse &&
			std::equal(std::begin(lhs.CauseObjectID), std::end(lhs.CauseObjectID), std::begin(rhs.CauseObjectID)) &&
			std::equal(std::begin(lhs.CausedObjectID), std::end(lhs.CausedObjectID), std::begin(rhs.CausedObjectID)) &&
			std::equal(std::begin(lhs.CauseObjectDamagedPartList), std::end(lhs.CauseObjectDamagedPartList), std::begin(rhs.CauseObjectDamagedPartList)) &&
			std::equal(std::begin(lhs.CausedObjectDamagedPartList), std::end(lhs.CausedObjectDamagedPartList), std::begin(rhs.CausedObjectDamagedPartList));
	}

	/*
	bool operator == (const SC04_TrafficPatternInfo& lhs, const SC04_TrafficPatternInfo& rhs)
	{
		return
			lhs == rhs;
	}
	*/

	bool operator == (const TE00_Box& lhs, const TE00_Box& rhs)
	{
		return
			lhs.Type == rhs.Type &&
			std::equal(std::begin(lhs.location), std::end(lhs.location), std::begin(rhs.location)) &&
			std::equal(std::begin(lhs.rotation), std::end(lhs.rotation), std::begin(rhs.rotation)) &&
			std::equal(std::begin(lhs.extent), std::end(lhs.extent), std::begin(rhs.extent));
	}

	/*
	bool operator == (const TE01_TopographicEvent& lhs, const TE01_TopographicEvent& rhs)
	{
		return
			lhs == rhs;
	}
	*/

    
} } }    

// data export function for boost_python
void export_data_Dongguk()
{
    py::class_<AA00_AnimationInfo>("AnimationInfo")
        .def_readwrite("AnimationID", &AA00_AnimationInfo::AnimationID)
        .def_readwrite("PartID", &AA00_AnimationInfo::PartID)
        .def_readwrite("AnimationPlayWidth", &AA00_AnimationInfo::AnimationPlayWidth)
        .def_readwrite("AnimationPlaySpeed", &AA00_AnimationInfo::AnimationPlaySpeed)
        .def_readwrite("AnimationLoop", &AA00_AnimationInfo::AnimationLoop)
    ;

	py::class_<AA01_AutomaticCarStatus>("AutomaticCarStatus")
		.add_property("Position", make_array(&AA01_AutomaticCarStatus::Position))
		.add_property("ForwardVector", make_array(&AA01_AutomaticCarStatus::ForwardVector))
		.def_readwrite("dVelocity", &AA01_AutomaticCarStatus::dVelocity)
	;

	py::class_<AA02_HumanStatus>("HumanStatus")
		.ADD_PROPERTY(AA02_HumanStatus, NpcHumanID)
		.def_readwrite("NpcHumanType", &AA02_HumanStatus::NpcHumanType)
		.add_property("NpcHumanLocation", make_array(&AA02_HumanStatus::NpcHumanLocation))
		.add_property("NpcHumanRotation", make_array(&AA02_HumanStatus::NpcHumanRotation))
		.add_property("NpcHumanColliderSize", make_array(&AA02_HumanStatus::NpcHumanColliderSize))
		.add_property("AnimationInfo", make_array(&AA02_HumanStatus::AnimationInfo))
		.def_readwrite("AnimationInfoSize", &AA02_HumanStatus::AnimationInfoSize)
		.def_readwrite("Speed", &AA02_HumanStatus::Speed)
	;

	py::class_<AA03_AnimalStatus>("AnimalStatus")
		.ADD_PROPERTY(AA03_AnimalStatus, NpcAnimalID)
		.def_readwrite("NpcAnimalType", &AA03_AnimalStatus::NpcAnimalType)
		.add_property("NpcAnimalLocation", make_array(&AA03_AnimalStatus::NpcAnimalLocation))
		.add_property("NpcAnimalRotation", make_array(&AA03_AnimalStatus::NpcAnimalRotation))
		.add_property("NpcAnimalColliderSize", make_array(&AA03_AnimalStatus::NpcAnimalColliderSize))
		.def_readwrite("AnimationInfoSize", &AA03_AnimalStatus::AnimationInfoSize)
		.add_property("AnimationInfo", make_array(&AA03_AnimalStatus::AnimationInfo))
		.def_readwrite("Speed", &AA03_AnimalStatus::Speed)
	;

	py::class_<AA04_VehicleStatus>("VehicleStatus")
		.ADD_PROPERTY(AA04_VehicleStatus, NpcCarID)
		.def_readwrite("NpcCarType", &AA04_VehicleStatus::NpcCarType)
		.add_property("NpcCarLocation", make_array(&AA04_VehicleStatus::NpcCarLocation))
		.add_property("NpcCarRotation", make_array(&AA04_VehicleStatus::NpcCarRotation))
		.add_property("NpcCarColliderSize", make_array(&AA04_VehicleStatus::NpcCarColliderSize))
		.def_readwrite("AnimationInfoSize", &AA04_VehicleStatus::AnimationInfoSize)
		.add_property("AnimationInfo", make_array(&AA04_VehicleStatus::AnimationInfo))
		.def_readwrite("Speed", &AA04_VehicleStatus::Speed)
	;

	py::class_<AA07_WeatherStatus>("WeatherStatus")
		.def_readwrite("IsWeatherRandom", &AA07_WeatherStatus::IsWeatherRandom)
		.def_readwrite("SeasonID", &AA07_WeatherStatus::SeasonID)
		.def_readwrite("WeatherID", &AA07_WeatherStatus::WeatherID)
		.def_readwrite("FogDensity", &AA07_WeatherStatus::FogDensity)
		.def_readwrite("CloudDensity", &AA07_WeatherStatus::CloudDensity)
		.def_readwrite("Precipitation", &AA07_WeatherStatus::Precipitation)
	;

	py::class_<AA08_AllAgentsInformation>("AllAgentsInformation")
		.def_readwrite("AutomaticCarStatusMemory", &AA08_AllAgentsInformation::AutomaticCarStatusMemory)
		.add_property("HumanStatusMemory", make_array(&AA08_AllAgentsInformation::HumanStatusMemory))
		.add_property("AnimalStatusMemory", make_array(&AA08_AllAgentsInformation::AnimalStatusMemory))
		.add_property("VehicleStatusMemory", make_array(&AA08_AllAgentsInformation::VehicleStatusMemory))
		.def_readwrite("Hour", &AA08_AllAgentsInformation::Hour)
		.def_readwrite("WeatherStatusMemory", &AA08_AllAgentsInformation::WeatherStatusMemory)
	;
      
    py::class_<CE00_Action>("Action")
        .def_readwrite("Animation", &CE00_Action::Animation)
		.add_property("Destination", make_array(&CE00_Action::Destination))
        .def_readwrite("Time", &CE00_Action::Time)
    ;        
      
    py::class_<CE01_Subject>("Subject")
		.def_readwrite("Type", &CE01_Subject::Type)
        .def_readwrite("Mesh", &CE01_Subject::Mesh)
		.add_property("StartPosition", make_array(&CE01_Subject::StartPosition))
		.def_readwrite("ActionNum", &CE01_Subject::ActionNum)
		.add_property("ActionArray", make_array(&CE01_Subject::ActionArray))
    ;
      
    py::class_<CE02_CustomEvent>("CustomEvent")
        .ADD_PROPERTY(CE02_CustomEvent, ID)
		.add_property("Position", make_array(&CE02_CustomEvent::Position))
        .def_readwrite("State", &CE02_CustomEvent::State)
        .def_readwrite("StartDistance", &CE02_CustomEvent::StartDistance)
		.def_readwrite("SubjectsNum", &CE02_CustomEvent::SubjectsNum)
		.add_property("SubjectsArray", make_array(&CE02_CustomEvent::SubjectsArray))
    ;

	py::class_<CE03_CustomEventList>("CustomEventList")
		.def("init_dynamic_buffer", &CE03_CustomEventList::init_daynamic_buffer)

		.def("List_alloc", &CE03_CustomEventList::List_alloc)
		.def("List_size", &CE03_CustomEventList::List_size)
		.def<CE02_CustomEvent* (CE03_CustomEventList::*)(const int)>("List", &CE03_CustomEventList::List,
			py::return_value_policy<py::reference_existing_object>())
	;

	py::class_<IA00_InterruptAgent>("InterruptAgent")
		.ADD_PROPERTY(IA00_InterruptAgent, ID)
		.def_readwrite("DeletionStatus", &IA00_InterruptAgent::DeletionStatus)
		.add_property("Location", make_array(&IA00_InterruptAgent::Location))
		.def_readwrite("Mesh", &IA00_InterruptAgent::Mesh)
		.def_readwrite("Animation", &IA00_InterruptAgent::Animation)
		.add_property("Destination", make_array(&IA00_InterruptAgent::Destination))
		.def_readwrite("Time", &IA00_InterruptAgent::Time)
	;

	py::class_<IA01_InterruptAgentsList>("InterruptAgentsList")
		.def("init_dynamic_buffer", &IA01_InterruptAgentsList::init_daynamic_buffer)

		.def("List_alloc", &IA01_InterruptAgentsList::List_alloc)
		.def("List_size", &IA01_InterruptAgentsList::List_size)
		.def<IA00_InterruptAgent* (IA01_InterruptAgentsList::*)(const int)>("List", &IA01_InterruptAgentsList::List,
			py::return_value_policy<py::reference_existing_object>())
	;

	py::class_<SC00_ScenarioSetting>("ScenarioSetting")
		.def_readwrite("FPS", &SC00_ScenarioSetting::FPS)
		.def_readwrite("CAR_NUM", &SC00_ScenarioSetting::CAR_NUM)
		.def_readwrite("HUMAN_NUM", &SC00_ScenarioSetting::HUMAN_NUM)
		.def_readwrite("ANIMAL_NUM", &SC00_ScenarioSetting::ANIMAL_NUM)
		.def_readwrite("MapType", &SC00_ScenarioSetting::MapType)
		.def_readwrite("ObjectControlMode", &SC00_ScenarioSetting::ObjectControlMode)
		.def_readwrite("HumanLayer", &SC00_ScenarioSetting::HumanLayer)
		.def_readwrite("AnimalLayer", &SC00_ScenarioSetting::AnimalLayer)
		.def_readwrite("VehicleLayer", &SC00_ScenarioSetting::VehicleLayer)
		.def_readwrite("TrafficLightLayer", &SC00_ScenarioSetting::TrafficLightLayer)
		.def_readwrite("WeatherLayer", &SC00_ScenarioSetting::WeatherLayer)
		.def_readwrite("IsNew", &SC00_ScenarioSetting::IsNew)
		.add_property("HumanTypes", make_array(&SC00_ScenarioSetting::HumanTypes))
		.add_property("AnimalTypes", make_array(&SC00_ScenarioSetting::AnimalTypes))
		.add_property("CarTypes", make_array(&SC00_ScenarioSetting::CarTypes))
	;       

    py::class_<SC03_CrashInfo>("CrashInfo")
        .add_property("Location", make_array(&SC03_CrashInfo::Location))
        .def_readwrite("Impulse", &SC03_CrashInfo::Impulse)
        .ADD_PROPERTY(SC03_CrashInfo,CauseObjectID)
        .ADD_PROPERTY(SC03_CrashInfo,CausedObjectID)
        .add_property("CauseObjectDamagedPartList", make_array(&SC03_CrashInfo::CauseObjectDamagedPartList))
        .add_property("CausedObjectDamagedPartList", make_array(&SC03_CrashInfo::CausedObjectDamagedPartList))
    ;

	py::class_<TE00_Box>("Box")
		.def_readwrite("Type", &TE00_Box::Type)
		.add_property("location", make_array(&TE00_Box::location))
		.add_property("rotation", make_array(&TE00_Box::rotation))
		.add_property("extent", make_array(&TE00_Box::extent))
		;

	py::class_<TE01_TopographicEvent>("TopographicEvent")
		.def("init_dynamic_buffer", &TE01_TopographicEvent::init_daynamic_buffer)

		.def("Boxes_alloc", &TE01_TopographicEvent::Boxes_alloc)
		.def("Boxes_size", &TE01_TopographicEvent::Boxes_size)
		.def<TE00_Box* (TE01_TopographicEvent::*)(const int)>("Boxes", &TE01_TopographicEvent::Boxes,
			py::return_value_policy<py::reference_existing_object>())
		;

}



// 구조체 배열을 사용하기 위한 operator == 정의
// xslt로 구조체 배열로 참조당하는 구조체를 선별해서 단 한번만 operator == 를 정의하기에 어려움이 있음
// 우선 모든 구조체의 operator == () 를 구현하도록 함..
// xslt 에서 런타임에 값을 저장/참조할 수 있는 방법 찾으면 다시 수정할 예정 (javascript)
namespace Nerv { namespace Data { namespace Coretec {
    
    bool operator == (const AI00_MonitoringReady& lhs, const AI00_MonitoringReady& rhs)
    {
        return
            lhs.Ready == rhs.Ready;
    }
    
	bool operator == (const AI01_AnimationInfo& lhs, const AI01_AnimationInfo& rhs)
	{
		return
			lhs.AnimationID == rhs.AnimationID &&
			lhs.PartID == rhs.PartID &&
			lhs.AnimationPlayWidth == rhs.AnimationPlayWidth &&
			lhs.AnimationPlaySpeed == rhs.AnimationPlaySpeed &&
			lhs.AnimationLoop == rhs.AnimationLoop;
	}
    
    bool operator == (const AI02_HumanSpawnInfo& lhs, const AI02_HumanSpawnInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.HumanID), std::end(lhs.HumanID), std::begin(rhs.HumanID)) &&
            lhs.ResourceType == rhs.ResourceType &&
            std::equal(std::begin(lhs.Location), std::end(lhs.Location), std::begin(rhs.Location)) &&
            std::equal(std::begin(lhs.Rotation), std::end(lhs.Rotation), std::begin(rhs.Rotation)) &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo));
    }
    
    bool operator == (const AI03_AnimalSpawnInfo& lhs, const AI03_AnimalSpawnInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.AnimalID), std::end(lhs.AnimalID), std::begin(rhs.AnimalID)) &&
            lhs.ResourceType == rhs.ResourceType &&
            std::equal(std::begin(lhs.Location), std::end(lhs.Location), std::begin(rhs.Location)) &&
            std::equal(std::begin(lhs.Rotation), std::end(lhs.Rotation), std::begin(rhs.Rotation)) &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo));
    }
    
    bool operator == (const AI04_VehicleSpawnInfo& lhs, const AI04_VehicleSpawnInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.VehicleID), std::end(lhs.VehicleID), std::begin(rhs.VehicleID)) &&
            lhs.ResourceType == rhs.ResourceType &&
            std::equal(std::begin(lhs.Location), std::end(lhs.Location), std::begin(rhs.Location)) &&
            std::equal(std::begin(lhs.Rotation), std::end(lhs.Rotation), std::begin(rhs.Rotation)) &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo));
    }
    
	/*
    bool operator == (const AI06_SpawnInfo& lhs, const AI06_SpawnInfo& rhs)
    {
        return 
            // TODO : variable buffer
            lhs.human_spawn == rhs.human_spawn&&
            // TODO : variable buffer
            lhs.animal_spawn == rhs.animal_spawn&&
            // TODO : variable buffer
            lhs.vehicle_spawn == rhs.vehicle_spawn&&
            // TODO : variable buffer
            lhs.envobj_spawn == rhs.envobj_spawn;
    }
	*/
    
    bool operator == (const AI07_HumanControlInfo& lhs, const AI07_HumanControlInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.HumanID), std::end(lhs.HumanID), std::begin(rhs.HumanID)) &&
            lhs.ActionType == rhs.ActionType &&
            lhs.isPhysicalEffect == rhs.isPhysicalEffect &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
            std::equal(std::begin(lhs.Rotation), std::end(lhs.Rotation), std::begin(rhs.Rotation)) &&
            lhs.Speed == rhs.Speed;
    }
    
    bool operator == (const AI08_AnimalControlInfo& lhs, const AI08_AnimalControlInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.AnimalID), std::end(lhs.AnimalID), std::begin(rhs.AnimalID)) &&
            lhs.ActionType == rhs.ActionType &&
            lhs.isPhysicalEffect == rhs.isPhysicalEffect &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
            std::equal(std::begin(lhs.Rotation), std::end(lhs.Rotation), std::begin(rhs.Rotation)) &&
            lhs.Speed == rhs.Speed;
    }
    
    bool operator == (const AI09_VehicleControlInfo& lhs, const AI09_VehicleControlInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.VehicleID), std::end(lhs.VehicleID), std::begin(rhs.VehicleID)) &&
            lhs.ActionType == rhs.ActionType &&
            lhs.isPhysicalEffect == rhs.isPhysicalEffect &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            lhs.Speed == rhs.Speed;
    }
    
    bool operator == (const AI10_TrafficLightControlInfo& lhs, const AI10_TrafficLightControlInfo& rhs)
    {
        return 
            lhs.TrafficLightID == rhs.TrafficLightID &&
            lhs.TrafficLightState == rhs.TrafficLightState &&
            lhs.ActionType == rhs.ActionType &&
            lhs.isPhysicalEffect == rhs.isPhysicalEffect &&
            lhs.AnimationInfoSize == rhs.AnimationInfoSize &&
            std::equal(std::begin(lhs.AnimationInfo), std::end(lhs.AnimationInfo), std::begin(rhs.AnimationInfo)) &&
            lhs.TrafficLightTimer == rhs.TrafficLightTimer;
    }

    //bool operator == (const AI12_ControlInfo& lhs, const AI12_ControlInfo& rhs)
    //{
    //    return 
    //        // TODO : variable buffer
    //        lhs.human_objects == rhs.human_objects&&
    //        // TODO : variable buffer
    //        lhs.animal_objects == rhs.animal_objects&&
    //        // TODO : variable buffer
    //        lhs.vehicle_objects == rhs.vehicle_objects&&
    //        // TODO : variable buffer
    //        lhs.traffic_light_objects == rhs.traffic_light_objects&&
    //        // TODO : variable buffer
    //        lhs.envobj_objects == rhs.envobj_objects;
    //        
    //}
    
    bool operator == (const AI13_DeleteObject& lhs, const AI13_DeleteObject& rhs)
    {
        return 
            std::equal(std::begin(lhs.DeleteObjectID), std::end(lhs.DeleteObjectID), std::begin(rhs.DeleteObjectID)) &&
            lhs.DeleteObjectType == rhs.DeleteObjectType;
    }

	/*
	bool operator == (const AI14_DeleteObjectInfo& lhs, const AI14_DeleteObjectInfo& rhs)
	{
		return 
			// TODO : variable buffer
			lhs.DeleteObjectArray == rhs.DeleteObjectArray;
	}
	*/
    
    bool operator == (const AI15_StringInfo& lhs, const AI15_StringInfo& rhs)
    {
        return 
            std::equal(std::begin(lhs.data), std::end(lhs.data), std::begin(rhs.data));
    }
    
} } }    

// data export function for boost_python
void export_data_Coretec()
{
	py::class_<AI00_MonitoringReady>("MonitoringReady")
		.def_readwrite("Ready", &AI00_MonitoringReady::Ready)
	;

    py::class_<AI01_AnimationInfo>("AnimationInfo")
        .def_readwrite("AnimationID", &AI01_AnimationInfo::AnimationID)
        .def_readwrite("PartID", &AI01_AnimationInfo::PartID)
        .def_readwrite("AnimationPlayWidth", &AI01_AnimationInfo::AnimationPlayWidth)
        .def_readwrite("AnimationPlaySpeed", &AI01_AnimationInfo::AnimationPlaySpeed)
        .def_readwrite("AnimationLoop", &AI01_AnimationInfo::AnimationLoop)
    ;              
      
    py::class_<AI02_HumanSpawnInfo>("HumanSpawnInfo")
        .ADD_PROPERTY(AI02_HumanSpawnInfo,HumanID)
        .def_readwrite("ResourceType", &AI02_HumanSpawnInfo::ResourceType)
        .add_property("Location", make_array(&AI02_HumanSpawnInfo::Location))
        .add_property("Rotation", make_array(&AI02_HumanSpawnInfo::Rotation))
        .def_readwrite("AnimationInfoSize", &AI02_HumanSpawnInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI02_HumanSpawnInfo::AnimationInfo))
    ;        
      
    py::class_<AI03_AnimalSpawnInfo>("AnimalSpawnInfo")
        .ADD_PROPERTY(AI03_AnimalSpawnInfo,AnimalID)
        .def_readwrite("ResourceType", &AI03_AnimalSpawnInfo::ResourceType)
        .add_property("Location", make_array(&AI03_AnimalSpawnInfo::Location))
        .add_property("Rotation", make_array(&AI03_AnimalSpawnInfo::Rotation))
        .def_readwrite("AnimationInfoSize", &AI03_AnimalSpawnInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI03_AnimalSpawnInfo::AnimationInfo))
    ;        
      
    py::class_<AI04_VehicleSpawnInfo>("VehicleSpawnInfo")
        .ADD_PROPERTY(AI04_VehicleSpawnInfo,VehicleID)
        .def_readwrite("ResourceType", &AI04_VehicleSpawnInfo::ResourceType)
        .add_property("Location", make_array(&AI04_VehicleSpawnInfo::Location))
        .add_property("Rotation", make_array(&AI04_VehicleSpawnInfo::Rotation))
        .def_readwrite("AnimationInfoSize", &AI04_VehicleSpawnInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI04_VehicleSpawnInfo::AnimationInfo))
    ;
      
    py::class_<AI06_SpawnInfo>("SpawnInfo")
        .def("init_dynamic_buffer", &AI06_SpawnInfo::init_daynamic_buffer)
    
        .def("human_spawn_alloc", &AI06_SpawnInfo::human_spawn_alloc)
        .def("human_spawn_size", &AI06_SpawnInfo::human_spawn_size)
        .def<AI02_HumanSpawnInfo* (AI06_SpawnInfo::*)(const int)>("human_spawn", &AI06_SpawnInfo::human_spawn,
             py::return_value_policy<py::reference_existing_object>())
        .def("animal_spawn_alloc", &AI06_SpawnInfo::animal_spawn_alloc)
        .def("animal_spawn_size", &AI06_SpawnInfo::animal_spawn_size)
        .def<AI03_AnimalSpawnInfo* (AI06_SpawnInfo::*)(const int)>("animal_spawn", &AI06_SpawnInfo::animal_spawn,
             py::return_value_policy<py::reference_existing_object>())
        .def("vehicle_spawn_alloc", &AI06_SpawnInfo::vehicle_spawn_alloc)
        .def("vehicle_spawn_size", &AI06_SpawnInfo::vehicle_spawn_size)
        .def<AI04_VehicleSpawnInfo* (AI06_SpawnInfo::*)(const int)>("vehicle_spawn", &AI06_SpawnInfo::vehicle_spawn,
             py::return_value_policy<py::reference_existing_object>())
    ;        
      
    py::class_<AI07_HumanControlInfo>("HumanControlInfo")
        .ADD_PROPERTY(AI07_HumanControlInfo,HumanID)
        .def_readwrite("ActionType", &AI07_HumanControlInfo::ActionType)
        .def_readwrite("isPhysicalEffect", &AI07_HumanControlInfo::isPhysicalEffect)
        .def_readwrite("AnimationInfoSize", &AI07_HumanControlInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI07_HumanControlInfo::AnimationInfo))
        .add_property("Rotation", make_array(&AI07_HumanControlInfo::Rotation))
        .def_readwrite("Speed", &AI07_HumanControlInfo::Speed)
    ;        
      
    py::class_<AI08_AnimalControlInfo>("AnimalControlInfo")
        .ADD_PROPERTY(AI08_AnimalControlInfo,AnimalID)
        .def_readwrite("ActionType", &AI08_AnimalControlInfo::ActionType)
        .def_readwrite("isPhysicalEffect", &AI08_AnimalControlInfo::isPhysicalEffect)
        .def_readwrite("AnimationInfoSize", &AI08_AnimalControlInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI08_AnimalControlInfo::AnimationInfo))
        .add_property("Rotation", make_array(&AI08_AnimalControlInfo::Rotation))
        .def_readwrite("Speed", &AI08_AnimalControlInfo::Speed)
    ;        
      
    py::class_<AI09_VehicleControlInfo>("VehicleControlInfo")
        .ADD_PROPERTY(AI09_VehicleControlInfo,VehicleID)
        .def_readwrite("ActionType", &AI09_VehicleControlInfo::ActionType)
        .def_readwrite("isPhysicalEffect", &AI09_VehicleControlInfo::isPhysicalEffect)
        .def_readwrite("AnimationInfoSize", &AI09_VehicleControlInfo::AnimationInfoSize)
		.add_property("AnimationInfo", make_array(&AI09_VehicleControlInfo::AnimationInfo))
		.add_property("Rotation", make_array(&AI09_VehicleControlInfo::Rotation))
        .def_readwrite("Speed", &AI09_VehicleControlInfo::Speed)
    ;        
      
    py::class_<AI10_TrafficLightControlInfo>("TrafficLightControlInfo")
		.def_readwrite("TrafficLightID", &AI10_TrafficLightControlInfo::TrafficLightID)
        .def_readwrite("TrafficLightState", &AI10_TrafficLightControlInfo::TrafficLightState)
        .def_readwrite("ActionType", &AI10_TrafficLightControlInfo::ActionType)
        .def_readwrite("isPhysicalEffect", &AI10_TrafficLightControlInfo::isPhysicalEffect)
        .def_readwrite("AnimationInfoSize", &AI10_TrafficLightControlInfo::AnimationInfoSize)
        .add_property("AnimationInfo", make_array(&AI10_TrafficLightControlInfo::AnimationInfo))
        .def_readwrite("TrafficLightTimer", &AI10_TrafficLightControlInfo::TrafficLightTimer)
    ;           
      
    py::class_<AI12_ControlInfo>("ControlInfo")
        .def("init_dynamic_buffer", &AI12_ControlInfo::init_daynamic_buffer)
    
        .def("human_objects_alloc", &AI12_ControlInfo::human_objects_alloc)
        .def("human_objects_size", &AI12_ControlInfo::human_objects_size)
        .def<AI07_HumanControlInfo* (AI12_ControlInfo::*)(const int)>("human_objects", &AI12_ControlInfo::human_objects,
             py::return_value_policy<py::reference_existing_object>())
        .def("animal_objects_alloc", &AI12_ControlInfo::animal_objects_alloc)
        .def("animal_objects_size", &AI12_ControlInfo::animal_objects_size)
        .def<AI08_AnimalControlInfo* (AI12_ControlInfo::*)(const int)>("animal_objects", &AI12_ControlInfo::animal_objects,
             py::return_value_policy<py::reference_existing_object>())
        .def("vehicle_objects_alloc", &AI12_ControlInfo::vehicle_objects_alloc)
        .def("vehicle_objects_size", &AI12_ControlInfo::vehicle_objects_size)
        .def<AI09_VehicleControlInfo* (AI12_ControlInfo::*)(const int)>("vehicle_objects", &AI12_ControlInfo::vehicle_objects,
             py::return_value_policy<py::reference_existing_object>())
        .def("traffic_light_objects_alloc", &AI12_ControlInfo::traffic_light_objects_alloc)
        .def("traffic_light_objects_size", &AI12_ControlInfo::traffic_light_objects_size)
        .def<AI10_TrafficLightControlInfo* (AI12_ControlInfo::*)(const int)>("traffic_light_objects", &AI12_ControlInfo::traffic_light_objects,
             py::return_value_policy<py::reference_existing_object>())
    ;          
      
    py::class_<AI13_DeleteObject>("DeleteObject")
        .ADD_PROPERTY(AI13_DeleteObject,DeleteObjectID)
        .def_readwrite("DeleteObjectType", &AI13_DeleteObject::DeleteObjectType)
    ;

	py::class_<AI14_DeleteObjectInfo>("DeleteObjectInfo")
		.def("init_dynamic_buffer", &AI14_DeleteObjectInfo::init_daynamic_buffer)

		.def("DeleteObjectArray_alloc", &AI14_DeleteObjectInfo::DeleteObjectArray_alloc)
		.def("DeleteObjectArray_size", &AI14_DeleteObjectInfo::DeleteObjectArray_size)
		.def<AI13_DeleteObject* (AI14_DeleteObjectInfo::*)(const int)>("DeleteObjectArray", &AI14_DeleteObjectInfo::DeleteObjectArray,
			py::return_value_policy<py::reference_existing_object>())
	;
      
    py::class_<AI15_StringInfo>("StringInfo")
        .ADD_PROPERTY(AI15_StringInfo,data)
    ;        
      
}

