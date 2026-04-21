#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(NoObstacles) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.noobstacles.toggle", false);

            tab->addToggle("level.noobstacles")
                ->setDescription("Hide all obstacles")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Obstacles"; }
        [[nodiscard]] int32_t getPriority() const override { return -70; }
    };

    REGISTER_HACK(NoObstacles)
}
