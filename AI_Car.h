
#ifdef _PYTHON

#include <boost/python.hpp>
namespace py = boost::python;

// nerv const
#include "python_wrapper/nerv_const.h"

// nerv util
#include "python_wrapper/nerv_util_wrapper.h"

// boost python wrapper
#include "python_wrapper/export_data_Coretec_Scenario.h"
#include "python_wrapper/export_proxy_Coretec_Scenario.h"


BOOST_PYTHON_MODULE(AI_CORETEC_IF)
{
    // constant	
    py::class_<nerv_const>("const")
        .def_readonly("c_AI_port", &nerv_const::c_AI_port)
        ;

    //////////////////////////////////////////////////////////////////
    // structure

    // wrapper 없이 직접 export가 가능한 struct의 경우 py::class_<>().def_readwrite("멤버", ...) 형태로 export
    // wrapper 작성 시 get/set 함수를 py::class_<>().add_property("멤버", getter, setter) 형태로 export 한다 (주로 char* or char[])
    // add_property 를 위해 작성한 get/set 함수는 각 리턴값/인자값에 const를 반드시 명시해야 컴파일 에러가 발생하지 않는다
    // struct 배열의 경우 get/set 함수를 별도로 작성 .def("get_x", &a_wrapper::get_x) 형태로 export
    
    // add_propert / def 여부는 char* 처럼 인덱싱이 필요없이 포인터를 get/set 하는 경우 add_property 사용
    // index 를 이용해 배열의 특정 값을 get/set 하는 경우 일일히 def 로 get/set 함수를 export 시킨다

    py::class_<Nerv::client_addr_t>("client_addr_t")
        .def_readwrite("node_addr", &Nerv::client_addr_t::node_addr)
        .def_readwrite("obj_id", &Nerv::client_addr_t::obj_id)
        ;
        
    // nerv util
    py::def("initialize", &nerv_util_wrapper::nerv_init);
    py::def("finalize", &nerv_util_wrapper::nerv_finalize);
    py::def("dispatch_msg", &nerv_util_wrapper::nerv_dispatch_msg);
    py::def("inet_addr", &nerv_util_wrapper::nerv_inet_addr);

    // Nerv::Data::Coretec
    export_data_Coretec();

    // Nerv::Data::Dongguk
    export_data_Dongguk();
    
    // Proxy AICoretec
	export_proxy_coretec_scenario();
}

#else

#ifdef AI_CORETEC_EXPORTS
#define AI_CORETEC_IF_API __declspec(dllexport)
#else
#define AI_CORETEC_IF_API __declspec(dllimport)
#endif

AI_CORETEC_IF_API int ai_coretec_if(int argc, char* argv[]);

#endif // _PYTHON