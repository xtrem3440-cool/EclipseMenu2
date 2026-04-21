#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(CameraShakeDisable) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.camerashakedisable.toggle", false);

            tab->addToggle("level.camerashakedisable")
                ->setDescription("Disable camera shake")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Disable Camera Shake"; }
        [[nodiscard]] int32_t getPriority() const override { return -84; }
    };

    REGISTER_HACK(CameraShakeDisable)
}
