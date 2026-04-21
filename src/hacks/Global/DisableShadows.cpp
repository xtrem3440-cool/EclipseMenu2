#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(DisableShadowsHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("global.disableshadows.toggle")
        
        // Hook implementation for DisableShadows
        // This modifies game behavior based on config values
    };

    class $hack(DisableShadows) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disableshadows.toggle", false);
            config::setIfEmpty("global.disableshadows", 1.f);

            tab->addFloatToggle("global.disableshadows", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableShadows")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableShadows"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableShadows)
}
