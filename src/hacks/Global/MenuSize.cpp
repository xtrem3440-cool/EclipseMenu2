#include <Geode/modify/MenuLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(MenuSizeHook, MenuLayer) {
        ADD_HOOKS_DELEGATE("global.menusize.toggle")
        
        // Hook implementation for MenuSize
        // This modifies game behavior based on config values
    };

    class $hack(MenuSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.menusize.toggle", false);
            config::setIfEmpty("global.menusize", 1.f);

            tab->addFloatToggle("global.menusize", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies MenuSize")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "MenuSize"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(MenuSize)
}
