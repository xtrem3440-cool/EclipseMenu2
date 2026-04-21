#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(PracticeModeHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("level.practicemode.toggle")
        
        // Hook implementation for PracticeMode
        // This modifies game behavior based on config values
    };

    class $hack(PracticeMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.practicemode.toggle", false);
            config::setIfEmpty("level.practicemode", 1.f);

            tab->addFloatToggle("level.practicemode", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PracticeMode")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PracticeMode"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PracticeMode)
}
