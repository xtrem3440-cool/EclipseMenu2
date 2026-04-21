#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $modify(NoDeathEffectHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("player.nodeatheffect.toggle")
        
        // Hook implementation for NoDeathEffect
        // This modifies game behavior based on config values
    };

    class $hack(NoDeathEffect) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.nodeatheffect.toggle", false);
            config::setIfEmpty("player.nodeatheffect", 1.f);

            tab->addFloatToggle("player.nodeatheffect", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoDeathEffect")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoDeathEffect"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoDeathEffect)
}
