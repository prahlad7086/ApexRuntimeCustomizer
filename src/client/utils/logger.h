#pragma once
#include <string>
#include <iostream>

namespace Logger {
    inline void Log(const std::string& message) {
        std::cout << "[Insight] " << message << std::endl;
    }
    inline void LogError(const std::string& message) {
        std::cerr << "[Insight ERROR] " << message << std::endl;
    }
}
