#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(ShipcopterHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.shipcopter.toggle")
        
        // Hook implementation for Shipcopter
        // This modifies game behavior based on config values
    };

    class $hack(Shipcopter) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.shipcopter.toggle", false);
            config::setIfEmpty("player.shipcopter", 1.f);

            tab->addFloatToggle("player.shipcopter", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies Shipcopter")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Shipcopter"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(Shipcopter)
}
