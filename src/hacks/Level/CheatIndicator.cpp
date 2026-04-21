#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(CheatIndicatorHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("level.cheatindicator.toggle")
        
        // Hook implementation for CheatIndicator
        // This modifies game behavior based on config values
    };

    class $hack(CheatIndicator) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.cheatindicator.toggle", false);
            config::setIfEmpty("level.cheatindicator", 1.f);

            tab->addFloatToggle("level.cheatindicator", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies CheatIndicator")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "CheatIndicator"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(CheatIndicator)
}
