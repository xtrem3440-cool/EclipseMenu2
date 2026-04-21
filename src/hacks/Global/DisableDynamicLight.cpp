#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(DisableDynamicLight) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disabledynamiclight.toggle", false);

            tab->addToggle("global.disabledynamiclight")
                ->setDescription("Disable dynamic lighting")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Dynamic Light"; }
        [[nodiscard]] int32_t getPriority() const override { return -34; }
    };

    REGISTER_HACK(DisableDynamicLight)
}
