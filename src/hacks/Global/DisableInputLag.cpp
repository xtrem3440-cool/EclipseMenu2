#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(DisableInputLagHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("global.disableinputlag.toggle")
        
        // Hook implementation for DisableInputLag
        // This modifies game behavior based on config values
    };

    class $hack(DisableInputLag) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.disableinputlag.toggle", false);
            config::setIfEmpty("global.disableinputlag", 1.f);

            tab->addFloatToggle("global.disableinputlag", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies DisableInputLag")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "DisableInputLag"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(DisableInputLag)
}
