#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(BouncyPlayerMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.bouncyplayermode.toggle", false);

            tab->addToggle("player.bouncyplayermode")
                ->setDescription("Bounce around the level")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Bouncy Player Mode"; }
        [[nodiscard]] int32_t getPriority() const override { return -64; }
    };

    REGISTER_HACK(BouncyPlayerMode)
}
