#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(EditorsGuidelines) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.editorsguidelines.toggle", false);

            tab->addToggle("creator.editorsguidelines")
                ->setDescription("Show editor guidelines")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Editor Guidelines"; }
        [[nodiscard]] int32_t getPriority() const override { return -88; }
    };

    REGISTER_HACK(EditorsGuidelines)
}
