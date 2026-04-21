#include <Geode/modify/CCScheduler.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(FPSBypassHook, CCScheduler) {
        ADD_HOOKS_DELEGATE("global.fpsbypass.toggle")
        
        // Hook implementation for FPSBypass
        // This modifies game behavior based on config values
    };

    class $hack(FPSBypass) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.fpsbypass.toggle", false);
            config::setIfEmpty("global.fpsbypass", 1.f);

            tab->addFloatToggle("global.fpsbypass", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies FPSBypass")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "FPSBypass"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(FPSBypass)
}
