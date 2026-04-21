#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(DisableInputLag) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disableinputlag.toggle", false);

            tab->addToggle("global.disableinputlag")
                ->setDescription("Reduce input lag")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Input Lag"; }
        [[nodiscard]] int32_t getPriority() const override { return -28; }
    };

    REGISTER_HACK(DisableInputLag)
}
