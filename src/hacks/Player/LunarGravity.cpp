#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(LunarGravity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.lunargravity.toggle", false);

            tab->addToggle("player.lunargravity")
                ->setDescription("Reduce gravity to lunar levels")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Lunar Gravity"; }
        [[nodiscard]] int32_t getPriority() const override { return -50; }
    };

    REGISTER_HACK(LunarGravity)
}
