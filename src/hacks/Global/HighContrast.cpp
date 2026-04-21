#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(HighContrast) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.highcontrast.toggle", false);

            tab->addToggle("global.highcontrast")
                ->setDescription("Enable high contrast mode")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "High Contrast Mode"; }
        [[nodiscard]] int32_t getPriority() const override { return -25; }
    };

    REGISTER_HACK(HighContrast)
}
