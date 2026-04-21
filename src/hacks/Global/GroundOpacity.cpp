#include <Geode/modify/GameObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(GroundOpacityHook, GameObject) {
        ADD_HOOKS_DELEGATE("global.groundopacity.toggle")
        
        // Hook implementation for GroundOpacity
        // This modifies game behavior based on config values
    };

    class $hack(GroundOpacity) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.groundopacity.toggle", false);
            config::setIfEmpty("global.groundopacity", 1.f);

            tab->addFloatToggle("global.groundopacity", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies GroundOpacity")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "GroundOpacity"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(GroundOpacity)
}
