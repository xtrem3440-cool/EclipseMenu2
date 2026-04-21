#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(ObjectScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.objectscale.toggle", false);
            config::setIfEmpty("level.objectscale", 1.f);

            tab->addFloatToggle("level.objectscale", 0.1f, 3.0f, "%.2f")
                ->setDescription("Scales all game objects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Object Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -79; }
    };

    REGISTER_HACK(ObjectScale)
}
