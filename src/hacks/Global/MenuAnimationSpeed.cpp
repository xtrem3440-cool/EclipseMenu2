#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(MenuAnimationSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.menuanimationspeed.toggle", false);
            config::setIfEmpty("global.menuanimationspeed", 1.f);

            tab->addFloatToggle("global.menuanimationspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts menu transition speeds")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Menu Animation Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -16; }
    };

    REGISTER_HACK(MenuAnimationSpeed)
}
