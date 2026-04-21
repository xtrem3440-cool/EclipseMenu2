#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerRotation) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playerrotation.toggle", false);
            config::setIfEmpty("player.playerrotation", 0.f);

            tab->addFloatToggle("player.playerrotation", -360.f, 360.f, "%.1f")
                ->setDescription("Rotates player sprite")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Rotation"; }
        [[nodiscard]] int32_t getPriority() const override { return -54; }
    };

    REGISTER_HACK(PlayerRotation)
}
