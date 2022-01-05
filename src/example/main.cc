//
// Created by kafuu on 2022/1/4.
//
#include "sdk/include/sdk.hpp"

EXT_INFO("17", "Example", "1.0", "Kafuu", R"(菜單演示1,_menu_first|菜單演示2,_menu_second)")

EXT_FUNCTION(R"({
                "SDK信息處理演示1":"SDK1|_sdk_demo1",
                "SDK信息處理演示2":"SDK2|_sdk_demo2"
})")

EXT_INIT
{
    sdk::bind_auth_code([](int32_t authCode){
        //sdk::raw::CG_addLog_Debug("SDK Example", "bind_auth_code0");
    });

    sdk::bind_ext_event_start([](){
        sdk::raw::CG_addLog_Debug("SDK Example", "bind_ext_event_start");
    });

    sdk::bind_ext_close([](){
        sdk::raw::CG_addLog_Debug("SDK Example", "bind_ext_close");
    });

    sdk::bind_ext_event_received([](const sdk::ReceiveMessage &message){
        sdk::raw::CG_addLog_Debug("SDK Example", message.msg);
    });
}

CG_MENU(_menu_first)
{
    sdk::raw::CG_addLog_Debug("菜單點擊事件", "菜單1被用戶點擊");
}

CG_MENU(_menu_second)
{
    sdk::raw::CG_addLog_Debug("菜單點擊事件", "菜單2被用戶點擊");
}

CG_FUNCTION_CALLBACK(_sdk_demo1)
{
    return "SDK信息回調1";
}

CG_FUNCTION_CALLBACK(_sdk_demo2)
{
    return "SDK信息回調2";
}
