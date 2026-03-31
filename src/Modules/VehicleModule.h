#pragma once
namespace Modules {
    namespace Vehicle {
        void UpdateState(); // Applies vehicle-related modifications
        void ProvisionVehicle(int modelHash);
        void SetDurability(bool enable);
    }
}
