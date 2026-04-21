#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(SpawnProtectionHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.spawnprotection.toggle")
        
        // Hook implementation for SpawnProtection
        // This modifies game behavior based on config values
    };

    class $hack(SpawnProtection) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.spawnprotection.toggle", false);
            config::setIfEmpty("player.spawnprotection", 1.f);

            tab->addFloatToggle("player.spawnprotection", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies SpawnProtection")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "SpawnProtection"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(SpawnProtection)
}
