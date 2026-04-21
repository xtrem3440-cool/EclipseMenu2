#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelContrast) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levelcontrast.toggle", false);
            config::setIfEmpty("level.levelcontrast", 1.f);

            tab->addFloatToggle("level.levelcontrast", 0.5f, 2.0f, "%.2f")
                ->setDescription("Adjusts level contrast")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Contrast"; }
        [[nodiscard]] int32_t getPriority() const override { return -72; }
    };

    REGISTER_HACK(LevelContrast)
}
