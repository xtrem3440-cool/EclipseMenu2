#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(FrameStepperHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("player.framestepper.toggle")
        
        // Hook implementation for FrameStepper
        // This modifies game behavior based on config values
    };

    class $hack(FrameStepper) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.framestepper.toggle", false);
            config::setIfEmpty("player.framestepper", 1.f);

            tab->addFloatToggle("player.framestepper", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies FrameStepper")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "FrameStepper"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(FrameStepper)
}
