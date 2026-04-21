#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(ObstacleOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.obstacleopacity.toggle", false);
            config::setIfEmpty("global.obstacleopacity", 1.f);

            tab->addFloatToggle("global.obstacleopacity", 0.0f, 1.0f, "%.2f")
                ->setDescription("Adjusts obstacle transparency")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Obstacle Opacity"; }
        [[nodiscard]] int32_t getPriority() const override { return -36; }
    };

    REGISTER_HACK(ObstacleOpacity)
}
