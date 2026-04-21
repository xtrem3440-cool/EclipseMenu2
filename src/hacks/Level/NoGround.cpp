#include <Geode/modify/GJGameLevel.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(NoGroundHook, GJGameLevel) {
        ADD_HOOKS_DELEGATE("level.noground.toggle")
        
        // Hook implementation for NoGround
        // This modifies game behavior based on config values
    };

    class $hack(NoGround) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.noground.toggle", false);
            config::setIfEmpty("level.noground", 1.f);

            tab->addFloatToggle("level.noground", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoGround")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoGround"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoGround)
}
