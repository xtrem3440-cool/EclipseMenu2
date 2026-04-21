#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(EditorSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.editorspeed.toggle", false);
            config::setIfEmpty("creator.editorspeed", 1.f);

            tab->addFloatToggle("creator.editorspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts editor movement speed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Editor Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -98; }
    };

    REGISTER_HACK(EditorSpeed)
}
