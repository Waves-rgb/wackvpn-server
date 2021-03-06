#include "common.h"
#include "util/util.h"

int main(int argc, char** argv) {
    // Parse the given arguments
    util::parseArgs(argc, argv);

    // Print banner
    for (auto line : global::banner)
        fmt::print("{}", line);

    // Initialize the global variables
    global::init();

    fmt::print("WackVPN Starting on {}:{}\n", global::netInfo.host.c_str(), global::config.port);



    return 0;
}
