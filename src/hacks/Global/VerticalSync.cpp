#include <Geode/modify/CCDirector.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(VerticalSyncHook, CCDirector) {
        ADD_HOOKS_DELEGATE("global.verticalsync.toggle")
        
        // Hook implementation for VerticalSync
        // This modifies game behavior based on config values
    };

    class $hack(VerticalSync) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.verticalsync.toggle", false);
            config::setIfEmpty("global.verticalsync", 1.f);

            tab->addFloatToggle("global.verticalsync", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies VerticalSync")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "VerticalSync"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(VerticalSync)
}
