#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(BackgroundBlur) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.backgroundblur.toggle", false);

            tab->addToggle("global.backgroundblur")
                ->setDescription("Disable blur effect on background")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Background Blur"; }
        [[nodiscard]] int32_t getPriority() const override { return -13; }
    };

    REGISTER_HACK(BackgroundBlur)
}
