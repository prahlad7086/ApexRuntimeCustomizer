#include "PlayerModule.h"
#include "../Core/Configuration.h"
#include "../Utilities/Logger.h"
// #include "../GameData/GameDefinitions.h" // For game data interaction

namespace Modules {
    namespace Player {
        void UpdateState() {
            if (Config::bEnableEnhancedResilience) {
                // GameDefinitions::ApplyResilienceBoost(); // Dummy call
            }
            if (Config::bEnableOptimizedAmmunition) {
                // GameDefinitions::ApplyAmmoOptimization();
            }
        }

        void SetResilience(bool enable) {
            Config::bEnableEnhancedResilience = enable;
            Logger::Log(std::string("Player Resilience: ") + (enable ? "Enabled" : "Disabled"));
        }
        void SetAmmunitionOptimization(bool enable) {
            Config::bEnableOptimizedAmmunition = enable;
            Logger::Log(std::string("Optimized Ammunition: ") + (enable ? "Enabled" : "Disabled"));
        }
    }
}
