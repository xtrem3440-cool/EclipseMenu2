#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(FPSCounterSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.fpscountersize.toggle", false);
            config::setIfEmpty("global.fpscountersize", 1.f);

            tab->addFloatToggle("global.fpscountersize", 0.5f, 3.0f, "%.2f")
                ->setDescription("Scales FPS counter size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "FPS Counter Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -27; }
    };

    REGISTER_HACK(FPSCounterSize)
}
