#ifndef ABOAWT_CORE_H
#define ABOAWT_CORE_H

#include <Application/Definitions.h>

#include <string>
#include <map>

namespace Application::Core {

    /*
     * Followed by https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods
     */
    enum NetworkRequestMode {
        GET = 0,
        HEAD = 1,
        POST = 2,
        PUT = 3,
        DELETE = 4,
        CONNECT = 5,
        OPTIONS = 6,
        TRACE = 7,
        PATCH = 8
    };

    char* NetworkRequest(std::string url, NetworkRequestMode mode, std::map<std::string, std::string> headers);

    void ExecuteAction(ActionType type);

}

#endif //ABOAWT_CORE_H
