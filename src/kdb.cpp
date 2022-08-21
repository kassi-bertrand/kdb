#include "debugger.h"

void kdb::Debugger::handle_command(const std::string &line) {}

void kdb::Debugger::continue_execution() {}

bool kdb::Debugger::is_prefix(const std::string &s, const std::string &of) {}

std::vector<std::string> kdb::Debugger::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens {};
    std::stringstream ss {s};
    std::string token;
    while (std::getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

void kdb::Debugger::run() {}