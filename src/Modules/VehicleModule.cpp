#include "VehicleModule.h"
#include "../Core/Configuration.h"
#include "../Utilities/Logger.h"
// #include "../GameData/GameDefinitions.h" // For game data interaction

namespace Modules {
    namespace Vehicle {
        void UpdateState() {
            if (Config::bEnableVehicleDurability) {
                // GameDefinitions::ApplyVehicleDurability(); // Dummy call
            }
        }

        void ProvisionVehicle(int modelHash) {
            Logger::Log("Vehicle: Requesting model " + std::to_string(modelHash));
            // GameDefinitions::RequestVehicleModel(modelHash);
            // GameDefinitions::InstantiateVehicle(modelHash, ...);
        }

        void SetDurability(bool enable) {
            Config::bEnableVehicleDurability = enable;
            Logger::Log(std::string("Vehicle Durability: ") + (enable ? "Enabled" : "Disabled"));
        }
    }
}
