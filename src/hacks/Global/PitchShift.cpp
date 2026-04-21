#include <Geode/modify/FMODAudioEngine.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(PitchShiftHook, FMODAudioEngine) {
        ADD_HOOKS_DELEGATE("global.pitchshift.toggle")
        
        // Hook implementation for PitchShift
        // This modifies game behavior based on config values
    };

    class $hack(PitchShift) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.pitchshift.toggle", false);
            config::setIfEmpty("global.pitchshift", 1.f);

            tab->addFloatToggle("global.pitchshift", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PitchShift")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PitchShift"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PitchShift)
}
