#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelBackground) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.disablebackground.toggle", false);

            tab->addToggle("level.disablebackground")
                ->setDescription("Disable level background")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Level Background"; }
        [[nodiscard]] int32_t getPriority() const override { return -66; }
    };

    REGISTER_HACK(LevelBackground)
}
