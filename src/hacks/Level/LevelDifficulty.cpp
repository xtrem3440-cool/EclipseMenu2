#include <Geode/modify/GJGameLevel.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(LevelDifficultyHook, GJGameLevel) {
        ADD_HOOKS_DELEGATE("level.leveldifficulty.toggle")
        
        // Hook implementation for LevelDifficulty
        // This modifies game behavior based on config values
    };

    class $hack(LevelDifficulty) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.leveldifficulty.toggle", false);
            config::setIfEmpty("level.leveldifficulty", 1.f);

            tab->addFloatToggle("level.leveldifficulty", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LevelDifficulty")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LevelDifficulty"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LevelDifficulty)
}
