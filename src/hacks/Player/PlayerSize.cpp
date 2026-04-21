#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(PlayerSizeHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.playersize.toggle")
        
        // Hook implementation for PlayerSize
        // This modifies game behavior based on config values
    };

    class $hack(PlayerSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.playersize.toggle", false);
            config::setIfEmpty("player.playersize", 1.f);

            tab->addFloatToggle("player.playersize", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies PlayerSize")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "PlayerSize"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(PlayerSize)
}
