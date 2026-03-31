#include <windows.h>
#include "core/driver_control.h"
#include "utils/logger.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    
    Logger::Log("OperatorInsight Client Initializing...");
    
    if (!Driver::Initialize()) {
        Logger::LogError("Exiting: Driver connection failed.");
        return 1;
    }

    // Main application loop
    Logger::Log("Running main application loop...");
    while (true) {
        // Render loop, feature updates, etc.
        Sleep(100);
    }
    
    Driver::Shutdown();
    return 0;
}
