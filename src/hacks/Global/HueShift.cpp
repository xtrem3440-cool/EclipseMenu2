#include <Geode/modify/CCNode.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(HueShiftHook, CCNode) {
        ADD_HOOKS_DELEGATE("global.hueshift.toggle")
        
        // Hook implementation for HueShift
        // This modifies game behavior based on config values
    };

    class $hack(HueShift) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.hueshift.toggle", false);
            config::setIfEmpty("global.hueshift", 1.f);

            tab->addFloatToggle("global.hueshift", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies HueShift")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "HueShift"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(HueShift)
}
