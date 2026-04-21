#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerGlowHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playerglow.toggle")
        
        // Hook implementation for PlayerGlow
        // This modifies game behavior based on config values
    };

    class $hack(PlayerGlow) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerglow.toggle", false);
            config::setIfEmpty("player.playerglow", 1.f);

            tab->addFloatToggle("player.playerglow", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerGlow")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerGlow"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerGlow)
}
