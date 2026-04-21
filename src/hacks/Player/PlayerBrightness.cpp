#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerbrightness.toggle", false);
            config::setIfEmpty("player.playerbrightness", 1.f);

            tab->addFloatToggle("player.playerbrightness", 0.1f, 2.0f, "%.2f")
                ->setDescription("Adjusts player brightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Brightness"; }
        [[nodiscard]] int32_t getPriority() const override { return -63; }
    };

    REGISTER_HACK(PlayerBrightness)
}
