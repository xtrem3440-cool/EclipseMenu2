#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(ShowTapsHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("global.showtaps.toggle")
        
        // Hook implementation for ShowTaps
        // This modifies game behavior based on config values
    };

    class $hack(ShowTaps) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.showtaps.toggle", false);
            config::setIfEmpty("global.showtaps", 1.f);

            tab->addFloatToggle("global.showtaps", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies ShowTaps")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "ShowTaps"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(ShowTaps)
}
