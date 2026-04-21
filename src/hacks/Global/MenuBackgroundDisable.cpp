#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(MenuBackgroundDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.menubackgrounddisable.toggle", false);

            tab->addToggle("global.menubackgrounddisable")
                ->setDescription("Disable menu background")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Menu Background"; }
        [[nodiscard]] int32_t getPriority() const override { return -31; }
    };

    REGISTER_HACK(MenuBackgroundDisable)
}
