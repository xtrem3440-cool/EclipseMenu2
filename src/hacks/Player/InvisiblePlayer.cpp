#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(InvisiblePlayer) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.invisibleplayer.toggle", false);

            tab->addToggle("player.invisibleplayer")
                ->setDescription("Make player invisible")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Invisible Player"; }
        [[nodiscard]] int32_t getPriority() const override { return -42; }
    };

    REGISTER_HACK(InvisiblePlayer)
}
