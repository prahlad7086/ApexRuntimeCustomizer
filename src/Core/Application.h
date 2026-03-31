#pragma once
#include <windows.h>

namespace Application {
    // Initialize core components like injection hooks, overlay, etc.
    bool Initialize();
    // Main loop for rendering and processing inputs
    void Run();
    // Shutdown and cleanup resources
    void Shutdown();
    // Check if the application is currently active
    bool IsRunning();
}
