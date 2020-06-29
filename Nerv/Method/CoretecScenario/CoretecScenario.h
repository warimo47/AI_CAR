/****************************************************************************************************************************************************

    Document Header

    domain : CoretecScenario
    creator : root
    create date  : 2019-03-07 12:02:08
    standardport : 10005
    description : 
     by root, at Mon Jun 29 11:16:54 2020

****************************************************************************************************************************************************/


/* Prevent Duplicated Including ********************************************************************************************************************/
#ifndef Define__Nerv__Method__CoretecScenario__CoretecScenario_h
#define Define__Nerv__Method__CoretecScenario__CoretecScenario_h


/* Include Nerv Sdk Document ***********************************************************************************************************************/
#include <Nerv/Nerv.h>


/* Include Inline ***********************************************************************************************************************/


/* Include Method_Parent Domains Document *****************************************************************************************************************/


/* Include Data Parent Domains Document *****************************************************************************************************************/
#include <Nerv/Data/Coretec/Coretec.h>
#include <Nerv/Data/Dongguk/Dongguk.h>


/* Domain Define ***********************************************************************************************************************************/
namespace  Nerv { namespace  Method { namespace  CoretecScenario { 

/* Standard Domain Port Constance **************************************************************************************************************/

        const ::Nerv::domain_t c_standard_port = 10005;


/* Data Defines ********************************************************************************************************************************/

    /* Method Defines ******************************************************************************************************************************/

        /********************************************************************************************************************************************
         Method     : CO00_MonitoringReady
         Input      : Nerv::Data::Coretec::AI00_MonitoringReady
         Output     : ::
         Method Type: COMMAND
         Code       : 0x0000
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_CO00_MonitoringReady : public ::Nerv::nerv_proxy_object_command
        {
        public:
               proxy_method_CO00_MonitoringReady() :  nerv_proxy_object_command(0x0000) {}

               bool CO00_MonitoringReady_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t CO00_MonitoringReady_connect( const double& in_limit_time = 1.0 , double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void CO00_MonitoringReady_shutdown() { shutdown(); }

               void CO00_MonitoringReady_set_sync_model ( const bool& in_using_udp,
                                 const sender_sync_model_t& in_sync_model,
                                              const double& in_interval)
               {
                      set_sync_model ( in_using_udp, in_sync_model,in_interval);
               }

               Nerv::Data::Coretec::AI00_MonitoringReady* CO00_MonitoringReady_get()
               {
                      return (Nerv::Data::Coretec::AI00_MonitoringReady*)get(sizeof(Nerv::Data::Coretec::AI00_MonitoringReady));
               }

               void CO00_MonitoringReady_cancel()
               {
                      cancel();
               }

               nerv_err_t CO00_MonitoringReady_post(Nerv::Data::Coretec::AI00_MonitoringReady* pin_buf  )
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                        return post( in_size);
               }

               nerv_err_t CO00_MonitoringReady_write( Nerv::Data::Coretec::AI00_MonitoringReady const* const& pin_buf)
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
               }

               letter_case_t CO00_MonitoringReady_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void CO00_MonitoringReady_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t CO00_MonitoringReady_read( Nerv::Data::Coretec::AI00_MonitoringReady* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI00_MonitoringReady);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_CO00_MonitoringReady_disconnected();
               }

               virtual void on_CO00_MonitoringReady_disconnected() = 0; //{}
        };

        /* stub */
        class method_CO00_MonitoringReady : public ::Nerv::nerv_object_command
        {
        public:
               method_CO00_MonitoringReady() : nerv_object_command(0x0000) {}

               void CO00_MonitoringReady_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }


               void CO00_MonitoringReady_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }

			    void CO00_MonitoringReady_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }

