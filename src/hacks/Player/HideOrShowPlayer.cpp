#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(HideOrShowPlayerHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.hideorshowplayer.toggle")
        
        // Hook implementation for HideOrShowPlayer
        // This modifies game behavior based on config values
    };

    class $hack(HideOrShowPlayer) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.hideorshowplayer.toggle", false);
            config::setIfEmpty("player.hideorshowplayer", 1.f);

            tab->addFloatToggle("player.hideorshowplayer", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies HideOrShowPlayer")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "HideOrShowPlayer"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(HideOrShowPlayer)
}
