/****************************************************************************************************************************************************

    Document Header

    domain   : Coretec
    creator  : root
    create date          : 2018-07-30 10:01:05
    description          : 
 by root, at Tue Mar 10 15:47:58 2020

****************************************************************************************************************************************************/


/* Prevent Duplicated Including ********************************************************************************************************************/
#ifndef Define__Nerv__Data__Coretec__Coretec_h
#define Define__Nerv__Data__Coretec__Coretec_h


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
namespace  Nerv { namespace  Data { namespace  Coretec { 

/* Data Defines ********************************************************************************************************************************/
    #pragma pack(1)
    #pragma warning(disable: 4200)

        /********************************************************************************************************************************************
         data name  : AI00_MonitoringReady
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI00_MonitoringReady
        {
               /*  */
               ::Nerv::int32_t Ready;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI00_MonitoringReady const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI00_MonitoringReady> AI00_MonitoringReady_history_elem;
        typedef template_history<AI00_MonitoringReady> AI00_MonitoringReady_history;

        /********************************************************************************************************************************************
         data name  : AI01_AnimationInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI01_AnimationInfo
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
               ::Nerv::int32_t AnimationLoop;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI01_AnimationInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI01_AnimationInfo> AI01_AnimationInfo_history_elem;
        typedef template_history<AI01_AnimationInfo> AI01_AnimationInfo_history;

        /********************************************************************************************************************************************
         data name  : AI02_HumanSpawnInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI02_HumanSpawnInfo
        {
               /*  */
               ::Nerv::char_t HumanID[5];

               /*  */
               ::Nerv::int32_t ResourceType;

               /*  */
               ::Nerv::ieee754_32_t Location[3];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI02_HumanSpawnInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI02_HumanSpawnInfo> AI02_HumanSpawnInfo_history_elem;
        typedef template_history<AI02_HumanSpawnInfo> AI02_HumanSpawnInfo_history;

        /********************************************************************************************************************************************
         data name  : AI03_AnimalSpawnInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI03_AnimalSpawnInfo
        {
               /*  */
               ::Nerv::char_t AnimalID[5];

               /*  */
               ::Nerv::int32_t ResourceType;

               /*  */
               ::Nerv::ieee754_32_t Location[3];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI03_AnimalSpawnInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI03_AnimalSpawnInfo> AI03_AnimalSpawnInfo_history_elem;
        typedef template_history<AI03_AnimalSpawnInfo> AI03_AnimalSpawnInfo_history;

        /********************************************************************************************************************************************
         data name  : AI04_VehicleSpawnInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI04_VehicleSpawnInfo
        {
               /*  */
               ::Nerv::char_t VehicleID[5];

               /*  */
               ::Nerv::int32_t ResourceType;

               /*  */
               ::Nerv::ieee754_32_t Location[3];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI04_VehicleSpawnInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI04_VehicleSpawnInfo> AI04_VehicleSpawnInfo_history_elem;
        typedef template_history<AI04_VehicleSpawnInfo> AI04_VehicleSpawnInfo_history;

