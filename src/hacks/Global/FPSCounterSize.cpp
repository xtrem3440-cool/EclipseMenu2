#include <Geode/modify/UILayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(FPSCounterSizeHook, UILayer) {
        ADD_HOOKS_DELEGATE("global.fpscountersize.toggle")
        
        // Hook implementation for FPSCounterSize
        // This modifies game behavior based on config values
    };

    class $hack(FPSCounterSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.fpscountersize.toggle", false);
            config::setIfEmpty("global.fpscountersize", 1.f);

            tab->addFloatToggle("global.fpscountersize", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies FPSCounterSize")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "FPSCounterSize"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(FPSCounterSize)
}
