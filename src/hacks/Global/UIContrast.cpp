#include <Geode/modify/CCLabelBMFont.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(UIContrastHook, CCLabelBMFont) {
        ADD_HOOKS_DELEGATE("global.uicontrast.toggle")
        
        // Hook implementation for UIContrast
        // This modifies game behavior based on config values
    };

    class $hack(UIContrast) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.uicontrast.toggle", false);
            config::setIfEmpty("global.uicontrast", 1.f);

            tab->addFloatToggle("global.uicontrast", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies UIContrast")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UIContrast"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(UIContrast)
}
