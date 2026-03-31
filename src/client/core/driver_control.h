#pragma once
#include <windows.h>

namespace Driver {
    bool Initialize();
    void Shutdown();
    bool ReadMemory(uintptr_t address, void* buffer, size_t size);
}
