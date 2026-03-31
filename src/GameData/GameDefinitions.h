#pragma once
#include <windows.h> // Include standard Windows headers

// This file would contain declarations for game-specific data structures and access methods
// Example:
namespace GameDefinitions {
    // Initialize all necessary data offsets and pointers for game interaction
    bool LoadDataOffsets();

    // Player related data access
    void ApplyResilienceBoost();
    void ApplyArmorEnhancement();
    void ApplyAmmoOptimization();

    // Vehicle related data access
    void RequestVehicleModel(DWORD modelHash);
    void InstantiateVehicle(DWORD modelHash, float x, float y, float z, float heading);
    void ApplyVehicleDurability(int durabilityValue);

    // World state manipulation
    void AdjustWeather(int weatherType);
    void SetGameTime(int hour, int minute, int second);
}
