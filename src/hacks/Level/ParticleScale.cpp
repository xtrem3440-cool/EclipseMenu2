#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(ParticleScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.particlescale.toggle", false);
            config::setIfEmpty("level.particlescale", 1.f);

            tab->addFloatToggle("level.particlescale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Scales level particle effects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Particle Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -82; }
    };

    REGISTER_HACK(ParticleScale)
}
