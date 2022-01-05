#pragma once
#include "api.hpp"
#include "event_callback.hpp"
#include "def_export_event.hpp"

#include <cstdio>

void ext_create();
const char * ext_info();
const char * ext_function_info();

#define EXT_INIT    void ext_init();\
                    void ext_create() { sdk::init_api(); ext_init(); }\
                    void ext_init()

#define EXT_INFO(apiVersion, ext_name, ext_ver, author, function) const char * ext_info() { \
    constexpr size_t buffer_size = 1024;\
    static char info[buffer_size];\
    sprintf_s(info, buffer_size, R"({"apiVersion":"%s", "ext_name":"%s", "ext_ver":"%s", "author":"%s", "function":"%s", "Event_Start":"_ext_event_start", "Event_ReceivedMsg":"_ext_event_ReceivedMsg"})", apiVersion, ext_name, ext_ver, author, function);\
    return info;\
}

#define EXT_FUNCTION(FunctionInfo) const char * ext_function_info() { return FunctionInfo; }

#define CG_MENU(MenuName) CG_EVENT(void, MenuName, 0)()
#define CG_FUNCTION_CALLBACK(FunctionName) CG_EVENT(const char*, FunctionName, 16)(const char *receiveMsg, const char *messageType, const char *fromGroup, const char *fromUser)

