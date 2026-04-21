#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(TrailLength) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.trailduration.toggle", false);
            config::setIfEmpty("player.trailduration", 1.f);

            tab->addFloatToggle("player.trailduration", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts how long trails persist")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Trail Duration"; }
        [[nodiscard]] int32_t getPriority() const override { return -57; }
    };

    REGISTER_HACK(TrailLength)
}
