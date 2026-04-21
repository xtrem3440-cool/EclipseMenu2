#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(NametagScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.nametagscale.toggle", false);
            config::setIfEmpty("global.nametagscale", 1.f);

            tab->addFloatToggle("global.nametagscale", 0.2f, 3.0f, "%.2f")
                ->setDescription("Scales player nametags")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Nametag Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -19; }
    };

    REGISTER_HACK(NametagScale)
}
