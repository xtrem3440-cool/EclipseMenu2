#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(NoPlatforms) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.noplatforms.toggle", false);

            tab->addToggle("level.noplatforms")
                ->setDescription("Hide all platforms")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Platforms"; }
        [[nodiscard]] int32_t getPriority() const override { return -67; }
    };

    REGISTER_HACK(NoPlatforms)
}
