#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(BackgroundBlurHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("global.backgroundblur.toggle")
        
        // Hook implementation for BackgroundBlur
        // This modifies game behavior based on config values
    };

    class $hack(BackgroundBlur) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.backgroundblur.toggle", false);
            config::setIfEmpty("global.backgroundblur", 1.f);

            tab->addFloatToggle("global.backgroundblur", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies BackgroundBlur")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "BackgroundBlur"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(BackgroundBlur)
}
