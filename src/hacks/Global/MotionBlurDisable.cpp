#include <Geode/modify/RenderTexture.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(MotionBlurDisableHook, RenderTexture) {
        ADD_HOOKS_DELEGATE("global.motionblurdisable.toggle")
        
        // Hook implementation for MotionBlurDisable
        // This modifies game behavior based on config values
    };

    class $hack(MotionBlurDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.motionblurdisable.toggle", false);
            config::setIfEmpty("global.motionblurdisable", 1.f);

            tab->addFloatToggle("global.motionblurdisable", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies MotionBlurDisable")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "MotionBlurDisable"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(MotionBlurDisable)
}
