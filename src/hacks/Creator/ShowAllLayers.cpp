#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(ShowAllLayers) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.showalllayers.toggle", false);

            tab->addToggle("creator.showalllayers")
                ->setDescription("Display all editor layers")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Show All Layers"; }
        [[nodiscard]] int32_t getPriority() const override { return -91; }
    };

    REGISTER_HACK(ShowAllLayers)
}
