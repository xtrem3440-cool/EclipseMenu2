#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(InvisiblePlayerHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.invisibleplayer.toggle")
        
        // Hook implementation for InvisiblePlayer
        // This modifies game behavior based on config values
    };

    class $hack(InvisiblePlayer) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.invisibleplayer.toggle", false);
            config::setIfEmpty("player.invisibleplayer", 1.f);

            tab->addFloatToggle("player.invisibleplayer", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies InvisiblePlayer")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "InvisiblePlayer"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(InvisiblePlayer)
}
