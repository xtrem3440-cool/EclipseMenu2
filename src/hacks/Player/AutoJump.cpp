#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(AutoJump) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.autojump.toggle", false);

            tab->addToggle("player.autojump")
                ->setDescription("Automatic jumping")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Auto Jump"; }
        [[nodiscard]] int32_t getPriority() const override { return -61; }
    };

    REGISTER_HACK(AutoJump)
}
