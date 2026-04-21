#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(MotionBlurDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.motionblurdisable.toggle", false);

            tab->addToggle("global.motionblurdisable")
                ->setDescription("Disable motion blur effect")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Motion Blur"; }
        [[nodiscard]] int32_t getPriority() const override { return -29; }
    };

    REGISTER_HACK(MotionBlurDisable)
}
