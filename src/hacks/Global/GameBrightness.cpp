#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
<parameter name="components/float-toggle.hpp">
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(GameBrightness) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.gamebrightness.toggle", false);
            config::setIfEmpty("global.gamebrightness", 1.f);

            tab->addFloatToggle("global.gamebrightness", 0.1f, 2.0f, "%.2f")
                ->setDescription("Adjusts game brightness")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Game Brightness"; }
        [[nodiscard]] int32_t getPriority() const override { return -21; }
    };

    REGISTER_HACK(GameBrightness)
}
