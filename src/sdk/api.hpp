#pragma once

#include <Windows.h>
#include <cinttypes>

#include "game_define.hpp"

namespace sdk {
    namespace raw {

#define Api(ReturnType, FuncName, ...) extern ReturnType(__stdcall* FuncName)(__VA_ARGS__);
#include "api_funcs.inc"
#undef Api

}

void init_api() noexcept(false);

}
