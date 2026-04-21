#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(NoTriggers) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.notriggers.toggle", false);

            tab->addToggle("level.notriggers")
                ->setDescription("Hide all triggers")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Triggers"; }
        [[nodiscard]] int32_t getPriority() const override { return -73; }
    };

    REGISTER_HACK(NoTriggers)
}
