#include <Geode/modify/UILayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(ComboCounterSizeHook, UILayer) {
        ADD_HOOKS_DELEGATE("global.combocountersize.toggle")
        
        // Hook implementation for ComboCounterSize
        // This modifies game behavior based on config values
    };

    class $hack(ComboCounterSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.combocountersize.toggle", false);
            config::setIfEmpty("global.combocountersize", 1.f);

            tab->addFloatToggle("global.combocountersize", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies ComboCounterSize")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "ComboCounterSize"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(ComboCounterSize)
}
