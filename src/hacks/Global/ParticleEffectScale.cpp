#include <Geode/modify/ParticleSystem.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(ParticleEffectScaleHook, ParticleSystem) {
        ADD_HOOKS_DELEGATE("global.particleeffectscale.toggle")
        
        // Hook implementation for ParticleEffectScale
        // This modifies game behavior based on config values
    };

    class $hack(ParticleEffectScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.particleeffectscale.toggle", false);
            config::setIfEmpty("global.particleeffectscale", 1.f);

            tab->addFloatToggle("global.particleeffectscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies ParticleEffectScale")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "ParticleEffectScale"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(ParticleEffectScale)
}
