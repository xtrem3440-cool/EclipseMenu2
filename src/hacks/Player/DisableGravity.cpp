#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(DisableGravityHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.disablegravity.toggle")
        
        // Hook implementation for DisableGravity
        // This modifies game behavior based on config values
    };

    class $hack(DisableGravity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.disablegravity.toggle", false);
            config::setIfEmpty("player.disablegravity", 1.f);

            tab->addFloatToggle("player.disablegravity", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableGravity")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableGravity"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableGravity)
}
