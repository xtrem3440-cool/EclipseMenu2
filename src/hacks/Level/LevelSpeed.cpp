#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levelspeed.toggle", false);
            config::setIfEmpty("level.levelspeed", 1.f);

            tab->addFloatToggle("level.levelspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts overall level speed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -85; }
    };

    REGISTER_HACK(LevelSpeed)
}
