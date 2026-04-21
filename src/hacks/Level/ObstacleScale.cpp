#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(ObstacleScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.obstaclescale.toggle", false);
            config::setIfEmpty("level.obstaclescale", 1.f);

            tab->addFloatToggle("level.obstaclescale", 0.1f, 3.0f, "%.2f")
                ->setDescription("Scales all obstacles")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Obstacle Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -68; }
    };

    REGISTER_HACK(ObstacleScale)
}
