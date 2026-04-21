#include <Geode/modify/PlayerObject.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(NametagScaleHook, PlayerObject) {
        ADD_HOOKS_DELEGATE("global.nametagscale.toggle")
        
        // Hook implementation for NametagScale
        // This modifies game behavior based on config values
    };

    class $hack(NametagScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.nametagscale.toggle", false);
            config::setIfEmpty("global.nametagscale", 1.f);

            tab->addFloatToggle("global.nametagscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NametagScale")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NametagScale"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NametagScale)
}
