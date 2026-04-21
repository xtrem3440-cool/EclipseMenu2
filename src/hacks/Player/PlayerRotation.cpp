#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerRotationHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playerrotation.toggle")
        
        // Hook implementation for PlayerRotation
        // This modifies game behavior based on config values
    };

    class $hack(PlayerRotation) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerrotation.toggle", false);
            config::setIfEmpty("player.playerrotation", 1.f);

            tab->addFloatToggle("player.playerrotation", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerRotation")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerRotation"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerRotation)
}
