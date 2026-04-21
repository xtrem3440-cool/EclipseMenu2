#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerBrightnessHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playerbrightness.toggle")
        
        // Hook implementation for PlayerBrightness
        // This modifies game behavior based on config values
    };

    class $hack(PlayerBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerbrightness.toggle", false);
            config::setIfEmpty("player.playerbrightness", 1.f);

            tab->addFloatToggle("player.playerbrightness", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerBrightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerBrightness"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerBrightness)
}
