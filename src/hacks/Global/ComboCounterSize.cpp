#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(ComboCounterSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.combocountersize.toggle", false);
            config::setIfEmpty("global.combocountersize", 1.f);

            tab->addFloatToggle("global.combocountersize", 0.3f, 3.0f, "%.2f")
                ->setDescription("Scales combo counter size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Combo Counter Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -26; }
    };

    REGISTER_HACK(ComboCounterSize)
}