        /********************************************************************************************************************************************
         data name  : AI06_SpawnInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI06_SpawnInfo
        {
               /*  */
               variable_array_field_dctrl_t human_spawn_dctrl;
               Nerv::Data::Coretec::AI02_HumanSpawnInfo* human_spawn() { return (Nerv::Data::Coretec::AI02_HumanSpawnInfo*)(dynamicbuffer+human_spawn_dctrl.dindex); }
			   Nerv::Data::Coretec::AI02_HumanSpawnInfo* human_spawn(const int in_index) { return (Nerv::Data::Coretec::AI02_HumanSpawnInfo*)(dynamicbuffer + human_spawn_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI02_HumanSpawnInfo const* human_spawn() const { return (Nerv::Data::Coretec::AI02_HumanSpawnInfo const*)(dynamicbuffer+human_spawn_dctrl.dindex); }
               bool human_spawn_alloc(int array_size)
               {
                   bool ret_b;
                   human_spawn_dctrl.dindex = dynamicsize;
                   human_spawn_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI02_HumanSpawnInfo);
                   if(_maxDynamicSize < dynamicsize + human_spawn_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += human_spawn_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int human_spawn_size()
               {
                   return human_spawn_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI02_HumanSpawnInfo);
               }

               /*  */
               variable_array_field_dctrl_t animal_spawn_dctrl;
               Nerv::Data::Coretec::AI03_AnimalSpawnInfo* animal_spawn() { return (Nerv::Data::Coretec::AI03_AnimalSpawnInfo*)(dynamicbuffer+animal_spawn_dctrl.dindex); }
			   Nerv::Data::Coretec::AI03_AnimalSpawnInfo* animal_spawn(const int in_index) { return (Nerv::Data::Coretec::AI03_AnimalSpawnInfo*)(dynamicbuffer + animal_spawn_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI03_AnimalSpawnInfo const* animal_spawn() const { return (Nerv::Data::Coretec::AI03_AnimalSpawnInfo const*)(dynamicbuffer+animal_spawn_dctrl.dindex); }
               bool animal_spawn_alloc(int array_size)
               {
                   bool ret_b;
                   animal_spawn_dctrl.dindex = dynamicsize;
                   animal_spawn_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI03_AnimalSpawnInfo);
                   if(_maxDynamicSize < dynamicsize + animal_spawn_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += animal_spawn_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int animal_spawn_size()
               {
                   return animal_spawn_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI03_AnimalSpawnInfo);
               }

               /*  */
               variable_array_field_dctrl_t vehicle_spawn_dctrl;
               Nerv::Data::Coretec::AI04_VehicleSpawnInfo* vehicle_spawn() { return (Nerv::Data::Coretec::AI04_VehicleSpawnInfo*)(dynamicbuffer+vehicle_spawn_dctrl.dindex); }
			   Nerv::Data::Coretec::AI04_VehicleSpawnInfo* vehicle_spawn(const int in_index) { return (Nerv::Data::Coretec::AI04_VehicleSpawnInfo*)(dynamicbuffer + vehicle_spawn_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI04_VehicleSpawnInfo const* vehicle_spawn() const { return (Nerv::Data::Coretec::AI04_VehicleSpawnInfo const*)(dynamicbuffer+vehicle_spawn_dctrl.dindex); }
               bool vehicle_spawn_alloc(int array_size)
               {
                   bool ret_b;
                   vehicle_spawn_dctrl.dindex = dynamicsize;
                   vehicle_spawn_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI04_VehicleSpawnInfo);
                   if(_maxDynamicSize < dynamicsize + vehicle_spawn_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += vehicle_spawn_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int vehicle_spawn_size()
               {
                   return vehicle_spawn_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI04_VehicleSpawnInfo);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Coretec::AI02_HumanSpawnInfo)*1024+sizeof(Nerv::Data::Coretec::AI03_AnimalSpawnInfo)*1024+sizeof(Nerv::Data::Coretec::AI04_VehicleSpawnInfo)*1024};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(AI06_SpawnInfo)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI06_SpawnInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI06_SpawnInfo> AI06_SpawnInfo_history_elem;
        typedef template_history<AI06_SpawnInfo> AI06_SpawnInfo_history;

        /********************************************************************************************************************************************
         data name  : AI07_HumanControlInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI07_HumanControlInfo
        {
               /*  */
               ::Nerv::char_t HumanID[5];

               /*  */
               ::Nerv::int32_t ActionType;

               /*  */
               ::Nerv::int32_t isPhysicalEffect;

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI07_HumanControlInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI07_HumanControlInfo> AI07_HumanControlInfo_history_elem;
        typedef template_history<AI07_HumanControlInfo> AI07_HumanControlInfo_history;

        /********************************************************************************************************************************************
         data name  : AI08_AnimalControlInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI08_AnimalControlInfo
        {
               /*  */
               ::Nerv::char_t AnimalID[5];

               /*  */
               ::Nerv::int32_t ActionType;

               /*  */
               ::Nerv::int32_t isPhysicalEffect;

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI08_AnimalControlInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI08_AnimalControlInfo> AI08_AnimalControlInfo_history_elem;
        typedef template_history<AI08_AnimalControlInfo> AI08_AnimalControlInfo_history;

        /********************************************************************************************************************************************
         data name  : AI09_VehicleControlInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI09_VehicleControlInfo
        {
               /*  */
               ::Nerv::char_t VehicleID[5];

               /*  */
               ::Nerv::int32_t ActionType;

               /*  */
               ::Nerv::int32_t isPhysicalEffect;

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::ieee754_32_t Rotation[3];

               /*  */
               ::Nerv::ieee754_32_t Speed;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI09_VehicleControlInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI09_VehicleControlInfo> AI09_VehicleControlInfo_history_elem;
        typedef template_history<AI09_VehicleControlInfo> AI09_VehicleControlInfo_history;

        /********************************************************************************************************************************************
         data name  : AI10_TrafficLightControlInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI10_TrafficLightControlInfo
        {
               /*  */
               ::Nerv::int32_t TrafficLightID;

               /*  */
               ::Nerv::int32_t ActionType;

               /*  */
               ::Nerv::int32_t isPhysicalEffect;

               /*  */
               ::Nerv::int32_t AnimationInfoSize;

               /*  */
               Nerv::Data::Coretec::AI01_AnimationInfo AnimationInfo[4];

               /*  */
               ::Nerv::int32_t TrafficLightState;

               /*  */
               ::Nerv::ieee754_32_t TrafficLightTimer;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI10_TrafficLightControlInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI10_TrafficLightControlInfo> AI10_TrafficLightControlInfo_history_elem;
        typedef template_history<AI10_TrafficLightControlInfo> AI10_TrafficLightControlInfo_history;

        /********************************************************************************************************************************************
         data name  : AI12_ControlInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI12_ControlInfo
        {
               /*  */
               variable_array_field_dctrl_t human_objects_dctrl;
               Nerv::Data::Coretec::AI07_HumanControlInfo* human_objects() { return (Nerv::Data::Coretec::AI07_HumanControlInfo*)(dynamicbuffer+human_objects_dctrl.dindex); }
			   Nerv::Data::Coretec::AI07_HumanControlInfo* human_objects(const int in_index) { return (Nerv::Data::Coretec::AI07_HumanControlInfo*)(dynamicbuffer + human_objects_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI07_HumanControlInfo const* human_objects() const { return (Nerv::Data::Coretec::AI07_HumanControlInfo const*)(dynamicbuffer+human_objects_dctrl.dindex); }
               bool human_objects_alloc(int array_size)
               {
                   bool ret_b;
                   human_objects_dctrl.dindex = dynamicsize;
                   human_objects_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI07_HumanControlInfo);
                   if(_maxDynamicSize < dynamicsize + human_objects_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += human_objects_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int human_objects_size()
               {
                   return human_objects_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI07_HumanControlInfo);
               }

               /*  */
               variable_array_field_dctrl_t animal_objects_dctrl;
               Nerv::Data::Coretec::AI08_AnimalControlInfo* animal_objects() { return (Nerv::Data::Coretec::AI08_AnimalControlInfo*)(dynamicbuffer+animal_objects_dctrl.dindex); }
			   Nerv::Data::Coretec::AI08_AnimalControlInfo* animal_objects(const int in_index) { return (Nerv::Data::Coretec::AI08_AnimalControlInfo*)(dynamicbuffer + animal_objects_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI08_AnimalControlInfo const* animal_objects() const { return (Nerv::Data::Coretec::AI08_AnimalControlInfo const*)(dynamicbuffer+animal_objects_dctrl.dindex); }
               bool animal_objects_alloc(int array_size)
               {
                   bool ret_b;
                   animal_objects_dctrl.dindex = dynamicsize;
                   animal_objects_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI08_AnimalControlInfo);
                   if(_maxDynamicSize < dynamicsize + animal_objects_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += animal_objects_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int animal_objects_size()
               {
                   return animal_objects_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI08_AnimalControlInfo);
               }

               /*  */
               variable_array_field_dctrl_t vehicle_objects_dctrl;
               Nerv::Data::Coretec::AI09_VehicleControlInfo* vehicle_objects() { return (Nerv::Data::Coretec::AI09_VehicleControlInfo*)(dynamicbuffer+vehicle_objects_dctrl.dindex); }
			   Nerv::Data::Coretec::AI09_VehicleControlInfo* vehicle_objects(const int in_index) { return (Nerv::Data::Coretec::AI09_VehicleControlInfo*)(dynamicbuffer + vehicle_objects_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI09_VehicleControlInfo const* vehicle_objects() const { return (Nerv::Data::Coretec::AI09_VehicleControlInfo const*)(dynamicbuffer+vehicle_objects_dctrl.dindex); }
               bool vehicle_objects_alloc(int array_size)
               {
                   bool ret_b;
                   vehicle_objects_dctrl.dindex = dynamicsize;
                   vehicle_objects_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI09_VehicleControlInfo);
                   if(_maxDynamicSize < dynamicsize + vehicle_objects_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += vehicle_objects_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int vehicle_objects_size()
               {
                   return vehicle_objects_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI09_VehicleControlInfo);
               }

               /*  */
               variable_array_field_dctrl_t traffic_light_objects_dctrl;
               Nerv::Data::Coretec::AI10_TrafficLightControlInfo* traffic_light_objects() { return (Nerv::Data::Coretec::AI10_TrafficLightControlInfo*)(dynamicbuffer+traffic_light_objects_dctrl.dindex); }
			   Nerv::Data::Coretec::AI10_TrafficLightControlInfo* traffic_light_objects(const int in_index) { return (Nerv::Data::Coretec::AI10_TrafficLightControlInfo*)(dynamicbuffer + traffic_light_objects_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI10_TrafficLightControlInfo const* traffic_light_objects() const { return (Nerv::Data::Coretec::AI10_TrafficLightControlInfo const*)(dynamicbuffer+traffic_light_objects_dctrl.dindex); }
               bool traffic_light_objects_alloc(int array_size)
               {
                   bool ret_b;
                   traffic_light_objects_dctrl.dindex = dynamicsize;
                   traffic_light_objects_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI10_TrafficLightControlInfo);
                   if(_maxDynamicSize < dynamicsize + traffic_light_objects_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += traffic_light_objects_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int traffic_light_objects_size()
               {
                   return traffic_light_objects_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI10_TrafficLightControlInfo);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Coretec::AI07_HumanControlInfo)*1024+sizeof(Nerv::Data::Coretec::AI08_AnimalControlInfo)*1024+sizeof(Nerv::Data::Coretec::AI09_VehicleControlInfo)*1024+sizeof(Nerv::Data::Coretec::AI10_TrafficLightControlInfo)*11000};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(AI12_ControlInfo)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI12_ControlInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI12_ControlInfo> AI12_ControlInfo_history_elem;
        typedef template_history<AI12_ControlInfo> AI12_ControlInfo_history;

        /********************************************************************************************************************************************
         data name  : AI13_DeleteObject
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI13_DeleteObject
        {
               /*  */
               ::Nerv::char_t DeleteObjectID[5];

               /*  */
               ::Nerv::int32_t DeleteObjectType;

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI13_DeleteObject const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI13_DeleteObject> AI13_DeleteObject_history_elem;
        typedef template_history<AI13_DeleteObject> AI13_DeleteObject_history;

        /********************************************************************************************************************************************
         data name  : AI14_DeleteObjectInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI14_DeleteObjectInfo
        {
               /*  */
               variable_array_field_dctrl_t DeleteObjectArray_dctrl;
               Nerv::Data::Coretec::AI13_DeleteObject* DeleteObjectArray() { return (Nerv::Data::Coretec::AI13_DeleteObject*)(dynamicbuffer+DeleteObjectArray_dctrl.dindex); }
			   Nerv::Data::Coretec::AI13_DeleteObject* DeleteObjectArray(const int in_index) { return (Nerv::Data::Coretec::AI13_DeleteObject*)(dynamicbuffer + DeleteObjectArray_dctrl.dindex) + in_index; }
               Nerv::Data::Coretec::AI13_DeleteObject const* DeleteObjectArray() const { return (Nerv::Data::Coretec::AI13_DeleteObject const*)(dynamicbuffer+DeleteObjectArray_dctrl.dindex); }
               bool DeleteObjectArray_alloc(int array_size)
               {
                   bool ret_b;
                   DeleteObjectArray_dctrl.dindex = dynamicsize;
                   DeleteObjectArray_dctrl.dsize = array_size*sizeof(Nerv::Data::Coretec::AI13_DeleteObject);
                   if(_maxDynamicSize < dynamicsize + DeleteObjectArray_dctrl.dsize)
                   {
                       ret_b=false;
                   }
                   else
                   {
                       dynamicsize += DeleteObjectArray_dctrl.dsize;
                       ret_b=true;
                   }
                   return ret_b;
               }
               int DeleteObjectArray_size()
               {
                   return DeleteObjectArray_dctrl.dsize / sizeof(Nerv::Data::Coretec::AI13_DeleteObject);
               }

               /* 가변 데이터 버퍼 */
               enum {_maxDynamicSize=0+sizeof(Nerv::Data::Coretec::AI13_DeleteObject)*1024};
               void init_daynamic_buffer() { dynamicsize = 0; }
               ::Nerv::pksize_t get_sizeof() const { return sizeof(AI14_DeleteObjectInfo)- _maxDynamicSize + dynamicsize; }
               ::Nerv::pksize_t dynamicsize;
               ::Nerv::u_int8_t dynamicbuffer[_maxDynamicSize];    // dynamic buffer
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI14_DeleteObjectInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI14_DeleteObjectInfo> AI14_DeleteObjectInfo_history_elem;
        typedef template_history<AI14_DeleteObjectInfo> AI14_DeleteObjectInfo_history;

        /********************************************************************************************************************************************
         data name  : AI15_StringInfo
         writer     : root
         description: 
        ********************************************************************************************************************************************/
        struct __attribute__((packed)) AI15_StringInfo
        {
               /*  */
               ::Nerv::char_t data[128];

               ::Nerv::pksize_t get_sizeof() const { return sizeof(*this); }
        };
        inline ::Nerv::pksize_t nerv_sizeof( AI15_StringInfo const* const& p) { return p->get_sizeof(); }
        typedef template_history_elem<AI15_StringInfo> AI15_StringInfo_history_elem;
        typedef template_history<AI15_StringInfo> AI15_StringInfo_history;

        #pragma warning(default : 4200)
        #pragma pack()


    /* Method Defines ******************************************************************************************************************************/


    /* Interface Defines ***************************************************************************************************************************/


} using namespace Coretec; } using namespace Data; } using namespace Nerv; 

#endif // #ifdef Define__Nerv__Data__Coretec__Coretec_h
