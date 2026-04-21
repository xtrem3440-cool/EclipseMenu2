#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(UIContrast) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.uicontrast.toggle", false);
            config::setIfEmpty("global.uicontrast", 1.f);

            tab->addFloatToggle("global.uicontrast", 0.5f, 2.0f, "%.2f")
                ->setDescription("Adjusts UI contrast")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UI Contrast"; }
        [[nodiscard]] int32_t getPriority() const override { return -22; }
    };

    REGISTER_HACK(UIContrast)
}
