#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(GridSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.gridsize.toggle", false);

            tab->addToggle("creator.gridsize")
                ->setDescription("Show editor grid")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Show Grid"; }
        [[nodiscard]] int32_t getPriority() const override { return -86; }
    };

    REGISTER_HACK(GridSize)
}
