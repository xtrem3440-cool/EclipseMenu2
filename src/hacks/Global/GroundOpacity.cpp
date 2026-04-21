#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(GroundOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.groundopacity.toggle", false);
            config::setIfEmpty("global.groundopacity", 1.f);

            tab->addFloatToggle("global.groundopacity", 0.0f, 1.0f, "%.2f")
                ->setDescription("Adjusts ground transparency")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Ground Opacity"; }
        [[nodiscard]] int32_t getPriority() const override { return -37; }
    };

    REGISTER_HACK(GroundOpacity)
}
