#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelSaturation) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levelsaturation.toggle", false);
            config::setIfEmpty("level.levelsaturation", 1.f);

            tab->addFloatToggle("level.levelsaturation", 0.0f, 3.0f, "%.2f")
                ->setDescription("Adjusts level color saturation")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Saturation"; }
        [[nodiscard]] int32_t getPriority() const override { return -76; }
    };

    REGISTER_HACK(LevelSaturation)
}
