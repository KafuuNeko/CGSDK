#include "event.hpp"

#include <stdint.h>
#include <utility>
#include <inttypes.h>

template<class _Cont, class... _Args>
void call_all(const _Cont &callbacks, _Args &&... args)
{
    for(auto & callback : callbacks)
    {
        if(callback)
            callback(std::forward<_Args>(args)...);
    }
}

CG_EVENT(int32_t, _AuthCode, 4)(int32_t AuthCode)
{
    call_all(sdk::_auth_code_callbacks(), AuthCode);
    return 0;
}

CG_EVENT(const char *, _info_ext, 0)()
{
    ext_create();
	return ext_info();
}

CG_EVENT(const char *, _info_function, 0)()
{
	return ext_function_info();
}

CG_EVENT(void, _ext_event_start, 0)()
{
    call_all(sdk::_ext_event_start_callbacks());
}

CG_EVENT(void, _ext_close, 0)()
{
	call_all(sdk::_ext_close_callbacks());
}

CG_EVENT(const char *, _ext_event_ReceivedMsg, 16)(const char *type, const char *fromQQ, const char *fromGroup, const char *msg)
{
    auto event = sdk::ReceiveMessage {type, fromQQ, fromGroup, msg, ""};
    call_all(sdk::_ext_event_received_callbacks(), event);
    return event.returnMessage;
}
