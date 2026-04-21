#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(SaturationBoost) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.saturationboost.toggle", false);
            config::setIfEmpty("global.saturationboost", 1.f);

            tab->addFloatToggle("global.saturationboost", 0.0f, 3.0f, "%.2f")
                ->setDescription("Increases color saturation")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Saturation Boost"; }
        [[nodiscard]] int32_t getPriority() const override { return -23; }
    };

    REGISTER_HACK(SaturationBoost)
}
