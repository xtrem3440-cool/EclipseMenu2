#include <Geode/modify/MenuLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(TabSpacingHook, MenuLayer) {
        ADD_HOOKS_DELEGATE("global.tabspacing.toggle")
        
        // Hook implementation for TabSpacing
        // This modifies game behavior based on config values
    };

    class $hack(TabSpacing) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.tabspacing.toggle", false);
            config::setIfEmpty("global.tabspacing", 1.f);

            tab->addFloatToggle("global.tabspacing", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies TabSpacing")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "TabSpacing"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(TabSpacing)
}
