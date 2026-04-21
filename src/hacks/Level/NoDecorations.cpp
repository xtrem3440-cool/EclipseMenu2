#include <Geode/modify/PlayLayer.hpp>
#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $modify(NoDecorationsHook, PlayLayer) {
        ADD_HOOKS_DELEGATE("level.nodecorations.toggle")
        
        // Hook implementation for NoDecorations
        // This modifies game behavior based on config values
    };

    class $hack(NoDecorations) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.nodecorations.toggle", false);
            config::setIfEmpty("level.nodecorations", 1.f);

            tab->addFloatToggle("level.nodecorations", 0.1f, 5.0f, "%.2f")
                ->setDescription("Modifies NoDecorations")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "NoDecorations"; }
        [[nodiscard]] int32_t getPriority() const override { return 0; }
    };

    REGISTER_HACK(NoDecorations)
}
