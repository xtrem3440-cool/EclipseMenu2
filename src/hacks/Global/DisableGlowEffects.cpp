#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(DisableGlowEffects) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disablegloweffects.toggle", false);

            tab->addToggle("global.disablegloweffects")
                ->setDescription("Disable glow effect on objects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Glow Effects"; }
        [[nodiscard]] int32_t getPriority() const override { return -39; }
    };

    REGISTER_HACK(DisableGlowEffects)
}
