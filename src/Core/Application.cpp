#include "Application.h"
#include "../Interface/OverlayRenderer.h"
#include "../Injection/D3D11Hook.h"
#include "../Utilities/Logger.h"
#include "../GameData/GameDefinitions.h" // Placeholder for game specific data

namespace Application {
    bool g_isRunning = true;

    bool Initialize() {
        Logger::Log("Core: Initiating D3D11 Hook for overlay integration...");
        if (!D3D11Hook::Initialize()) {
            Logger::LogError("Core: Failed to initialize D3D11 Hook!");
            return false;
        }

        Logger::Log("Core: Configuring user interface renderer...");
        OverlayRenderer::Initialize(D3D11Hook::GetDevice(), D3D11Hook::GetDeviceContext());

        // Placeholder for game data initialization, e.g., structure definitions
        // GameDefinitions::LoadOffsets();

        Logger::Log("Core: All core components successfully initialized.");
        return true;
    }

    void Run() {
        // This loop would orchestrate GUI rendering and module updates
        while (g_isRunning) {
            OverlayRenderer::Render();
            // Update active modules
            Sleep(1);
        }
    }

    void Shutdown() {
        Logger::Log("Core: Commencing application shutdown sequence...");
        OverlayRenderer::Shutdown();
        D3D11Hook::Shutdown();
        Logger::Log("Core: Application shutdown complete.");
    }

    bool IsRunning() {
        return g_isRunning;
    }
}
