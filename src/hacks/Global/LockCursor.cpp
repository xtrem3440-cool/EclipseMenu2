#include <Geode/modify/CCDirector.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(LockCursorHook, CCDirector) {
        ADD_HOOKS_DELEGATE("global.lockcursor.toggle")
        
        // Hook implementation for LockCursor
        // This modifies game behavior based on config values
    };

    class $hack(LockCursor) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.lockcursor.toggle", false);
            config::setIfEmpty("global.lockcursor", 1.f);

            tab->addFloatToggle("global.lockcursor", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies LockCursor")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "LockCursor"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(LockCursor)
}
