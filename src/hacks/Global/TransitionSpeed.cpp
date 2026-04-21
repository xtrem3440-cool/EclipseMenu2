#include <Geode/modify/MenuGameLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(TransitionSpeedHook, MenuGameLayer) {
        ADD_HOOKS_DELEGATE("global.transitionspeed.toggle")
        
        // Hook implementation for TransitionSpeed
        // This modifies game behavior based on config values
    };

    class $hack(TransitionSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.transitionspeed.toggle", false);
            config::setIfEmpty("global.transitionspeed", 1.f);

            tab->addFloatToggle("global.transitionspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies TransitionSpeed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "TransitionSpeed"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(TransitionSpeed)
}
