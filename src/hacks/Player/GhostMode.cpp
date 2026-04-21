#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(GhostMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.ghostmode.toggle", false);

            tab->addToggle("player.ghostmode")
                ->setDescription("Enable ghost mode - phase through obstacles")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Ghost Mode"; }
        [[nodiscard]] int32_t getPriority() const override { return -46; }
    };

    REGISTER_HACK(GhostMode)
}
