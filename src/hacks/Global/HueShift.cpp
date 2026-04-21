#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(HueShift) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.hueshift.toggle", false);
            config::setIfEmpty("global.hueshift", 0.f);

            tab->addFloatToggle("global.hueshift", -180.f, 180.f, "%.1f")
                ->setDescription("Shifts all hue colors")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Hue Shift"; }
        [[nodiscard]] int32_t getPriority() const override { return -24; }
    };

    REGISTER_HACK(HueShift)
}
