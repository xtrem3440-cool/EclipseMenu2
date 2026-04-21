#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(BallRotationHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.ballrotation.toggle")
        
        // Hook implementation for BallRotation
        // This modifies game behavior based on config values
    };

    class $hack(BallRotation) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.ballrotation.toggle", false);
            config::setIfEmpty("player.ballrotation", 1.f);

            tab->addFloatToggle("player.ballrotation", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies BallRotation")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "BallRotation"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(BallRotation)
}
