#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(NoDecorations) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.nodecorations.toggle", false);

            tab->addToggle("level.nodecorations")
                ->setDescription("Hide decorative objects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "No Decorations"; }
        [[nodiscard]] int32_t getPriority() const override { return -74; }
    };

    REGISTER_HACK(NoDecorations)
}
