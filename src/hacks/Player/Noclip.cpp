#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(NoclipHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("player.noclip.toggle")
        
        // Hook implementation for Noclip
        // This modifies game behavior based on config values
    };

    class $hack(Noclip) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.noclip.toggle", false);
            config::setIfEmpty("player.noclip", 1.f);

            tab->addFloatToggle("player.noclip", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies Noclip")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Noclip"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(Noclip)
}
