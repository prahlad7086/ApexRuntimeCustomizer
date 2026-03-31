#pragma once
#include <string>
#include <iostream>

namespace Logger {
    inline void Log(const std::string& message) {
        std::cout << "[ApexRuntimeCustomizer] " << message << std::endl;
    }
    inline void LogError(const std::string& message) {
        std::cerr << "[ApexRuntimeCustomizer ERROR] " << message << std::endl;
    }
}
