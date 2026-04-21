#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(CursorScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.cursorscale.toggle", false);
            config::setIfEmpty("global.cursorscale", 1.f);

            tab->addFloatToggle("global.cursorscale", 0.5f, 3.0f, "%.2f")
                ->setDescription("Scales cursor size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Cursor Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -18; }
    };

    REGISTER_HACK(CursorScale)
}
