
#include "nerv_util_wrapper.h"

#include <Nerv/nerv_utility.h>

void nerv_util_wrapper::nerv_init()
{
	Nerv::initialize(0, 16, 1);
}

void nerv_util_wrapper::nerv_finalize()
{
	Nerv::finalize();
}

void nerv_util_wrapper::nerv_dispatch_msg(double in_timeout)
{
	Nerv::dispatch_message(in_timeout);
}

Nerv::ip_t nerv_util_wrapper::nerv_inet_addr(const char_t * str_ip)
{
	return Nerv::inet_addr(str_ip);
}