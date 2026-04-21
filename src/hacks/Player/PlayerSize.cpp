#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(PlayerSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playersize.toggle", false);
            config::setIfEmpty("player.playersize", 1.f);

            tab->addFloatToggle("player.playersize", 0.3f, 3.0f, "%.2f")
                ->setDescription("Adjusts player size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Player Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -41; }
    };

    REGISTER_HACK(PlayerSize)
}
