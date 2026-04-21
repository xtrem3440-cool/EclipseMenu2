#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(NoPlatformerJumpSquishHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.noplatformerjumpsquish.toggle")
        
        // Hook implementation for NoPlatformerJumpSquish
        // This modifies game behavior based on config values
    };

    class $hack(NoPlatformerJumpSquish) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.noplatformerjumpsquish.toggle", false);
            config::setIfEmpty("player.noplatformerjumpsquish", 1.f);

            tab->addFloatToggle("player.noplatformerjumpsquish", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoPlatformerJumpSquish")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoPlatformerJumpSquish"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoPlatformerJumpSquish)
}
