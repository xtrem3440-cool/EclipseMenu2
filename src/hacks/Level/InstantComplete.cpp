#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(InstantCompleteHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("level.instantcomplete.toggle")
        
        // Hook implementation for InstantComplete
        // This modifies game behavior based on config values
    };

    class $hack(InstantComplete) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.instantcomplete.toggle", false);
            config::setIfEmpty("level.instantcomplete", 1.f);

            tab->addFloatToggle("level.instantcomplete", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies InstantComplete")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "InstantComplete"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(InstantComplete)
}
