#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(UIBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.uibrightness.toggle", false);
            config::setIfEmpty("global.uibrightness", 1.f);

            tab->addFloatToggle("global.uibrightness", 0.1f, 2.0f, "%.2f")
                ->setDescription("Adjusts UI brightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UI Brightness"; }
        [[nodiscard]] int32_t getPriority() const override { return -20; }
    };

    REGISTER_HACK(UIBrightness)
}
