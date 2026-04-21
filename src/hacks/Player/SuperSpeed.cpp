#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(SuperSpeedHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.superspeed.toggle")
        
        // Hook implementation for SuperSpeed
        // This modifies game behavior based on config values
    };

    class $hack(SuperSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.superspeed.toggle", false);
            config::setIfEmpty("player.superspeed", 1.f);

            tab->addFloatToggle("player.superspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies SuperSpeed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "SuperSpeed"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(SuperSpeed)
}
