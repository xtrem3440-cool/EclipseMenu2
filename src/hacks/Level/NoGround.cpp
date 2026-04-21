#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(NoGround) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.noground.toggle", false);

            tab->addToggle("level.noground")
                ->setDescription("Hide ground layers")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Ground"; }
        [[nodiscard]] int32_t getPriority() const override { return -78; }
    };

    REGISTER_HACK(NoGround)
}
