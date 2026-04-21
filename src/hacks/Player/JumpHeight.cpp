#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(JumpHeightHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.jumpheight.toggle")
        
        // Hook implementation for JumpHeight
        // This modifies game behavior based on config values
    };

    class $hack(JumpHeight) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.jumpheight.toggle", false);
            config::setIfEmpty("player.jumpheight", 1.f);

            tab->addFloatToggle("player.jumpheight", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies JumpHeight")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "JumpHeight"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(JumpHeight)
}
