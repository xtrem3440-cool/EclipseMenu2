#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(SelectAllObjects) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.selectallobjects.toggle", false);

            tab->addToggle("creator.selectallobjects")
                ->setDescription("Quick select all objects")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Select All Objects"; }
        [[nodiscard]] int32_t getPriority() const override { return -94; }
    };

    REGISTER_HACK(SelectAllObjects)
}
