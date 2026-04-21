#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(SuperSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.superspeed.toggle", false);

            tab->addToggle("player.superspeed")
                ->setDescription("Infinite running speed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Super Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -55; }
    };

    REGISTER_HACK(SuperSpeed)
}
