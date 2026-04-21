#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(IconSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.iconsize.toggle", false);
            config::setIfEmpty("global.iconsize", 1.f);

            tab->addFloatToggle("global.iconsize", 0.3f, 3.0f, "%.2f")
                ->setDescription("Scales all icon sizes")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Icon Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -32; }
    };

    REGISTER_HACK(IconSize)
}
