/****************************************************************************************************************************************************

    Document Header

    domain   : Dongguk
    creator  : root
    create date          : 2018-07-30 09:31:35
    description          : 
 by root, at Mon Apr 20 11:21:19 2020

****************************************************************************************************************************************************/


/* Prevent Duplicated Including ********************************************************************************************************************/
#ifndef Define__Nerv__Data__Dongguk__Dongguk_h
#define Define__Nerv__Data__Dongguk__Dongguk_h


/* Include Nerv Sdk Document ***********************************************************************************************************************/
#include <Nerv/Nerv.h>


/* Include Inline ***********************************************************************************************************************/
#ifndef Define__Nerv__Data
#define Define__Nerv__Data

namespace  Nerv { namespace  Data { 
  template<class TYPE>
  inline ::Nerv::pksize_t nerv_sizeof(TYPE const* const& p) { return sizeof(*p); } 
} using namespace Data; } using namespace Nerv;
#endif // Define__Nerv__Data

/* Include Method_Parent Domains Document *****************************************************************************************************************/

/* Include Data Parent Domains Document *****************************************************************************************************************/


/* Domain Define ***********************************************************************************************************************************/
namespace  Nerv { namespace  Data { namespace  Dongguk { 

/* Data Defines ********************************************************************************************************************************/
    #pragma pack(1)
    #pragma warning(disable: 4200)

        /********************************************************************************************************************************************
         data name  : AA01_AutomaticCarStatus
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA01_AutomaticCarStatus
        {
               /*  */
               ::Nerv::ieee754_32_t Position[3];

               /*  */
               ::Nerv::ieee754_32_t ForwardVector[3];

               /*  */
               ::Nerv::ieee754_32_t dVelocity;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA01_AutomaticCarStatus const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA01_AutomaticCarStatus> AA01_AutomaticCarStatus_history_elem;
        typedef template_history<AA01_AutomaticCarStatus> AA01_AutomaticCarStatus_history;

        /********************************************************************************************************************************************
         data name  : SC02_Tick
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        typedef ::Nerv::ieee754_32_t SC02_Tick;
        typedef template_history_elem<SC02_Tick> SC02_Tick_history_elem;
        typedef template_history<SC02_Tick> SC02_Tick_history;

        /********************************************************************************************************************************************
         data name  : AA07_WeatherStatus
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA07_WeatherStatus
        {
               /*  */
               ::Nerv::int32_t IsWeatherRandom;

               /*  */
               ::Nerv::int32_t SeasonID;

               /*  */
               ::Nerv::int32_t WeatherID;

               /*  */
               ::Nerv::int32_t FogDensity;

               /*  */
               ::Nerv::int32_t CloudDensity;

               /*  */
               ::Nerv::int32_t Precipitation;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA07_WeatherStatus const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA07_WeatherStatus> AA07_WeatherStatus_history_elem;
        typedef template_history<AA07_WeatherStatus> AA07_WeatherStatus_history;

        /********************************************************************************************************************************************
         data name  : CE00_Action
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) CE00_Action
        {
               /*  */
               ::Nerv::int32_t Animation;

               /*  */
               ::Nerv::ieee754_32_t Destination[3];

