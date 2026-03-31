#include <Windows.h>
#include <iostream>
#include "Core/Application.h"
#include "Utilities/Logger.h"

// Entry point for the external game customizer application
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Attach a console for debugging purposes during development
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    Logger::Log("ApexRuntimeCustomizer: Initializing application...");

    if (Application::Initialize()) {
        Logger::Log("ApexRuntimeCustomizer: Core modules loaded. Awaiting game process...");
        // Main application loop would be here, handling render and input
        while (Application::IsRunning()) {
            Sleep(10); // Reduce CPU usage to prevent system strain
        }
    } else {
        Logger::LogError("ApexRuntimeCustomizer: Application initialization failed!");
    }

    Application::Shutdown();
    fclose(f);
    FreeConsole();
    return 0;
}
