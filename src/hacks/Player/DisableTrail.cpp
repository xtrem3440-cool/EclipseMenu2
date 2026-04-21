#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(DisableTrail) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.disabletrail.toggle", false);

            tab->addToggle("player.disabletrail")
                ->setDescription("Disable player trail effect")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Trail"; }
        [[nodiscard]] int32_t getPriority() const override { return -44; }
    };

    REGISTER_HACK(DisableTrail)
}
