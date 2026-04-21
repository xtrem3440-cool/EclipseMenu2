#include <Geode/modify/LevelEditorLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(LevelEditorHook, LevelEditorLayer) {
        ADD_HOOKS_DELEGATE("level.leveleditor.toggle")
        
        // Hook implementation for LevelEditor
        // This modifies game behavior based on config values
    };

    class $hack(LevelEditor) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.leveleditor.toggle", false);
            config::setIfEmpty("level.leveleditor", 1.f);

            tab->addFloatToggle("level.leveleditor", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LevelEditor")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LevelEditor"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LevelEditor)
}
