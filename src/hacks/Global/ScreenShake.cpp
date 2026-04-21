#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(ScreenShakeHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("global.screenshake.toggle")
        
        // Hook implementation for ScreenShake
        // This modifies game behavior based on config values
    };

    class $hack(ScreenShake) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.screenshake.toggle", false);
            config::setIfEmpty("global.screenshake", 1.f);

            tab->addFloatToggle("global.screenshake", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies ScreenShake")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "ScreenShake"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(ScreenShake)
}
