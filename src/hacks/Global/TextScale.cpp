#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(TextScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.textscale.toggle", false);
            config::setIfEmpty("global.textscale", 1.f);

            tab->addFloatToggle("global.textscale", 0.5f, 2.5f, "%.2f")
                ->setDescription("Scales all text sizes")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Text Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -14; }
    };

    REGISTER_HACK(TextScale)
}
