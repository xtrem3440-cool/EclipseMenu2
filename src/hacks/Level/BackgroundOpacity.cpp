#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(BackgroundOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.backgroundopacity.toggle", false);
            config::setIfEmpty("level.backgroundopacity", 1.f);

            tab->addFloatToggle("level.backgroundopacity", 0.0f, 1.0f, "%.2f")
                ->setDescription("Adjusts background transparency")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Background Opacity"; }
        [[nodiscard]] int32_t getPriority() const override { return -75; }
    };

    REGISTER_HACK(BackgroundOpacity)
}
