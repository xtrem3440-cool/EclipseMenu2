#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(ParticleEffectScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.particleeffectscale.toggle", false);
            config::setIfEmpty("global.particleeffectscale", 1.f);

            tab->addFloatToggle("global.particleeffectscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Scales all particle effects in the game")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Particle Effect Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -10; }
    };

    REGISTER_HACK(ParticleEffectScale)
}
