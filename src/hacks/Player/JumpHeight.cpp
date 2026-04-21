#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(JumpHeight) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.jumpheight.toggle", false);
            config::setIfEmpty("player.jumpheight", 1.f);

            tab->addFloatToggle("player.jumpheight", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts jump height")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Jump Height"; }
        [[nodiscard]] int32_t getPriority() const override { return -47; }
    };

    REGISTER_HACK(JumpHeight)
}
