#pragma once
#include <windows.h>
#include <vector>
#include <string>

// Utility functions for memory operations
namespace MemoryOperations {
    // Read a value from a specified memory address
    template<typename T>
    T ReadMemory(uintptr_t address) {
        // Dummy implementation
        return T(); 
    }

    // Write a value to a specified memory address
    template<typename T>
    void WriteMemory(uintptr_t address, T value) {
        // Dummy implementation
    }

    // Scan for a byte pattern in memory
    bool ScanPattern(const std::string& pattern, uintptr_t* outAddress);
}
