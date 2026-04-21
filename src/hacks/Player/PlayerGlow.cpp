#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerGlow) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerglow.toggle", false);

            tab->addToggle("player.playerglow")
                ->setDescription("Add glow effect to player")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Glow"; }
        [[nodiscard]] int32_t getPriority() const override { return -53; }
    };

    REGISTER_HACK(PlayerGlow)
}
