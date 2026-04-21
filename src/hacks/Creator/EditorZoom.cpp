#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(EditorZoom) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.editorzoom.toggle", false);
            config::setIfEmpty("creator.editorzoom", 1.f);

            tab->addFloatToggle("creator.editorzoom", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts editor zoom level")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Editor Zoom"; }
        [[nodiscard]] int32_t getPriority() const override { return -89; }
    };

    REGISTER_HACK(EditorZoom)
}
