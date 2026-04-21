#include <Geode/modify/CCPhysicsWorld.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(TPSBypassHook, CCPhysicsWorld) {
        ADD_HOOKS_DELEGATE("global.tpsbypass.toggle")
        
        // Hook implementation for TPSBypass
        // This modifies game behavior based on config values
    };

    class $hack(TPSBypass) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.tpsbypass.toggle", false);
            config::setIfEmpty("global.tpsbypass", 1.f);

            tab->addFloatToggle("global.tpsbypass", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies TPSBypass")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "TPSBypass"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(TPSBypass)
}
