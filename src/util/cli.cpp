#include "cli.h"
#include "../common.h"
#include "global.h"

const map<vector<string>, function<void(string)>> args = {
        {{"-h", "--help"}, [](const string& arg) {
            for (const auto line : global::usage) printf("%s\n", line);
            exit(0);
        }},
        {{"--version"}, [](const string& arg) {
            fmt::print("WackVPN@v{} - Compiled: {}\n", WACKVPN_VERSION, __DATE__);
            exit(0);
        }},
        {{"-v", "--verbose"}, [](const string& arg) {
            fmt::print("Verbose mode enabled\n");
            global::config.verbose = true;
        }}
};

void util::parseArgs(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {
        const auto arg = string(argv[i]);

        if (arg.find('-') == string::npos) continue;

        for (const auto &[key, value] : args)
            if (std::find(key.begin(), key.end(), arg) != key.end()) {
                value(arg);
                break;
            }
    }
}