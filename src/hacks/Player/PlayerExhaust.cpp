#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerExhaust) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerexhaust.toggle", false);
            config::setIfEmpty("player.playerexhaust", 1.f);

            tab->addFloatToggle("player.playerexhaust", 0.0f, 5.0f, "%.2f")
                ->setDescription("Scales exhaust particle trail")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Exhaust Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -65; }
    };

    REGISTER_HACK(PlayerExhaust)
}
