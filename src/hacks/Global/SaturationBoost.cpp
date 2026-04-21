#include <Geode/modify/CCRenderTexture.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(SaturationBoostHook, CCRenderTexture) {
        ADD_HOOKS_DELEGATE("global.saturationboost.toggle")
        
        // Hook implementation for SaturationBoost
        // This modifies game behavior based on config values
    };

    class $hack(SaturationBoost) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.saturationboost.toggle", false);
            config::setIfEmpty("global.saturationboost", 1.f);

            tab->addFloatToggle("global.saturationboost", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies SaturationBoost")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "SaturationBoost"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(SaturationBoost)
}
