#include <Geode/modify/GameManager.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Bypass {
    class $modify(UnlockIconsHook, GameManager) {
        ADD_HOOKS_DELEGATE("bypass.unlockicons.toggle")
        
        // Hook implementation for UnlockIcons
        // This modifies game behavior based on config values
    };

    class $hack(UnlockIcons) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.bypass");

            config::setIfEmpty("bypass.unlockicons.toggle", false);
            config::setIfEmpty("bypass.unlockicons", 1.f);

            tab->addFloatToggle("bypass.unlockicons", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies UnlockIcons")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UnlockIcons"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(UnlockIcons)
}
