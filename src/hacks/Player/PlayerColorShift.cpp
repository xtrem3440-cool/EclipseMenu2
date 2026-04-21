#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerColorShiftHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playercolorshift.toggle")
        
        // Hook implementation for PlayerColorShift
        // This modifies game behavior based on config values
    };

    class $hack(PlayerColorShift) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playercolorshift.toggle", false);
            config::setIfEmpty("player.playercolorshift", 1.f);

            tab->addFloatToggle("player.playercolorshift", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerColorShift")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerColorShift"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerColorShift)
}
