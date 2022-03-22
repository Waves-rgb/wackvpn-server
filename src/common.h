#pragma once

/*-----------------------------------------------------------*\
|     ________              __     ___ ___ ______ _______     |
|    |  |  |  |.---.-.----.|  |--.|   |   |   __ \    |  |    |
|    |  |  |  ||  _  |  __||    < |   |   |    __/       |    |
|    |________||___._|____||__|__| \_____/|___|  |__|____|    |
|                                                             |
|            Waves-rgb/WackVPN - A shitty FOSS VPN            |
|  This project is made possible by the following libraries:  |
|     - fmt                                                   |
\*-----------------------------------------------------------*/

// Linux specific headers.
#ifdef  __linux__
    #warning "Project is not supported on Linux. You're on your own. Good luck. Report any bugs to https://github.com/Waves-rgb/WackVPN/issues"
#endif

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <thread>
#include <mutex>

#include "util/util.h"
#include "util/global.h"

using std::string, std::map, std::vector, std::function;

// Windows specific headers.
#ifdef _WIN32
    #include <windows.h>

    // Include WinSock api (for networking).
    #pragma comment(lib , "Ws2_32.lib")
    #include <winsock.h>
#endif

#define WACKVPN_VERSION "0.1.0"