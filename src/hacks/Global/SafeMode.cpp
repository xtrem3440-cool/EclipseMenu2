#include <Geode/modify/GameManager.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(SafeModeHook, GameManager) {
        ADD_HOOKS_DELEGATE("global.safemode.toggle")
        
        // Hook implementation for SafeMode
        // This modifies game behavior based on config values
    };

    class $hack(SafeMode) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.safemode.toggle", false);
            config::setIfEmpty("global.safemode", 1.f);

            tab->addFloatToggle("global.safemode", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies SafeMode")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "SafeMode"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(SafeMode)
}
