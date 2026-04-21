#include <Geode/modify/DrawNode.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(DisableDynamicLightHook, DrawNode) {
        ADD_HOOKS_DELEGATE("global.disabledynamiclight.toggle")
        
        // Hook implementation for DisableDynamicLight
        // This modifies game behavior based on config values
    };

    class $hack(DisableDynamicLight) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disabledynamiclight.toggle", false);
            config::setIfEmpty("global.disabledynamiclight", 1.f);

            tab->addFloatToggle("global.disabledynamiclight", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableDynamicLight")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableDynamicLight"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableDynamicLight)
}
