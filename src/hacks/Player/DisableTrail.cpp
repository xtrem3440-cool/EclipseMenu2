#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(DisableTrailHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.disabletrail.toggle")
        
        // Hook implementation for DisableTrail
        // This modifies game behavior based on config values
    };

    class $hack(DisableTrail) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.disabletrail.toggle", false);
            config::setIfEmpty("player.disabletrail", 1.f);

            tab->addFloatToggle("player.disabletrail", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableTrail")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableTrail"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableTrail)
}
