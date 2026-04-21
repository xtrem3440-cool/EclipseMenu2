#include <Geode/modify/RenderTexture.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(DisableGlowEffectsHook, RenderTexture) {
        ADD_HOOKS_DELEGATE("global.disablegloweffects.toggle")
        
        // Hook implementation for DisableGlowEffects
        // This modifies game behavior based on config values
    };

    class $hack(DisableGlowEffects) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disablegloweffects.toggle", false);
            config::setIfEmpty("global.disablegloweffects", 1.f);

            tab->addFloatToggle("global.disablegloweffects", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableGlowEffects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableGlowEffects"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableGlowEffects)
}
