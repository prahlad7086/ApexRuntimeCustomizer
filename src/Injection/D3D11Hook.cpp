#include "D3D11Hook.h"
#include "../Utilities/Logger.h"
#include "../../vendor/kiero/kiero.h" // For hooking
#include "../../vendor/kiero/minhook/MinHook.h" // For hooking library

typedef HRESULT(__stdcall* D3D11PresentHook)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef void(__stdcall* D3D11ResizeBuffersHook)(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

static D3D11PresentHook  oD3D11Present = nullptr;
static D3D11ResizeBuffersHook oD3D11ResizeBuffers = nullptr;

static ID3D11Device* g_pd3dDevice = nullptr;
static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
static IDXGISwapChain* g_pSwapChain = nullptr;

HRESULT __stdcall hkD3D11Present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    if (!g_pd3dDevice) {
        pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&g_pd3dDevice);
        g_pd3dDevice->GetImmediateContext(&g_pd3dDeviceContext);
        g_pSwapChain = pSwapChain;
        Logger::Log("D3D11 Hook: Identified D3D11 Device and Context.");
        OverlayRenderer::Initialize(g_pd3dDevice, g_pd3dDeviceContext); // Initialize GUI after device is found
    }
    // Call GUI render function here
    // OverlayRenderer::Render();
    return oD3D11Present(pSwapChain, SyncInterval, Flags);
}

void __stdcall hkD3D11ResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
    // Handle resizing
    // OverlayRenderer::HandleResize(pSwapChain);
    oD3D11ResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}


namespace D3D11Hook {
    bool Initialize() {
        Logger::Log("D3D11 Hook: Initializing Kiero library...");
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            Logger::Log("D3D11 Hook: Kiero loaded. Attempting to integrate with Present and ResizeBuffers...");
            // Indices vary by game, these are common but might need adjustment
            kiero::bind(8, (void**)&oD3D11Present, hkD3D11Present); // Present
            kiero::bind(13, (void**)&oD3D11ResizeBuffers, hkD3D11ResizeBuffers); // ResizeBuffers
            Logger::Log("D3D11 Hook: Present and ResizeBuffers integration points established.");
            return true;
        }
        Logger::LogError("D3D11 Hook: Kiero initialization failed!");
        return false;
    }

    void Shutdown() {
        Logger::Log("D3D11 Hook: Deactivating D3D11 integration...");
        kiero::shutdown();
        if (g_pd3dDeviceContext) g_pd3dDeviceContext->Release();
        if (g_pd3dDevice) g_pd3dDevice->Release();
        Logger::Log("D3D11 Hook: D3D11 integration successfully terminated.");
    }

    ID3D11Device* GetDevice() {
        return g_pd3dDevice;
    }

    ID3D11DeviceContext* GetDeviceContext() {
        return g_pd3dDeviceContext;
    }
}
