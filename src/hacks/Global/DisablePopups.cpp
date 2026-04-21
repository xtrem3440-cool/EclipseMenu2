#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(DisablePopups) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disablepopups.toggle", false);

            tab->addToggle("global.disablepopups")
                ->setDescription("Disable all popup notifications")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Popups"; }
        [[nodiscard]] int32_t getPriority() const override { return -17; }
    };

    REGISTER_HACK(DisablePopups)
}
