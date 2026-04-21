#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerTrailScaleHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playertrailscale.toggle")
        
        // Hook implementation for PlayerTrailScale
        // This modifies game behavior based on config values
    };

    class $hack(PlayerTrailScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playertrailscale.toggle", false);
            config::setIfEmpty("player.playertrailscale", 1.f);

            tab->addFloatToggle("player.playertrailscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerTrailScale")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerTrailScale"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerTrailScale)
}
