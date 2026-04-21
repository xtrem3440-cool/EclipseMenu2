#include <Geode/modify/GameManager.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(LevelLoadingTimeHook, GameManager) {
        ADD_HOOKS_DELEGATE("global.levelloadingtime.toggle")
        
        // Hook implementation for LevelLoadingTime
        // This modifies game behavior based on config values
    };

    class $hack(LevelLoadingTime) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.levelloadingtime.toggle", false);
            config::setIfEmpty("global.levelloadingtime", 1.f);

            tab->addFloatToggle("global.levelloadingtime", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LevelLoadingTime")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LevelLoadingTime"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LevelLoadingTime)
}
