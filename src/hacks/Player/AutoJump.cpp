#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(AutoJumpHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.autojump.toggle")
        
        // Hook implementation for AutoJump
        // This modifies game behavior based on config values
    };

    class $hack(AutoJump) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.autojump.toggle", false);
            config::setIfEmpty("player.autojump", 1.f);

            tab->addFloatToggle("player.autojump", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies AutoJump")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "AutoJump"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(AutoJump)
}
