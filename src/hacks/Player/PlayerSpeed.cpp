#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerspeed.toggle", false);
            config::setIfEmpty("player.playerspeed", 1.f);

            tab->addFloatToggle("player.playerspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts player movement speed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -51; }
    };

    REGISTER_HACK(PlayerSpeed)
}
