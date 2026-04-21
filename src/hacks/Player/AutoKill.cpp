#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(AutoKillHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("player.autokill.toggle")
        
        // Hook implementation for AutoKill
        // This modifies game behavior based on config values
    };

    class $hack(AutoKill) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.autokill.toggle", false);
            config::setIfEmpty("player.autokill", 1.f);

            tab->addFloatToggle("player.autokill", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies AutoKill")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "AutoKill"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(AutoKill)
}
