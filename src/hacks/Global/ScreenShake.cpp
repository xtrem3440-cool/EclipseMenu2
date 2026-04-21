#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(ScreenShake) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.screenshake.toggle", false);

            tab->addToggle("global.screenshake")
                ->setDescription("Disable screen shake effects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Screen Shake"; }
        [[nodiscard]] int32_t getPriority() const override { return -12; }
    };

    REGISTER_HACK(ScreenShake)
}
