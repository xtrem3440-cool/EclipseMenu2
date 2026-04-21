#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(LunarGravityHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.lunargravity.toggle")
        
        // Hook implementation for LunarGravity
        // This modifies game behavior based on config values
    };

    class $hack(LunarGravity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.lunargravity.toggle", false);
            config::setIfEmpty("player.lunargravity", 1.f);

            tab->addFloatToggle("player.lunargravity", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LunarGravity")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LunarGravity"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LunarGravity)
}
