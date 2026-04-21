#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(DuplicateObjects) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.duplicateobjects.toggle", false);

            tab->addToggle("creator.duplicateobjects")
                ->setDescription("Quick duplicate selected objects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Quick Duplicate"; }
        [[nodiscard]] int32_t getPriority() const override { return -95; }
    };

    REGISTER_HACK(DuplicateObjects)
}
