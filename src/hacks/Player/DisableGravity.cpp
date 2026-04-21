#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(DisableGravity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.disablegravity.toggle", false);

            tab->addToggle("player.disablegravity")
                ->setDescription("Disable gravity completely")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Gravity"; }
        [[nodiscard]] int32_t getPriority() const override { return -52; }
    };

    REGISTER_HACK(DisableGravity)
}
