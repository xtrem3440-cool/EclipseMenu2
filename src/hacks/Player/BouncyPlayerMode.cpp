#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(BouncyPlayerModeHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.bouncyplayermode.toggle")
        
        // Hook implementation for BouncyPlayerMode
        // This modifies game behavior based on config values
    };

    class $hack(BouncyPlayerMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.bouncyplayermode.toggle", false);
            config::setIfEmpty("player.bouncyplayermode", 1.f);

            tab->addFloatToggle("player.bouncyplayermode", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies BouncyPlayerMode")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "BouncyPlayerMode"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(BouncyPlayerMode)
}
