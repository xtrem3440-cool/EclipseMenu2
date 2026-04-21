#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(MinimapScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.minimapscale.toggle", false);
            config::setIfEmpty("global.minimapscale", 1.f);

            tab->addFloatToggle("global.minimapscale", 0.3f, 3.0f, "%.2f")
                ->setDescription("Scales minimap size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Minimap Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -40; }
    };

    REGISTER_HACK(MinimapScale)
}
