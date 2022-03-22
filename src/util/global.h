#pragma once

#include "../common.h"

struct Cfg {
    bool verbose = false;
    int port = 443; // 443 to be used to avoid detection.
};

struct NetInfo {
    std::string host;
};

namespace global {
    inline Cfg config = {};
    inline NetInfo netInfo = {};

    void init();

    inline const char* banner[] = {
            " ________              __     ___ ___ ______ _______   \n"
            "|  |  |  |.---.-.----.|  |--.|   |   |   __ \\    |  | \n"
            "|  |  |  ||  _  |  __||    < |   |   |    __/       |  \n"
            "|________||___._|____||__|__| \\_____/|___|  |__|____| \n"
            "=====================================================  \n"
    };
    inline const char* usage[] = {
            "Usage: wackvpn [options]\n"
            "Options:\n"
            "  -h, --help                   Print this help message.\n"
            "  --version                    Print the version of WackVPN.\n"
            "  -p, --port=<port>            Set the port to listen on.\n"
            "  -v, --verbose                Enable verbose mode.\n"
    };
}