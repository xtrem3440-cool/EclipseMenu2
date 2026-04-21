#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerColorShift) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playercolorshift.toggle", false);
            config::setIfEmpty("player.playercolorshift", 0.f);

            tab->addFloatToggle("player.playercolorshift", -180.f, 180.f, "%.1f")
                ->setDescription("Shifts player color hue")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Color Shift"; }
        [[nodiscard]] int32_t getPriority() const override { return -58; }
    };

    REGISTER_HACK(PlayerColorShift)
}
