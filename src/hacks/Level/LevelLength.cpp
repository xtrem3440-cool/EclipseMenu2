#include <Geode/modify/GJGameLevel.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(LevelLengthHook, GJGameLevel) {
        ADD_HOOKS_DELEGATE("level.levellength.toggle")
        
        // Hook implementation for LevelLength
        // This modifies game behavior based on config values
    };

    class $hack(LevelLength) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levellength.toggle", false);
            config::setIfEmpty("level.levellength", 1.f);

            tab->addFloatToggle("level.levellength", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LevelLength")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LevelLength"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LevelLength)
}
