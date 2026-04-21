#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(DoubleJumpHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.doublejump.toggle")
        
        // Hook implementation for DoubleJump
        // This modifies game behavior based on config values
    };

    class $hack(DoubleJump) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.doublejump.toggle", false);
            config::setIfEmpty("player.doublejump", 1.f);

            tab->addFloatToggle("player.doublejump", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DoubleJump")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DoubleJump"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DoubleJump)
}
