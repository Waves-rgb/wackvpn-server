#include "global.h"

#include "../net/net.h"

void global::init() {
    net::init();

    if (netInfo.host = net::getIpAddress(); netInfo.host.empty()){
        fmt::print("Failed to get IP address! defaulting to 127.0.0.1\n");
        netInfo.host = "127.0.0.1";
    }
}