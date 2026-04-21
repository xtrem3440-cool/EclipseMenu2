#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levelbrightness.toggle", false);
            config::setIfEmpty("level.levelbrightness", 1.f);

            tab->addFloatToggle("level.levelbrightness", 0.1f, 2.0f, "%.2f")
                ->setDescription("Adjusts level brightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Brightness"; }
        [[nodiscard]] int32_t getPriority() const override { return -71; }
    };

    REGISTER_HACK(LevelBrightness)
}