               /*  */
               ::Nerv::ieee754_32_t Time;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( CE00_Action const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<CE00_Action> CE00_Action_history_elem;
        typedef template_history<CE00_Action> CE00_Action_history;

        /********************************************************************************************************************************************
         data name  : SC01_ScenarioSignalInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        typedef ::Nerv::int32_t SC01_ScenarioSignalInfo;
        typedef template_history_elem<SC01_ScenarioSignalInfo> SC01_ScenarioSignalInfo_history_elem;
        typedef template_history<SC01_ScenarioSignalInfo> SC01_ScenarioSignalInfo_history;

        /********************************************************************************************************************************************
         data name  : SC04_TrafficPatternInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        typedef ::Nerv::int32_t SC04_TrafficPatternInfo;
        typedef template_history_elem<SC04_TrafficPatternInfo> SC04_TrafficPatternInfo_history_elem;
        typedef template_history<SC04_TrafficPatternInfo> SC04_TrafficPatternInfo_history;

        /********************************************************************************************************************************************
         data name  : AA00_AnimationInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA00_AnimationInfo
        {
               /*  */
               ::Nerv::int32_t AnimationID;

               /*  */
               ::Nerv::int32_t PartID;

               /*  */
               ::Nerv::ieee754_32_t AnimationPlayWidth;

               /*  */
               ::Nerv::ieee754_32_t AnimationPlaySpeed;

               /*  */
               ::Nerv::int16_t AnimationLoop;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA00_AnimationInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA00_AnimationInfo> AA00_AnimationInfo_history_elem;
        typedef template_history<AA00_AnimationInfo> AA00_AnimationInfo_history;

        /********************************************************************************************************************************************
         data name  : SC00_ScenarioSetting
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) SC00_ScenarioSetting
        {
               /*  */
               ::Nerv::int32_t FPS;

               /*  */
               ::Nerv::int32_t CAR_NUM;

               /*  */
               ::Nerv::int32_t HUMAN_NUM;

               /*  */
               ::Nerv::int32_t ANIMAL_NUM;

               /*  */
               ::Nerv::int32_t MapType;

               /*  */
               ::Nerv::int32_t ObjectControlMode;

               /*  */
               ::Nerv::int32_t HumanLayer;

               /*  */
               ::Nerv::int32_t AnimalLayer;

               /*  */
               ::Nerv::int32_t VehicleLayer;

               /*  */
               ::Nerv::int32_t TrafficLightLayer;

               /*  */
               ::Nerv::int32_t WeatherLayer;

               /*  */
               ::Nerv::int32_t IsNew;

               /*  */
               ::Nerv::int32_t CarTypes[40];

               /*  */
               ::Nerv::int32_t AnimalTypes[40];

               /*  */
               ::Nerv::int32_t HumanTypes[40];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( SC00_ScenarioSetting const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<SC00_ScenarioSetting> SC00_ScenarioSetting_history_elem;
        typedef template_history<SC00_ScenarioSetting> SC00_ScenarioSetting_history;

        /********************************************************************************************************************************************
         data name  : SC03_CrashInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) SC03_CrashInfo
        {
               /*  */
               ::Nerv::ieee754_32_t Location[3];

               /*  */
               ::Nerv::ieee754_32_t Impulse;

               /*  */
               ::Nerv::char_t CauseObjectID[5];

               /*  */
               ::Nerv::char_t CausedObjectID[5];

               /*  */
               ::Nerv::int32_t CauseObjectDamagedPartList[10];

               /*  */
               ::Nerv::int32_t CausedObjectDamagedPartList[10];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( SC03_CrashInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<SC03_CrashInfo> SC03_CrashInfo_history_elem;
        typedef template_history<SC03_CrashInfo> SC03_CrashInfo_history;

        /********************************************************************************************************************************************
         data name  : IA00_InterruptAgent
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) IA00_InterruptAgent
        {
               /*  */
               ::Nerv::char_t ID[5];

               /*  */
               ::Nerv::int32_t DeletionStatus;

               /*  */
               ::Nerv::ieee754_32_t Location[3];

               /*  */
               ::Nerv::int32_t Mesh;

               /*  */
               ::Nerv::int32_t Animation;

               /*  */
               ::Nerv::ieee754_32_t Destination[3];

               /*  */
               ::Nerv::ieee754_32_t Time;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( IA00_InterruptAgent const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<IA00_InterruptAgent> IA00_InterruptAgent_history_elem;
        typedef template_history<IA00_InterruptAgent> IA00_InterruptAgent_history;

        /********************************************************************************************************************************************
         data name  : TE00_Box
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) TE00_Box
        {
               /*  */
               ::Nerv::int32_t Type;

               /*  */
               ::Nerv::ieee754_32_t location[3];

               /*  */
               ::Nerv::ieee754_32_t rotation[3];

               /*  */
               ::Nerv::ieee754_32_t extent[3];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( TE00_Box const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<TE00_Box> TE00_Box_history_elem;
        typedef template_history<TE00_Box> TE00_Box_history;

        /********************************************************************************************************************************************
         data name  : CE01_Subject
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) CE01_Subject
        {
               /*  */
               ::Nerv::int32_t Type;

               /*  */
               ::Nerv::int32_t Mesh;

               /*  */
               ::Nerv::ieee754_32_t StartPosition[3];

               /*  */
               ::Nerv::int32_t ActionNum;

               /*  */
               Nerv::Data::Dongguk::CE00_Action ActionArray[20];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( CE01_Subject const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<CE01_Subject> CE01_Subject_history_elem;
        typedef template_history<CE01_Subject> CE01_Subject_history;

        /********************************************************************************************************************************************
         data name  : IA01_InterruptAgentsList
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) IA01_InterruptAgentsList
        {
               /*  */
               variable_array_field_dctrl_t List_dctrl;
               Nerv::Data::Dongguk::IA00_InterruptAgent* List() { return (Nerv::Data::Dongguk::IA00_InterruptAgent*)(dynamicbuffer+List_dctrl.dindex); }
			   Nerv::Data::Dongguk::IA00_InterruptAgent* List(const int in_index) { return (Nerv::Data::Dongguk::IA00_InterruptAgent*)(dynamicbuffer + List_dctrl.dindex) + in_index; }
               Nerv::Data::Dongguk::IA00_InterruptAgent const* List() const { return (Nerv::Data::Dongguk::IA00_InterruptAgent const*)(dynamicbuffer+List_dctrl.dindex); }
               bool List_alloc(int array_size)
               {
                   bool ret_b;
                   List_dctrl.dindex = dynamicsize;
                   List_dctrl.dsize = array_size*sizeof(Nerv::Data::Dongguk::IA00_InterruptAgent);
                   if(_maxDynamicSize < dynamicsize + List_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += List_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int List_size()
               {
                   return List_dctrl.dsize / sizeof(Nerv::Data::Dongguk::IA00_InterruptAgent);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Dongguk::IA00_InterruptAgent)*600};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(IA01_InterruptAgentsList)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( IA01_InterruptAgentsList const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<IA01_InterruptAgentsList> IA01_InterruptAgentsList_history_elem;
        typedef template_history<IA01_InterruptAgentsList> IA01_InterruptAgentsList_history;

        /********************************************************************************************************************************************
         data name  : TE01_TopographicEvent
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) TE01_TopographicEvent
        {
               /*  */
               variable_array_field_dctrl_t Boxes_dctrl;
               Nerv::Data::Dongguk::TE00_Box* Boxes() { return (Nerv::Data::Dongguk::TE00_Box*)(dynamicbuffer+Boxes_dctrl.dindex); }
			   Nerv::Data::Dongguk::TE00_Box* Boxes(const int in_index) { return (Nerv::Data::Dongguk::TE00_Box*)(dynamicbuffer + Boxes_dctrl.dindex) + in_index; }
               Nerv::Data::Dongguk::TE00_Box const* Boxes() const { return (Nerv::Data::Dongguk::TE00_Box const*)(dynamicbuffer+Boxes_dctrl.dindex); }
               bool Boxes_alloc(int array_size)
               {
                   bool ret_b;
                   Boxes_dctrl.dindex = dynamicsize;
                   Boxes_dctrl.dsize = array_size*sizeof(Nerv::Data::Dongguk::TE00_Box);
                   if(_maxDynamicSize < dynamicsize + Boxes_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += Boxes_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int Boxes_size()
               {
                   return Boxes_dctrl.dsize / sizeof(Nerv::Data::Dongguk::TE00_Box);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Dongguk::TE00_Box)*200};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(TE01_TopographicEvent)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( TE01_TopographicEvent const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<TE01_TopographicEvent> TE01_TopographicEvent_history_elem;
        typedef template_history<TE01_TopographicEvent> TE01_TopographicEvent_history;

        /********************************************************************************************************************************************
         data name  : AA04_VehicleStatus
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA04_VehicleStatus
        {
               /*  */
               ::Nerv::char_t NpcCarID[5];

               /*  */
               ::Nerv::int32_t NpcCarType;

               /*  */
               ::Nerv::ieee754_32_t NpcCarLocation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcCarRotation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcCarColliderSize[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Dongguk::AA00_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA04_VehicleStatus const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA04_VehicleStatus> AA04_VehicleStatus_history_elem;
        typedef template_history<AA04_VehicleStatus> AA04_VehicleStatus_history;

        /********************************************************************************************************************************************
         data name  : AA02_HumanStatus
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA02_HumanStatus
        {
               /*  */
               ::Nerv::char_t NpcHumanID[5];

               /*  */
               ::Nerv::int32_t NpcHumanType;

               /*  */
               ::Nerv::ieee754_32_t NpcHumanLocation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcHumanRotation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcHumanColliderSize[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Dongguk::AA00_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA02_HumanStatus const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA02_HumanStatus> AA02_HumanStatus_history_elem;
        typedef template_history<AA02_HumanStatus> AA02_HumanStatus_history;

        /********************************************************************************************************************************************
         data name  : AA03_AnimalStatus
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA03_AnimalStatus
        {
               /*  */
               ::Nerv::char_t NpcAnimalID[5];

               /*  */
               ::Nerv::int32_t NpcAnimalType;

               /*  */
               ::Nerv::ieee754_32_t NpcAnimalLocation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcAnimalRotation[3];

               /*  */
               ::Nerv::ieee754_32_t NpcAnimalColliderSize[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Dongguk::AA00_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA03_AnimalStatus const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA03_AnimalStatus> AA03_AnimalStatus_history_elem;
        typedef template_history<AA03_AnimalStatus> AA03_AnimalStatus_history;

        /********************************************************************************************************************************************
         data name  : CE02_CustomEvent
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) CE02_CustomEvent
        {
               /*  */
               ::Nerv::char_t ID[7];

               /*  */
               ::Nerv::ieee754_32_t Position[3];

               /*  */
               ::Nerv::int32_t State;

               /*  */
               ::Nerv::ieee754_32_t StartDistance;

               /*  */
               ::Nerv::int32_t SubjectsNum;

               /*  */
               Nerv::Data::Dongguk::CE01_Subject SubjectsArray[5];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( CE02_CustomEvent const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<CE02_CustomEvent> CE02_CustomEvent_history_elem;
        typedef template_history<CE02_CustomEvent> CE02_CustomEvent_history;

        /********************************************************************************************************************************************
         data name  : CE03_CustomEventList
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) CE03_CustomEventList
        {
               /*  */
               variable_array_field_dctrl_t List_dctrl;
               Nerv::Data::Dongguk::CE02_CustomEvent* List() { return (Nerv::Data::Dongguk::CE02_CustomEvent*)(dynamicbuffer+List_dctrl.dindex); }
			   Nerv::Data::Dongguk::CE02_CustomEvent* List(const int in_index) { return (Nerv::Data::Dongguk::CE02_CustomEvent*)(dynamicbuffer + List_dctrl.dindex) + in_index; }
               Nerv::Data::Dongguk::CE02_CustomEvent const* List() const { return (Nerv::Data::Dongguk::CE02_CustomEvent const*)(dynamicbuffer+List_dctrl.dindex); }
               bool List_alloc(int array_size)
               {
                   bool ret_b;
                   List_dctrl.dindex = dynamicsize;
                   List_dctrl.dsize = array_size*sizeof(Nerv::Data::Dongguk::CE02_CustomEvent);
                   if(_maxDynamicSize < dynamicsize + List_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += List_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int List_size()
               {
                   return List_dctrl.dsize / sizeof(Nerv::Data::Dongguk::CE02_CustomEvent);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Dongguk::CE02_CustomEvent)*10000};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(CE03_CustomEventList)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( CE03_CustomEventList const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<CE03_CustomEventList> CE03_CustomEventList_history_elem;
        typedef template_history<CE03_CustomEventList> CE03_CustomEventList_history;

        /********************************************************************************************************************************************
         data name  : AA08_AllAgentsInformation
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AA08_AllAgentsInformation
        {
               /*  */
               static const double min_timestamp() { return double(-9223372036.854775807); }
               static const double max_timestamp() { return double(9223372036.854775807); }
               ::Nerv::real< ::Nerv::int64_t,min_timestamp,max_timestamp > timestamp;

               /*  */
               Nerv::Data::Dongguk::AA01_AutomaticCarStatus AutomaticCarStatusMemory;

               /*  */
               Nerv::Data::Dongguk::AA02_HumanStatus HumanStatusMemory[200];

               /*  */
               Nerv::Data::Dongguk::AA03_AnimalStatus AnimalStatusMemory[200];

               /*  */
               Nerv::Data::Dongguk::AA04_VehicleStatus VehicleStatusMemory[200];

               /*  */
               ::Nerv::int32_t Hour;

               /*  */
               Nerv::Data::Dongguk::AA07_WeatherStatus WeatherStatusMemory;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AA08_AllAgentsInformation const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AA08_AllAgentsInformation> AA08_AllAgentsInformation_history_elem;
        typedef template_history<AA08_AllAgentsInformation> AA08_AllAgentsInformation_history;

        #pragma warning(default : 4200)
        #pragma pack()


    /* Method Defines ******************************************************************************************************************************/


    /* Interface Defines ***************************************************************************************************************************/


} using namespace Dongguk; } using namespace Data; } using namespace Nerv; 

#endif // #ifdef Define__Nerv__Data__Dongguk__Dongguk_h
