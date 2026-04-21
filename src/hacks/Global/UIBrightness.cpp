#include <Geode/modify/MenuLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(UIBrightnessHook, MenuLayer) {
        ADD_HOOKS_DELEGATE("global.uibrightness.toggle")
        
        // Hook implementation for UIBrightness
        // This modifies game behavior based on config values
    };

    class $hack(UIBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.uibrightness.toggle", false);
            config::setIfEmpty("global.uibrightness", 1.f);

            tab->addFloatToggle("global.uibrightness", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies UIBrightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UIBrightness"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(UIBrightness)
}
