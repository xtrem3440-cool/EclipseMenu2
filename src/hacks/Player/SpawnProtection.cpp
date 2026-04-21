#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Player {
    class $hack(SpawnProtection) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.player");

            config::setIfEmpty("player.spawnprotection.toggle", false);

            tab->addToggle("player.spawnprotection")
                ->setDescription("Invulnerability after spawn")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Spawn Protection"; }
        [[nodiscard]] int32_t getPriority() const override { return -60; }
    };

    REGISTER_HACK(SpawnProtection)
}
