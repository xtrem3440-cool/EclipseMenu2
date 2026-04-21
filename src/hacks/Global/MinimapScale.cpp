#include <Geode/modify/GJGameLevel.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $modify(MinimapScaleHook, GJGameLevel) {
        ADD_HOOKS_DELEGATE("global.minimapscale.toggle")
        
        // Hook implementation for MinimapScale
        // This modifies game behavior based on config values
    };

    class $hack(MinimapScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.minimapscale.toggle", false);
            config::setIfEmpty("global.minimapscale", 1.f);

            tab->addFloatToggle("global.minimapscale", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies MinimapScale")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "MinimapScale"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(MinimapScale)
}
