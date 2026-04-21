#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(HueShiftLevel) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.hueshiftlevel.toggle", false);
            config::setIfEmpty("level.hueshiftlevel", 0.f);

            tab->addFloatToggle("level.hueshiftlevel", -180.f, 180.f, "%.1f")
                ->setDescription("Shifts level hue colors")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Hue Shift"; }
        [[nodiscard]] int32_t getPriority() const override { return -77; }
    };

    REGISTER_HACK(HueShiftLevel)
}
