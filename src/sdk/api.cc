#include "api.hpp"

namespace sdk {

namespace raw {

#define Api(ReturnType, FuncName, ...) ReturnType(__stdcall* FuncName)(__VA_ARGS__);
#include "api_funcs.inc"
#undef Api

}

void init_api() noexcept(false)
    {
        const auto dll = GetModuleHandleW(L"bin/cgapi.dll");
#define Api(ReturnType, FuncName, ...) raw::FuncName = reinterpret_cast<decltype(raw::FuncName)>(GetProcAddress(dll, #FuncName));
#include "api_funcs.inc"
#undef Api
    }

}
