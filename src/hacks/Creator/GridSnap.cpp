#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(GridSnap) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.gridsnap.toggle", false);

            tab->addToggle("creator.gridsnap")
                ->setDescription("Enable grid snapping in editor")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Grid Snap"; }
        [[nodiscard]] int32_t getPriority() const override { return -97; }
    };

    REGISTER_HACK(GridSnap)
}
