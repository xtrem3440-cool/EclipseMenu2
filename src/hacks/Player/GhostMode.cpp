#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(GhostModeHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.ghostmode.toggle")
        
        // Hook implementation for GhostMode
        // This modifies game behavior based on config values
    };

    class $hack(GhostMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.ghostmode.toggle", false);
            config::setIfEmpty("player.ghostmode", 1.f);

            tab->addFloatToggle("player.ghostmode", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies GhostMode")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "GhostMode"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(GhostMode)
}
