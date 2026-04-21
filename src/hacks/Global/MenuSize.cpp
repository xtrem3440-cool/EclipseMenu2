#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(MenuSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.menusize.toggle", false);
            config::setIfEmpty("global.menusize", 1.f);

            tab->addFloatToggle("global.menusize", 0.3f, 3.0f, "%.2f")
                ->setDescription("Scales menu window size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Menu Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -38; }
    };

    REGISTER_HACK(MenuSize)
}