			    void CO00_MonitoringReady_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }

               void CO00_MonitoringReady_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t CO00_MonitoringReady_see_history( const client_addr_t& in_client_addr, const size_t& in_size)
               {
                      return see_history(in_client_addr, in_size);
               }

               void CO00_MonitoringReady_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               int CO00_MonitoringReady_get_client_count()
               {
                      return get_client_count();
               }

               nerv_err_t CO00_MonitoringReady_read(const client_addr_t& in_client, Nerv::Data::Coretec::AI00_MonitoringReady* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI00_MonitoringReady);
                      return read(in_client, pin_data, &in_size );
               }

        private:

               virtual void on_sync( const client_addr_t& in_client,
                               const sender_sync_model_t& in_sync_model,
                                            const double& in_elapsed,
                                            const double& in_limit,
                                        void const* const pin_buffer,
                                           const pksize_t in_size)
               {
                      on_CO00_MonitoringReady_sync(in_client, in_sync_model,in_limit, in_elapsed,(Nerv::Data::Coretec::AI00_MonitoringReady const* const)pin_buffer);
               }

               virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
               {
                      return on_CO00_MonitoringReady_connect( in_client_addr,in_elapsed_time,in_limit_time );
               }

               virtual void on_shutdown( const client_addr_t& in_client_addr)
               {
                      on_CO00_MonitoringReady_shutdown(in_client_addr);
               }

               virtual nerv_err_t on_CO00_MonitoringReady_connect( const client_addr_t& in_client_addr,
                                                                const double& in_elapsed_time,
                                                                const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

               virtual void on_CO00_MonitoringReady_shutdown( const client_addr_t& in_client_addr) = 0; //{}

               virtual void on_CO00_MonitoringReady_sync( const client_addr_t& in_client,
                                          const sender_sync_model_t& in_sync_model,
                                                       const double& in_limit,
                                                       const double& in_elapsed
                                                       ,
Nerv::Data::Coretec::AI00_MonitoringReady const* const pin_buffer ) = 0; //{}
        };

        /********************************************************************************************************************************************
         Method     : CO01_SpawnInfo
         Input      : Nerv::Data::Coretec::AI06_SpawnInfo
         Output     : ::
         Method Type: COMMAND
         Code       : 0x0001
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_CO01_SpawnInfo : public ::Nerv::nerv_proxy_object_command
        {
        public:
               proxy_method_CO01_SpawnInfo() :  nerv_proxy_object_command(0x0001) {}

               bool CO01_SpawnInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t CO01_SpawnInfo_connect( const double& in_limit_time = 1.0 , double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void CO01_SpawnInfo_shutdown() { shutdown(); }

               void CO01_SpawnInfo_set_sync_model ( const bool& in_using_udp,
                                 const sender_sync_model_t& in_sync_model,
                                              const double& in_interval)
               {
                      set_sync_model ( in_using_udp, in_sync_model,in_interval);
               }

               Nerv::Data::Coretec::AI06_SpawnInfo* CO01_SpawnInfo_get()
               {
                      return (Nerv::Data::Coretec::AI06_SpawnInfo*)get(sizeof(Nerv::Data::Coretec::AI06_SpawnInfo));
               }

               void CO01_SpawnInfo_cancel()
               {
                      cancel();
               }

               nerv_err_t CO01_SpawnInfo_post(Nerv::Data::Coretec::AI06_SpawnInfo* pin_buf  )
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                        return post( in_size);
               }

               nerv_err_t CO01_SpawnInfo_write( Nerv::Data::Coretec::AI06_SpawnInfo const* const& pin_buf)
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
               }

               letter_case_t CO01_SpawnInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void CO01_SpawnInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t CO01_SpawnInfo_read( Nerv::Data::Coretec::AI06_SpawnInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI06_SpawnInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_CO01_SpawnInfo_disconnected();
               }

               virtual void on_CO01_SpawnInfo_disconnected() = 0; //{}
        };

        /* stub */
        class method_CO01_SpawnInfo : public ::Nerv::nerv_object_command
        {
        public:
               method_CO01_SpawnInfo() : nerv_object_command(0x0001) {}

               void CO01_SpawnInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }


               void CO01_SpawnInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }

			    void CO01_SpawnInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }

			    void CO01_SpawnInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }

               void CO01_SpawnInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t CO01_SpawnInfo_see_history( const client_addr_t& in_client_addr, const size_t& in_size)
               {
                      return see_history(in_client_addr, in_size);
               }

               void CO01_SpawnInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               int CO01_SpawnInfo_get_client_count()
               {
                      return get_client_count();
               }

               nerv_err_t CO01_SpawnInfo_read(const client_addr_t& in_client, Nerv::Data::Coretec::AI06_SpawnInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI06_SpawnInfo);
                      return read(in_client, pin_data, &in_size );
               }

        private:

               virtual void on_sync( const client_addr_t& in_client,
                               const sender_sync_model_t& in_sync_model,
                                            const double& in_elapsed,
                                            const double& in_limit,
                                        void const* const pin_buffer,
                                           const pksize_t in_size)
               {
                      on_CO01_SpawnInfo_sync(in_client, in_sync_model,in_limit, in_elapsed,(Nerv::Data::Coretec::AI06_SpawnInfo const* const)pin_buffer);
               }

               virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
               {
                      return on_CO01_SpawnInfo_connect( in_client_addr,in_elapsed_time,in_limit_time );
               }

               virtual void on_shutdown( const client_addr_t& in_client_addr)
               {
                      on_CO01_SpawnInfo_shutdown(in_client_addr);
               }

               virtual nerv_err_t on_CO01_SpawnInfo_connect( const client_addr_t& in_client_addr,
                                                                const double& in_elapsed_time,
                                                                const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

               virtual void on_CO01_SpawnInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

               virtual void on_CO01_SpawnInfo_sync( const client_addr_t& in_client,
                                          const sender_sync_model_t& in_sync_model,
                                                       const double& in_limit,
                                                       const double& in_elapsed
                                                       ,
Nerv::Data::Coretec::AI06_SpawnInfo const* const pin_buffer ) = 0; //{}
        };

        /********************************************************************************************************************************************
         Method     : CO02_ControlInfo
         Input      : Nerv::Data::Coretec::AI12_ControlInfo
         Output     : ::
         Method Type: COMMAND
         Code       : 0x0002
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_CO02_ControlInfo : public ::Nerv::nerv_proxy_object_command
        {
        public:
               proxy_method_CO02_ControlInfo() :  nerv_proxy_object_command(0x0002) {}

               bool CO02_ControlInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t CO02_ControlInfo_connect( const double& in_limit_time = 1.0 , double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void CO02_ControlInfo_shutdown() { shutdown(); }

               void CO02_ControlInfo_set_sync_model ( const bool& in_using_udp,
                                 const sender_sync_model_t& in_sync_model,
                                              const double& in_interval)
               {
                      set_sync_model ( in_using_udp, in_sync_model,in_interval);
               }

               Nerv::Data::Coretec::AI12_ControlInfo* CO02_ControlInfo_get()
               {
                      return (Nerv::Data::Coretec::AI12_ControlInfo*)get(sizeof(Nerv::Data::Coretec::AI12_ControlInfo));
               }

               void CO02_ControlInfo_cancel()
               {
                      cancel();
               }

               nerv_err_t CO02_ControlInfo_post(Nerv::Data::Coretec::AI12_ControlInfo* pin_buf  )
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                        return post( in_size);
               }

               nerv_err_t CO02_ControlInfo_write( Nerv::Data::Coretec::AI12_ControlInfo const* const& pin_buf)
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
               }

               letter_case_t CO02_ControlInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void CO02_ControlInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t CO02_ControlInfo_read( Nerv::Data::Coretec::AI12_ControlInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI12_ControlInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_CO02_ControlInfo_disconnected();
               }

               virtual void on_CO02_ControlInfo_disconnected() = 0; //{}
        };

        /* stub */
        class method_CO02_ControlInfo : public ::Nerv::nerv_object_command
        {
        public:
               method_CO02_ControlInfo() : nerv_object_command(0x0002) {}

               void CO02_ControlInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }


               void CO02_ControlInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }

			    void CO02_ControlInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }

			    void CO02_ControlInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }

               void CO02_ControlInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t CO02_ControlInfo_see_history( const client_addr_t& in_client_addr, const size_t& in_size)
               {
                      return see_history(in_client_addr, in_size);
               }

               void CO02_ControlInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               int CO02_ControlInfo_get_client_count()
               {
                      return get_client_count();
               }

               nerv_err_t CO02_ControlInfo_read(const client_addr_t& in_client, Nerv::Data::Coretec::AI12_ControlInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI12_ControlInfo);
                      return read(in_client, pin_data, &in_size );
               }

        private:

               virtual void on_sync( const client_addr_t& in_client,
                               const sender_sync_model_t& in_sync_model,
                                            const double& in_elapsed,
                                            const double& in_limit,
                                        void const* const pin_buffer,
                                           const pksize_t in_size)
               {
                      on_CO02_ControlInfo_sync(in_client, in_sync_model,in_limit, in_elapsed,(Nerv::Data::Coretec::AI12_ControlInfo const* const)pin_buffer);
               }

               virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
               {
                      return on_CO02_ControlInfo_connect( in_client_addr,in_elapsed_time,in_limit_time );
               }

               virtual void on_shutdown( const client_addr_t& in_client_addr)
               {
                      on_CO02_ControlInfo_shutdown(in_client_addr);
               }

               virtual nerv_err_t on_CO02_ControlInfo_connect( const client_addr_t& in_client_addr,
                                                                const double& in_elapsed_time,
                                                                const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

               virtual void on_CO02_ControlInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

               virtual void on_CO02_ControlInfo_sync( const client_addr_t& in_client,
                                          const sender_sync_model_t& in_sync_model,
                                                       const double& in_limit,
                                                       const double& in_elapsed
                                                       ,
Nerv::Data::Coretec::AI12_ControlInfo const* const pin_buffer ) = 0; //{}
        };

        /********************************************************************************************************************************************
         Method     : CO03_DeleteObjectInfo
         Input      : Nerv::Data::Coretec::AI14_DeleteObjectInfo
         Output     : ::
         Method Type: COMMAND
         Code       : 0x0003
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_CO03_DeleteObjectInfo : public ::Nerv::nerv_proxy_object_command
        {
        public:
               proxy_method_CO03_DeleteObjectInfo() :  nerv_proxy_object_command(0x0003) {}

               bool CO03_DeleteObjectInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t CO03_DeleteObjectInfo_connect( const double& in_limit_time = 1.0 , double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void CO03_DeleteObjectInfo_shutdown() { shutdown(); }

               void CO03_DeleteObjectInfo_set_sync_model ( const bool& in_using_udp,
                                 const sender_sync_model_t& in_sync_model,
                                              const double& in_interval)
               {
                      set_sync_model ( in_using_udp, in_sync_model,in_interval);
               }

               Nerv::Data::Coretec::AI14_DeleteObjectInfo* CO03_DeleteObjectInfo_get()
               {
                      return (Nerv::Data::Coretec::AI14_DeleteObjectInfo*)get(sizeof(Nerv::Data::Coretec::AI14_DeleteObjectInfo));
               }

               void CO03_DeleteObjectInfo_cancel()
               {
                      cancel();
               }

               nerv_err_t CO03_DeleteObjectInfo_post(Nerv::Data::Coretec::AI14_DeleteObjectInfo* pin_buf  )
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                        return post( in_size);
               }

               nerv_err_t CO03_DeleteObjectInfo_write( Nerv::Data::Coretec::AI14_DeleteObjectInfo const* const& pin_buf)
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
               }

               letter_case_t CO03_DeleteObjectInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void CO03_DeleteObjectInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t CO03_DeleteObjectInfo_read( Nerv::Data::Coretec::AI14_DeleteObjectInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI14_DeleteObjectInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_CO03_DeleteObjectInfo_disconnected();
               }

               virtual void on_CO03_DeleteObjectInfo_disconnected() = 0; //{}
        };

        /* stub */
        class method_CO03_DeleteObjectInfo : public ::Nerv::nerv_object_command
        {
        public:
               method_CO03_DeleteObjectInfo() : nerv_object_command(0x0003) {}

               void CO03_DeleteObjectInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }


               void CO03_DeleteObjectInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }

			    void CO03_DeleteObjectInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }

			    void CO03_DeleteObjectInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }

               void CO03_DeleteObjectInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t CO03_DeleteObjectInfo_see_history( const client_addr_t& in_client_addr, const size_t& in_size)
               {
                      return see_history(in_client_addr, in_size);
               }

               void CO03_DeleteObjectInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               int CO03_DeleteObjectInfo_get_client_count()
               {
                      return get_client_count();
               }

               nerv_err_t CO03_DeleteObjectInfo_read(const client_addr_t& in_client, Nerv::Data::Coretec::AI14_DeleteObjectInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI14_DeleteObjectInfo);
                      return read(in_client, pin_data, &in_size );
               }

        private:

               virtual void on_sync( const client_addr_t& in_client,
                               const sender_sync_model_t& in_sync_model,
                                            const double& in_elapsed,
                                            const double& in_limit,
                                        void const* const pin_buffer,
                                           const pksize_t in_size)
               {
                      on_CO03_DeleteObjectInfo_sync(in_client, in_sync_model,in_limit, in_elapsed,(Nerv::Data::Coretec::AI14_DeleteObjectInfo const* const)pin_buffer);
               }

               virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
               {
                      return on_CO03_DeleteObjectInfo_connect( in_client_addr,in_elapsed_time,in_limit_time );
               }

               virtual void on_shutdown( const client_addr_t& in_client_addr)
               {
                      on_CO03_DeleteObjectInfo_shutdown(in_client_addr);
               }

               virtual nerv_err_t on_CO03_DeleteObjectInfo_connect( const client_addr_t& in_client_addr,
                                                                const double& in_elapsed_time,
                                                                const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

               virtual void on_CO03_DeleteObjectInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

               virtual void on_CO03_DeleteObjectInfo_sync( const client_addr_t& in_client,
                                          const sender_sync_model_t& in_sync_model,
                                                       const double& in_limit,
                                                       const double& in_elapsed
                                                       ,
Nerv::Data::Coretec::AI14_DeleteObjectInfo const* const pin_buffer ) = 0; //{}
        };

        /********************************************************************************************************************************************
         Method     : CO04_StringInfo
         Input      : Nerv::Data::Coretec::AI15_StringInfo
         Output     : ::
         Method Type: COMMAND
         Code       : 0x0004
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_CO04_StringInfo : public ::Nerv::nerv_proxy_object_command
        {
        public:
               proxy_method_CO04_StringInfo() :  nerv_proxy_object_command(0x0004) {}

               bool CO04_StringInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t CO04_StringInfo_connect( const double& in_limit_time = 1.0 , double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void CO04_StringInfo_shutdown() { shutdown(); }

               void CO04_StringInfo_set_sync_model ( const bool& in_using_udp,
                                 const sender_sync_model_t& in_sync_model,
                                              const double& in_interval)
               {
                      set_sync_model ( in_using_udp, in_sync_model,in_interval);
               }

               Nerv::Data::Coretec::AI15_StringInfo* CO04_StringInfo_get()
               {
                      return (Nerv::Data::Coretec::AI15_StringInfo*)get(sizeof(Nerv::Data::Coretec::AI15_StringInfo));
               }

               void CO04_StringInfo_cancel()
               {
                      cancel();
               }

               nerv_err_t CO04_StringInfo_post(Nerv::Data::Coretec::AI15_StringInfo* pin_buf  )
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                        return post( in_size);
               }

               nerv_err_t CO04_StringInfo_write( Nerv::Data::Coretec::AI15_StringInfo const* const& pin_buf)
               {
                      ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
               }

               letter_case_t CO04_StringInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void CO04_StringInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t CO04_StringInfo_read( Nerv::Data::Coretec::AI15_StringInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI15_StringInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_CO04_StringInfo_disconnected();
               }

               virtual void on_CO04_StringInfo_disconnected() = 0; //{}
        };

        /* stub */
        class method_CO04_StringInfo : public ::Nerv::nerv_object_command
        {
        public:
               method_CO04_StringInfo() : nerv_object_command(0x0004) {}

               void CO04_StringInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }


               void CO04_StringInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }

			    void CO04_StringInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }

			    void CO04_StringInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }

               void CO04_StringInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t CO04_StringInfo_see_history( const client_addr_t& in_client_addr, const size_t& in_size)
               {
                      return see_history(in_client_addr, in_size);
               }

               void CO04_StringInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               int CO04_StringInfo_get_client_count()
               {
                      return get_client_count();
               }

               nerv_err_t CO04_StringInfo_read(const client_addr_t& in_client, Nerv::Data::Coretec::AI15_StringInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Coretec::AI15_StringInfo);
                      return read(in_client, pin_data, &in_size );
               }

        private:

               virtual void on_sync( const client_addr_t& in_client,
                               const sender_sync_model_t& in_sync_model,
                                            const double& in_elapsed,
                                            const double& in_limit,
                                        void const* const pin_buffer,
                                           const pksize_t in_size)
               {
                      on_CO04_StringInfo_sync(in_client, in_sync_model,in_limit, in_elapsed,(Nerv::Data::Coretec::AI15_StringInfo const* const)pin_buffer);
               }

               virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
               {
                      return on_CO04_StringInfo_connect( in_client_addr,in_elapsed_time,in_limit_time );
               }

               virtual void on_shutdown( const client_addr_t& in_client_addr)
               {
                      on_CO04_StringInfo_shutdown(in_client_addr);
               }

               virtual nerv_err_t on_CO04_StringInfo_connect( const client_addr_t& in_client_addr,
                                                                const double& in_elapsed_time,
                                                                const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

               virtual void on_CO04_StringInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

               virtual void on_CO04_StringInfo_sync( const client_addr_t& in_client,
                                          const sender_sync_model_t& in_sync_model,
                                                       const double& in_limit,
                                                       const double& in_elapsed
                                                       ,
Nerv::Data::Coretec::AI15_StringInfo const* const pin_buffer ) = 0; //{}
        };

        /********************************************************************************************************************************************
         Method     : IN00_AllAgentsInformation
         Input      : ::
         Output     : Nerv::Data::Dongguk::AA08_AllAgentsInformation
         Method Type: INFORMATION
         Code       : 0x1000
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN00_AllAgentsInformation : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN00_AllAgentsInformation() : nerv_proxy_object_information(0x1000) {}

               bool IN00_AllAgentsInformation_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN00_AllAgentsInformation_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN00_AllAgentsInformation_shutdown() { shutdown(); }

               void IN00_AllAgentsInformation_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN00_AllAgentsInformation_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN00_AllAgentsInformation_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN00_AllAgentsInformation_read( Nerv::Data::Dongguk::AA08_AllAgentsInformation* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::AA08_AllAgentsInformation);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN00_AllAgentsInformation_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN00_AllAgentsInformation_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::AA08_AllAgentsInformation const* const)pin_buffer );
               }

               virtual void on_IN00_AllAgentsInformation_disconnected() = 0; //{}

               virtual void on_IN00_AllAgentsInformation_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::AA08_AllAgentsInformation const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN00_AllAgentsInformation : public ::Nerv::nerv_object_information
        {

        public:

               method_IN00_AllAgentsInformation(int interval= 0) : nerv_object_information(0x1000) {}

               void IN00_AllAgentsInformation_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN00_AllAgentsInformation_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN00_AllAgentsInformation_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN00_AllAgentsInformation_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN00_AllAgentsInformation_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::AA08_AllAgentsInformation* IN00_AllAgentsInformation_get()
               {
                      return (Nerv::Data::Dongguk::AA08_AllAgentsInformation*) get(sizeof(Nerv::Data::Dongguk::AA08_AllAgentsInformation) );
                }

                void IN00_AllAgentsInformation_cancel()
                {
                       cancel();
                }

                nerv_err_t IN00_AllAgentsInformation_post(Nerv::Data::Dongguk::AA08_AllAgentsInformation* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN00_AllAgentsInformation_write(Nerv::Data::Dongguk::AA08_AllAgentsInformation* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN00_AllAgentsInformation_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN00_AllAgentsInformation_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN00_AllAgentsInformation_read( Nerv::Data::Dongguk::AA08_AllAgentsInformation* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::AA08_AllAgentsInformation);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN00_AllAgentsInformation_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN00_AllAgentsInformation_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN00_AllAgentsInformation_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN00_AllAgentsInformation_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN01_ScenarioSetting
         Input      : ::
         Output     : Nerv::Data::Dongguk::SC00_ScenarioSetting
         Method Type: INFORMATION
         Code       : 0x1001
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN01_ScenarioSetting : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN01_ScenarioSetting() : nerv_proxy_object_information(0x1001) {}

               bool IN01_ScenarioSetting_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN01_ScenarioSetting_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN01_ScenarioSetting_shutdown() { shutdown(); }

               void IN01_ScenarioSetting_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN01_ScenarioSetting_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN01_ScenarioSetting_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN01_ScenarioSetting_read( Nerv::Data::Dongguk::SC00_ScenarioSetting* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC00_ScenarioSetting);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN01_ScenarioSetting_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN01_ScenarioSetting_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::SC00_ScenarioSetting const* const)pin_buffer );
               }

               virtual void on_IN01_ScenarioSetting_disconnected() = 0; //{}

               virtual void on_IN01_ScenarioSetting_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::SC00_ScenarioSetting const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN01_ScenarioSetting : public ::Nerv::nerv_object_information
        {

        public:

               method_IN01_ScenarioSetting(int interval= 0) : nerv_object_information(0x1001) {}

               void IN01_ScenarioSetting_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN01_ScenarioSetting_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN01_ScenarioSetting_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN01_ScenarioSetting_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN01_ScenarioSetting_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::SC00_ScenarioSetting* IN01_ScenarioSetting_get()
               {
                      return (Nerv::Data::Dongguk::SC00_ScenarioSetting*) get(sizeof(Nerv::Data::Dongguk::SC00_ScenarioSetting) );
                }

                void IN01_ScenarioSetting_cancel()
                {
                       cancel();
                }

                nerv_err_t IN01_ScenarioSetting_post(Nerv::Data::Dongguk::SC00_ScenarioSetting* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN01_ScenarioSetting_write(Nerv::Data::Dongguk::SC00_ScenarioSetting* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN01_ScenarioSetting_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN01_ScenarioSetting_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN01_ScenarioSetting_read( Nerv::Data::Dongguk::SC00_ScenarioSetting* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC00_ScenarioSetting);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN01_ScenarioSetting_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN01_ScenarioSetting_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN01_ScenarioSetting_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN01_ScenarioSetting_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN02_CustomEventList
         Input      : ::
         Output     : Nerv::Data::Dongguk::CE03_CustomEventList
         Method Type: INFORMATION
         Code       : 0x1002
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN02_CustomEventList : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN02_CustomEventList() : nerv_proxy_object_information(0x1002) {}

               bool IN02_CustomEventList_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN02_CustomEventList_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN02_CustomEventList_shutdown() { shutdown(); }

               void IN02_CustomEventList_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN02_CustomEventList_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN02_CustomEventList_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN02_CustomEventList_read( Nerv::Data::Dongguk::CE03_CustomEventList* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::CE03_CustomEventList);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN02_CustomEventList_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN02_CustomEventList_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::CE03_CustomEventList const* const)pin_buffer );
               }

               virtual void on_IN02_CustomEventList_disconnected() = 0; //{}

               virtual void on_IN02_CustomEventList_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::CE03_CustomEventList const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN02_CustomEventList : public ::Nerv::nerv_object_information
        {

        public:

               method_IN02_CustomEventList(int interval= 0) : nerv_object_information(0x1002) {}

               void IN02_CustomEventList_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN02_CustomEventList_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN02_CustomEventList_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN02_CustomEventList_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN02_CustomEventList_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::CE03_CustomEventList* IN02_CustomEventList_get()
               {
                      return (Nerv::Data::Dongguk::CE03_CustomEventList*) get(sizeof(Nerv::Data::Dongguk::CE03_CustomEventList) );
                }

                void IN02_CustomEventList_cancel()
                {
                       cancel();
                }

                nerv_err_t IN02_CustomEventList_post(Nerv::Data::Dongguk::CE03_CustomEventList* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN02_CustomEventList_write(Nerv::Data::Dongguk::CE03_CustomEventList* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN02_CustomEventList_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN02_CustomEventList_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN02_CustomEventList_read( Nerv::Data::Dongguk::CE03_CustomEventList* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::CE03_CustomEventList);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN02_CustomEventList_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN02_CustomEventList_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN02_CustomEventList_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN02_CustomEventList_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN03_ScenarioSignalInfo
         Input      : ::
         Output     : Nerv::Data::Dongguk::SC01_ScenarioSignalInfo
         Method Type: INFORMATION
         Code       : 0x1003
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN03_ScenarioSignalInfo : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN03_ScenarioSignalInfo() : nerv_proxy_object_information(0x1003) {}

               bool IN03_ScenarioSignalInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN03_ScenarioSignalInfo_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN03_ScenarioSignalInfo_shutdown() { shutdown(); }

               void IN03_ScenarioSignalInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN03_ScenarioSignalInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN03_ScenarioSignalInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN03_ScenarioSignalInfo_read( Nerv::Data::Dongguk::SC01_ScenarioSignalInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC01_ScenarioSignalInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN03_ScenarioSignalInfo_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN03_ScenarioSignalInfo_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::SC01_ScenarioSignalInfo const* const)pin_buffer );
               }

               virtual void on_IN03_ScenarioSignalInfo_disconnected() = 0; //{}

               virtual void on_IN03_ScenarioSignalInfo_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::SC01_ScenarioSignalInfo const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN03_ScenarioSignalInfo : public ::Nerv::nerv_object_information
        {

        public:

               method_IN03_ScenarioSignalInfo(int interval= 0) : nerv_object_information(0x1003) {}

               void IN03_ScenarioSignalInfo_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN03_ScenarioSignalInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN03_ScenarioSignalInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN03_ScenarioSignalInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN03_ScenarioSignalInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::SC01_ScenarioSignalInfo* IN03_ScenarioSignalInfo_get()
               {
                      return (Nerv::Data::Dongguk::SC01_ScenarioSignalInfo*) get(sizeof(Nerv::Data::Dongguk::SC01_ScenarioSignalInfo) );
                }

                void IN03_ScenarioSignalInfo_cancel()
                {
                       cancel();
                }

                nerv_err_t IN03_ScenarioSignalInfo_post(Nerv::Data::Dongguk::SC01_ScenarioSignalInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN03_ScenarioSignalInfo_write(Nerv::Data::Dongguk::SC01_ScenarioSignalInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN03_ScenarioSignalInfo_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN03_ScenarioSignalInfo_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN03_ScenarioSignalInfo_read( Nerv::Data::Dongguk::SC01_ScenarioSignalInfo* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC01_ScenarioSignalInfo);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN03_ScenarioSignalInfo_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN03_ScenarioSignalInfo_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN03_ScenarioSignalInfo_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN03_ScenarioSignalInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN04_Tick
         Input      : ::
         Output     : Nerv::Data::Dongguk::SC02_Tick
         Method Type: INFORMATION
         Code       : 0x1004
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN04_Tick : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN04_Tick() : nerv_proxy_object_information(0x1004) {}

               bool IN04_Tick_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN04_Tick_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN04_Tick_shutdown() { shutdown(); }

               void IN04_Tick_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN04_Tick_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN04_Tick_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN04_Tick_read( Nerv::Data::Dongguk::SC02_Tick* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC02_Tick);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN04_Tick_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN04_Tick_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::SC02_Tick const* const)pin_buffer );
               }

               virtual void on_IN04_Tick_disconnected() = 0; //{}

               virtual void on_IN04_Tick_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::SC02_Tick const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN04_Tick : public ::Nerv::nerv_object_information
        {

        public:

               method_IN04_Tick(int interval= 0) : nerv_object_information(0x1004) {}

               void IN04_Tick_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN04_Tick_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN04_Tick_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN04_Tick_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN04_Tick_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::SC02_Tick* IN04_Tick_get()
               {
                      return (Nerv::Data::Dongguk::SC02_Tick*) get(sizeof(Nerv::Data::Dongguk::SC02_Tick) );
                }

                void IN04_Tick_cancel()
                {
                       cancel();
                }

                nerv_err_t IN04_Tick_post(Nerv::Data::Dongguk::SC02_Tick* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN04_Tick_write(Nerv::Data::Dongguk::SC02_Tick* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN04_Tick_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN04_Tick_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN04_Tick_read( Nerv::Data::Dongguk::SC02_Tick* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC02_Tick);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN04_Tick_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN04_Tick_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN04_Tick_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN04_Tick_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN05_CrashInfo
         Input      : ::
         Output     : Nerv::Data::Dongguk::SC03_CrashInfo
         Method Type: INFORMATION
         Code       : 0x1005
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN05_CrashInfo : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN05_CrashInfo() : nerv_proxy_object_information(0x1005) {}

               bool IN05_CrashInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN05_CrashInfo_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN05_CrashInfo_shutdown() { shutdown(); }

               void IN05_CrashInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN05_CrashInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN05_CrashInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN05_CrashInfo_read( Nerv::Data::Dongguk::SC03_CrashInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC03_CrashInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN05_CrashInfo_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN05_CrashInfo_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::SC03_CrashInfo const* const)pin_buffer );
               }

               virtual void on_IN05_CrashInfo_disconnected() = 0; //{}

               virtual void on_IN05_CrashInfo_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::SC03_CrashInfo const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN05_CrashInfo : public ::Nerv::nerv_object_information
        {

        public:

               method_IN05_CrashInfo(int interval= 0) : nerv_object_information(0x1005) {}

               void IN05_CrashInfo_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN05_CrashInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN05_CrashInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN05_CrashInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN05_CrashInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::SC03_CrashInfo* IN05_CrashInfo_get()
               {
                      return (Nerv::Data::Dongguk::SC03_CrashInfo*) get(sizeof(Nerv::Data::Dongguk::SC03_CrashInfo) );
                }

                void IN05_CrashInfo_cancel()
                {
                       cancel();
                }

                nerv_err_t IN05_CrashInfo_post(Nerv::Data::Dongguk::SC03_CrashInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN05_CrashInfo_write(Nerv::Data::Dongguk::SC03_CrashInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN05_CrashInfo_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN05_CrashInfo_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN05_CrashInfo_read( Nerv::Data::Dongguk::SC03_CrashInfo* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC03_CrashInfo);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN05_CrashInfo_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN05_CrashInfo_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN05_CrashInfo_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN05_CrashInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN06_InterruptAgentsList
         Input      : ::
         Output     : Nerv::Data::Dongguk::IA01_InterruptAgentsList
         Method Type: INFORMATION
         Code       : 0x1006
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN06_InterruptAgentsList : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN06_InterruptAgentsList() : nerv_proxy_object_information(0x1006) {}

               bool IN06_InterruptAgentsList_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN06_InterruptAgentsList_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN06_InterruptAgentsList_shutdown() { shutdown(); }

               void IN06_InterruptAgentsList_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN06_InterruptAgentsList_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN06_InterruptAgentsList_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN06_InterruptAgentsList_read( Nerv::Data::Dongguk::IA01_InterruptAgentsList* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::IA01_InterruptAgentsList);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN06_InterruptAgentsList_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN06_InterruptAgentsList_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::IA01_InterruptAgentsList const* const)pin_buffer );
               }

               virtual void on_IN06_InterruptAgentsList_disconnected() = 0; //{}

               virtual void on_IN06_InterruptAgentsList_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::IA01_InterruptAgentsList const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN06_InterruptAgentsList : public ::Nerv::nerv_object_information
        {

        public:

               method_IN06_InterruptAgentsList(int interval= 0) : nerv_object_information(0x1006) {}

               void IN06_InterruptAgentsList_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN06_InterruptAgentsList_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN06_InterruptAgentsList_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN06_InterruptAgentsList_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN06_InterruptAgentsList_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::IA01_InterruptAgentsList* IN06_InterruptAgentsList_get()
               {
                      return (Nerv::Data::Dongguk::IA01_InterruptAgentsList*) get(sizeof(Nerv::Data::Dongguk::IA01_InterruptAgentsList) );
                }

                void IN06_InterruptAgentsList_cancel()
                {
                       cancel();
                }

                nerv_err_t IN06_InterruptAgentsList_post(Nerv::Data::Dongguk::IA01_InterruptAgentsList* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN06_InterruptAgentsList_write(Nerv::Data::Dongguk::IA01_InterruptAgentsList* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN06_InterruptAgentsList_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN06_InterruptAgentsList_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN06_InterruptAgentsList_read( Nerv::Data::Dongguk::IA01_InterruptAgentsList* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::IA01_InterruptAgentsList);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN06_InterruptAgentsList_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN06_InterruptAgentsList_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN06_InterruptAgentsList_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN06_InterruptAgentsList_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN07_TrafficPatternInfo
         Input      : ::
         Output     : Nerv::Data::Dongguk::SC04_TrafficPatternInfo
         Method Type: INFORMATION
         Code       : 0x1007
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN07_TrafficPatternInfo : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN07_TrafficPatternInfo() : nerv_proxy_object_information(0x1007) {}

               bool IN07_TrafficPatternInfo_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN07_TrafficPatternInfo_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN07_TrafficPatternInfo_shutdown() { shutdown(); }

               void IN07_TrafficPatternInfo_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN07_TrafficPatternInfo_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN07_TrafficPatternInfo_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN07_TrafficPatternInfo_read( Nerv::Data::Dongguk::SC04_TrafficPatternInfo* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC04_TrafficPatternInfo);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN07_TrafficPatternInfo_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN07_TrafficPatternInfo_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::SC04_TrafficPatternInfo const* const)pin_buffer );
               }

               virtual void on_IN07_TrafficPatternInfo_disconnected() = 0; //{}

               virtual void on_IN07_TrafficPatternInfo_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::SC04_TrafficPatternInfo const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN07_TrafficPatternInfo : public ::Nerv::nerv_object_information
        {

        public:

               method_IN07_TrafficPatternInfo(int interval= 0) : nerv_object_information(0x1007) {}

               void IN07_TrafficPatternInfo_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN07_TrafficPatternInfo_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN07_TrafficPatternInfo_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN07_TrafficPatternInfo_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN07_TrafficPatternInfo_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::SC04_TrafficPatternInfo* IN07_TrafficPatternInfo_get()
               {
                      return (Nerv::Data::Dongguk::SC04_TrafficPatternInfo*) get(sizeof(Nerv::Data::Dongguk::SC04_TrafficPatternInfo) );
                }

                void IN07_TrafficPatternInfo_cancel()
                {
                       cancel();
                }

                nerv_err_t IN07_TrafficPatternInfo_post(Nerv::Data::Dongguk::SC04_TrafficPatternInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN07_TrafficPatternInfo_write(Nerv::Data::Dongguk::SC04_TrafficPatternInfo* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN07_TrafficPatternInfo_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN07_TrafficPatternInfo_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN07_TrafficPatternInfo_read( Nerv::Data::Dongguk::SC04_TrafficPatternInfo* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::SC04_TrafficPatternInfo);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN07_TrafficPatternInfo_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN07_TrafficPatternInfo_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN07_TrafficPatternInfo_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN07_TrafficPatternInfo_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };

        /********************************************************************************************************************************************
         Method     : IN08_TopographicEvent
         Input      : ::
         Output     : Nerv::Data::Dongguk::TE01_TopographicEvent
         Method Type: INFORMATION
         Code       : 0x1008
         Writer     : root
         Description: 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_method_IN08_TopographicEvent : public ::Nerv::nerv_proxy_object_information
        {
        public:

               proxy_method_IN08_TopographicEvent() : nerv_proxy_object_information(0x1008) {}

               bool IN08_TopographicEvent_is_connected() { return is_connected(); }

               ::Nerv::nerv_err_t IN08_TopographicEvent_connect( const bool& in_udp_request = true, const double& in_limit_time = 1.0, double* pout_time = 0)
               {
                      return_object_t return_object = async_connect( in_udp_request , in_limit_time );
                      return async_connect_return( return_object, pout_time );
               }

               void IN08_TopographicEvent_shutdown() { shutdown(); }

               void IN08_TopographicEvent_set_sync(const bool& in_use_on_sync) { set_sync(in_use_on_sync); }

               letter_case_t IN08_TopographicEvent_see_history( const size_t& in_size)
               {
                      return see_history( in_size);
               }

               void IN08_TopographicEvent_set_history_size( const size_t& in_history_size)
               {
                      set_history_size( in_history_size);
               }

               nerv_err_t IN08_TopographicEvent_read( Nerv::Data::Dongguk::TE01_TopographicEvent* pin_data)
               {
                      Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::TE01_TopographicEvent);
                      return read(pin_data, &in_size );
               }

        private:

               virtual void on_disconnected()
               {
                      on_IN08_TopographicEvent_disconnected();
               }

               virtual void on_sync( const sender_sync_model_t& in_sync_model,
                                                  const double& in_elapsed,
                                                  const double& in_limit,
                                              void const* const pin_buffer,
                                                 const pksize_t in_size)
               {
                      on_IN08_TopographicEvent_sync(in_sync_model, in_limit, in_elapsed , (Nerv::Data::Dongguk::TE01_TopographicEvent const* const)pin_buffer );
               }

               virtual void on_IN08_TopographicEvent_disconnected() = 0; //{}

               virtual void on_IN08_TopographicEvent_sync( const sender_sync_model_t& in_sync_model,
                                                             const double& in_limit,
                                                             const double& in_elapsed,
                              Nerv::Data::Dongguk::TE01_TopographicEvent const* const pin_buffer ) = 0; //{}
        };

        /* stub */
        class method_IN08_TopographicEvent : public ::Nerv::nerv_object_information
        {

        public:

               method_IN08_TopographicEvent(int interval= 0) : nerv_object_information(0x1008) {}

               void IN08_TopographicEvent_set_sync_model( const sender_sync_model_t& in_sync_model, const double& in_interval)
               {
                      set_sync_model(in_sync_model,in_interval);
               }

               void IN08_TopographicEvent_disconnect( const client_addr_t& in_client_addr )
               {
                      disconnect( in_client_addr );
               }

               void IN08_TopographicEvent_disconnect_all_client_object()
               {
                      disconnect_all_client_object();
               }
               void IN08_TopographicEvent_disconnect_one_client_node( const struct_node_addr& in_node_addr)
               {
                      disconnect_one_client_node( in_node_addr);
               }
               void IN08_TopographicEvent_disconnect_one_client_object( const client_addr_t& in_client_addr)
               {
                      disconnect_one_client_object( in_client_addr);
               }
               Nerv::Data::Dongguk::TE01_TopographicEvent* IN08_TopographicEvent_get()
               {
                      return (Nerv::Data::Dongguk::TE01_TopographicEvent*) get(sizeof(Nerv::Data::Dongguk::TE01_TopographicEvent) );
                }

                void IN08_TopographicEvent_cancel()
                {
                       cancel();
                }

                nerv_err_t IN08_TopographicEvent_post(Nerv::Data::Dongguk::TE01_TopographicEvent* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return post( in_size);
                }

                nerv_err_t IN08_TopographicEvent_write(Nerv::Data::Dongguk::TE01_TopographicEvent* pin_buf)
                {
                       ::Nerv::pksize_t in_size = nerv_sizeof(pin_buf);
                       return write( pin_buf, in_size);
                }

                letter_case_t IN08_TopographicEvent_see_history( const size_t& in_size)
                {
                       return see_history( in_size);
                }

                void IN08_TopographicEvent_set_history_size( const size_t& in_history_size)
                {
                       set_history_size( in_history_size);
                }

                nerv_err_t IN08_TopographicEvent_read( Nerv::Data::Dongguk::TE01_TopographicEvent* pin_data)
                {
                       Nerv::pksize_t in_size = sizeof(Nerv::Data::Dongguk::TE01_TopographicEvent);
                       return read(pin_data, &in_size );
                }

        private:

                virtual nerv_err_t on_connect( const client_addr_t& in_client_addr,
                                                        const bool& in_tcp_request,
                                                     const double& in_elapsed_time,
                                                     const double& in_limit_time )
                {
                       return on_IN08_TopographicEvent_connect( in_client_addr,in_tcp_request,in_elapsed_time,in_limit_time );
                }

                virtual void on_shutdown( const client_addr_t& in_client_addr)
                {
                       on_IN08_TopographicEvent_shutdown(in_client_addr);
                }

                virtual nerv_err_t on_IN08_TopographicEvent_connect( const client_addr_t& in_client_addr,
                                                                   const bool& in_tcp_request,
                                                                const double& in_elapsed_time,
                                                                  const double& in_limit_time ) = 0; //{ return ::Nerv::c_nerv_err_not_implement; }

                virtual void on_IN08_TopographicEvent_shutdown( const client_addr_t& in_client_addr) = 0; //{}

        };


    /* Interface Defines ***************************************************************************************************************************/

        /********************************************************************************************************************************************
         Interface Name : CoretecScenario
         Writer : root
         Description : 
        ********************************************************************************************************************************************/
        /* proxy */
        class proxy_interface_CoretecScenario : virtual public ::Nerv::nerv_proxy_object
        , virtual public CoretecScenario::proxy_method_CO00_MonitoringReady
        , virtual public CoretecScenario::proxy_method_CO01_SpawnInfo
        , virtual public CoretecScenario::proxy_method_CO02_ControlInfo
        , virtual public CoretecScenario::proxy_method_CO03_DeleteObjectInfo
        , virtual public CoretecScenario::proxy_method_CO04_StringInfo
        , virtual public CoretecScenario::proxy_method_IN00_AllAgentsInformation
        , virtual public CoretecScenario::proxy_method_IN01_ScenarioSetting
        , virtual public CoretecScenario::proxy_method_IN02_CustomEventList
        , virtual public CoretecScenario::proxy_method_IN03_ScenarioSignalInfo
        , virtual public CoretecScenario::proxy_method_IN04_Tick
        , virtual public CoretecScenario::proxy_method_IN05_CrashInfo
        , virtual public CoretecScenario::proxy_method_IN06_InterruptAgentsList
        , virtual public CoretecScenario::proxy_method_IN07_TrafficPatternInfo
        , virtual public CoretecScenario::proxy_method_IN08_TopographicEvent
        {
        };

        /* stub */
        class stub_interface_CoretecScenario : virtual public ::Nerv::nerv_object
        , virtual public CoretecScenario::method_CO00_MonitoringReady
        , virtual public CoretecScenario::method_CO01_SpawnInfo
        , virtual public CoretecScenario::method_CO02_ControlInfo
        , virtual public CoretecScenario::method_CO03_DeleteObjectInfo
        , virtual public CoretecScenario::method_CO04_StringInfo
        , virtual public CoretecScenario::method_IN00_AllAgentsInformation
        , virtual public CoretecScenario::method_IN01_ScenarioSetting
        , virtual public CoretecScenario::method_IN02_CustomEventList
        , virtual public CoretecScenario::method_IN03_ScenarioSignalInfo
        , virtual public CoretecScenario::method_IN04_Tick
        , virtual public CoretecScenario::method_IN05_CrashInfo
        , virtual public CoretecScenario::method_IN06_InterruptAgentsList
        , virtual public CoretecScenario::method_IN07_TrafficPatternInfo
        , virtual public CoretecScenario::method_IN08_TopographicEvent
        {
        };



} using namespace CoretecScenario; } using namespace Method; } using namespace Nerv; 

#endif // #ifdef Define__Nerv__Method__CoretecScenario__CoretecScenario_h
