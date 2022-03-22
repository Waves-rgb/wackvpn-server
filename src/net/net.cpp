#pragma once

#include "net.h"

string net::getIpAddress() {
#ifdef _WIN32
    string ipAddress;
    char hostname[256];

    if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
        WSACleanup();
        return "";
    }

    hostent* host = gethostbyname(hostname);
    if (host == nullptr) {
        WSACleanup();
        return "";
    }

    for (int i = 0; host->h_addr_list[i] != nullptr; i++) {
        in_addr addr{};
        memcpy(&addr, host->h_addr_list[i], sizeof(in_addr));
        ipAddress = inet_ntoa(addr);
    }

    WSACleanup();
    return ipAddress;
#elif __linux__
    struct ifaddrs *ifAddrStruct = NULL;
    struct ifaddrs *ifa = NULL;
    void *tmpAddrPtr = NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            if (strcmp(ifa->ifa_name, "en0") == 0) {
                freeifaddrs(ifAddrStruct);
                return string(addressBuffer);
            }
        }
    }
#endif
}

void net::init() {
#ifdef _WIN32
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);
    if (WSAStartup(wVersionRequested, &wsaData) != 0) {
        return;
    }
#endif
}
