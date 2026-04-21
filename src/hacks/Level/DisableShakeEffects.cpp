#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(ShakeEffectDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.shakeeffectdisable.toggle", false);

            tab->addToggle("level.shakeeffectdisable")
                ->setDescription("Disable shake effects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Shake Effects"; }
        [[nodiscard]] int32_t getPriority() const override { return -81; }
    };

    REGISTER_HACK(ShakeEffectDisable)
}
