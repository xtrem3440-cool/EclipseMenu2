#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(PaletteExpanded) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.paletteexpanded.toggle", false);

            tab->addToggle("creator.paletteexpanded")
                ->setDescription("Auto-expand object palette")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Palette Expanded"; }
        [[nodiscard]] int32_t getPriority() const override { return -92; }
    };

    REGISTER_HACK(PaletteExpanded)
}
