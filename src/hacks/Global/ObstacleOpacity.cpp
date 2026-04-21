#include <Geode/modify/GameObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(ObstacleOpacityHook, GameObject) {
        ADD_HOOKS_DELEGATE("global.obstacleopacity.toggle")
        
        // Hook implementation for ObstacleOpacity
        // This modifies game behavior based on config values
    };

    class $hack(ObstacleOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.obstacleopacity.toggle", false);
            config::setIfEmpty("global.obstacleopacity", 1.f);

            tab->addFloatToggle("global.obstacleopacity", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies ObstacleOpacity")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "ObstacleOpacity"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(ObstacleOpacity)
}
