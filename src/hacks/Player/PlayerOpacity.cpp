#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playeropacity.toggle", false);
            config::setIfEmpty("player.playeropacity", 1.f);

            tab->addFloatToggle("player.playeropacity", 0.0f, 1.0f, "%.2f")
                ->setDescription("Adjusts player transparency")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Opacity"; }
        [[nodiscard]] int32_t getPriority() const override { return -45; }
    };

    REGISTER_HACK(PlayerOpacity)
}
