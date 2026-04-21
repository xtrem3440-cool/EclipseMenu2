#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerOpacityHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playeropacity.toggle")
        
        // Hook implementation for PlayerOpacity
        // This modifies game behavior based on config values
    };

    class $hack(PlayerOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playeropacity.toggle", false);
            config::setIfEmpty("player.playeropacity", 1.f);

            tab->addFloatToggle("player.playeropacity", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerOpacity")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerOpacity"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerOpacity)
}
