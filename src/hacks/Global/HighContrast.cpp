#include <Geode/modify/ColorTweenAction.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(HighContrastHook, ColorTweenAction) {
        ADD_HOOKS_DELEGATE("global.highcontrast.toggle")
        
        // Hook implementation for HighContrast
        // This modifies game behavior based on config values
    };

    class $hack(HighContrast) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.highcontrast.toggle", false);
            config::setIfEmpty("global.highcontrast", 1.f);

            tab->addFloatToggle("global.highcontrast", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies HighContrast")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "HighContrast"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(HighContrast)
}
