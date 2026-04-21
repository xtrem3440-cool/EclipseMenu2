#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(PulseEffectDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.pulseeffectdisable.toggle", false);

            tab->addToggle("level.pulseeffectdisable")
                ->setDescription("Disable pulse effects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Pulse Effects"; }
        [[nodiscard]] int32_t getPriority() const override { return -80; }
    };

    REGISTER_HACK(PulseEffectDisable)
}
