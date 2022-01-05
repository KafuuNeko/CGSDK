#pragma once

#include <cinttypes>
#include <vector>
#include <functional>

#define DEF_EVENT(EventName, EventType)                                             \
    inline auto &_##EventName##_callbacks() {                                       \
        static std::vector<std::function<void(EventType)>> EventName##callbacks;    \
        return EventName##callbacks;                                                \
    }                                                                               \
    inline void bind_##EventName(const std::function<void(EventType)> &cb) {        \
        _##EventName##_callbacks().push_back(cb);                                   \
    }

namespace sdk {
    struct ReceiveMessage {
        const char *type; const char *fromQQ; const char *fromGroup; const char *msg;
        const char *returnMessage;
    };

DEF_EVENT(auth_code, int32_t);
DEF_EVENT(ext_event_start, void);
DEF_EVENT(ext_close, void);
DEF_EVENT(ext_event_received, const ReceiveMessage &message);

}

#undef DEF_EVENT

