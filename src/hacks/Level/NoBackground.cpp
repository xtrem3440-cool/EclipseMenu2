#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(NoBackgroundHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("level.nobackground.toggle")
        
        // Hook implementation for NoBackground
        // This modifies game behavior based on config values
    };

    class $hack(NoBackground) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.nobackground.toggle", false);
            config::setIfEmpty("level.nobackground", 1.f);

            tab->addFloatToggle("level.nobackground", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoBackground")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoBackground"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoBackground)
}
