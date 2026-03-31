#pragma once
#include <d3d11.h>

namespace D3D11Hook {
    bool Initialize();
    void Shutdown();
    ID3D11Device* GetDevice();
    ID3D11DeviceContext* GetDeviceContext();
}
