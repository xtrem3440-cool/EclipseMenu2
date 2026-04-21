#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(NoFrictionHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.nofriction.toggle")
        
        // Hook implementation for NoFriction
        // This modifies game behavior based on config values
    };

    class $hack(NoFriction) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.nofriction.toggle", false);
            config::setIfEmpty("player.nofriction", 1.f);

            tab->addFloatToggle("player.nofriction", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoFriction")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoFriction"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoFriction)
}
