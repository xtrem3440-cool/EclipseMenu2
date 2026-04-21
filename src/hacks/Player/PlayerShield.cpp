#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerShield) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playershield.toggle", false);

            tab->addToggle("player.playershield")
                ->setDescription("Add protective shield to player")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Shield"; }
        [[nodiscard]] int32_t getPriority() const override { return -62; }
    };

    REGISTER_HACK(PlayerShield)
}
