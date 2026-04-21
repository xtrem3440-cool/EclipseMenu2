#include <Geode/modify/GameManager.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Bypass {
    class $modify(UnlockAllLevelsHook, GameManager) {
        ADD_HOOKS_DELEGATE("bypass.unlockallevels.toggle")
        
        // Hook implementation for UnlockAllLevels
        // This modifies game behavior based on config values
    };

    class $hack(UnlockAllLevels) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.bypass");

            config::setIfEmpty("bypass.unlockallevels.toggle", false);
            config::setIfEmpty("bypass.unlockallevels", 1.f);

            tab->addFloatToggle("bypass.unlockallevels", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies UnlockAllLevels")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UnlockAllLevels"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(UnlockAllLevels)
}
