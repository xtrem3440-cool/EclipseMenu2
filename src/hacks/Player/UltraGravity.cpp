#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(UltraGravity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.ultragravity.toggle", false);

            tab->addToggle("player.ultragravity")
                ->setDescription("Increase gravity significantly")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Ultra Gravity"; }
        [[nodiscard]] int32_t getPriority() const override { return -49; }
    };

    REGISTER_HACK(UltraGravity)
}
