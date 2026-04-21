#include <Geode/modify/CCDirector.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(CursorScaleHook, CCDirector) {
        ADD_HOOKS_DELEGATE("global.cursorscale.toggle")
        
        // Hook implementation for CursorScale
        // This modifies game behavior based on config values
    };

    class $hack(CursorScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.cursorscale.toggle", false);
            config::setIfEmpty("global.cursorscale", 1.f);

            tab->addFloatToggle("global.cursorscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies CursorScale")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "CursorScale"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(CursorScale)
}
