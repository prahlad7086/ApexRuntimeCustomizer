#pragma once
#include <d3d11.h>

namespace OverlayRenderer {
    // Initialize ImGui context and renderer
    void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
    // Render the main user interface
    void Render();
    // Shutdown ImGui context and cleanup
    void Shutdown();
}
