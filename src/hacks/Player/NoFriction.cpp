#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(NoFriction) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.nofriction.toggle", false);

            tab->addToggle("player.nofriction")
                ->setDescription("Remove friction from player movement")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Friction"; }
        [[nodiscard]] int32_t getPriority() const override { return -48; }
    };

    REGISTER_HACK(NoFriction)
}
