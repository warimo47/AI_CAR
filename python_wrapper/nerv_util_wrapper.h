#pragma once

#include <Nerv/nerv_typedef.h>
using namespace Nerv;

class nerv_util_wrapper
{
public:
	static void nerv_init();
	static void nerv_finalize();
	static void nerv_dispatch_msg(double in_timeout);
	static ip_t nerv_inet_addr(const char_t* str_ip);
};