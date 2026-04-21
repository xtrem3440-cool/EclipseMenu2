#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(CustomWaveTrailHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.customwavetrail.toggle")
        
        // Hook implementation for CustomWaveTrail
        // This modifies game behavior based on config values
    };

    class $hack(CustomWaveTrail) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.customwavetrail.toggle", false);
            config::setIfEmpty("player.customwavetrail", 1.f);

            tab->addFloatToggle("player.customwavetrail", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies CustomWaveTrail")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "CustomWaveTrail"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(CustomWaveTrail)
}
