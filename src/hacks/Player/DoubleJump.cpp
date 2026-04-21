#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(DoubleJump) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.doublejump.toggle", false);

            tab->addToggle("player.doublejump")
                ->setDescription("Enable double jump in air")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Double Jump"; }
        [[nodiscard]] int32_t getPriority() const override { return -56; }
    };

    REGISTER_HACK(DoubleJump)
}
