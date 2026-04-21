#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(DisableShadows) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disableshadows.toggle", false);

            tab->addToggle("global.disableshadows")
                ->setDescription("Disable shadow effects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Shadows"; }
        [[nodiscard]] int32_t getPriority() const override { return -35; }
    };

    REGISTER_HACK(DisableShadows)
}
