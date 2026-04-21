#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerTrailScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playertrailscale.toggle", false);
            config::setIfEmpty("player.playertrailscale", 1.f);

            tab->addFloatToggle("player.playertrailscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts player trail size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Trail Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -43; }
    };

    REGISTER_HACK(PlayerTrailScale)
}
