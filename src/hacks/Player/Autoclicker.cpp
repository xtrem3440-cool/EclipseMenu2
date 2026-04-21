#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(AutoclickerHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("player.autoclicker.toggle")
        
        // Hook implementation for Autoclicker
        // This modifies game behavior based on config values
    };

    class $hack(Autoclicker) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.autoclicker.toggle", false);
            config::setIfEmpty("player.autoclicker", 1.f);

            tab->addFloatToggle("player.autoclicker", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies Autoclicker")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Autoclicker"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(Autoclicker)
}
