#include <Geode/modify/DialogLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(DisablePopupsHook, DialogLayer) {
        ADD_HOOKS_DELEGATE("global.disablepopups.toggle")
        
        // Hook implementation for DisablePopups
        // This modifies game behavior based on config values
    };

    class $hack(DisablePopups) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disablepopups.toggle", false);
            config::setIfEmpty("global.disablepopups", 1.f);

            tab->addFloatToggle("global.disablepopups", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisablePopups")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisablePopups"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisablePopups)
}
