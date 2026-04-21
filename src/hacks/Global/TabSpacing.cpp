#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(TabSpacing) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.tabspacing.toggle", false);
            config::setIfEmpty("global.tabspacing", 1.f);

            tab->addFloatToggle("global.tabspacing", 0.5f, 3.0f, "%.2f")
                ->setDescription("Adjusts spacing between tabs")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Tab Spacing"; }
        [[nodiscard]] int32_t getPriority() const override { return -33; }
    };

    REGISTER_HACK(TabSpacing)
}
