#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(PreviewSpeed) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.previewspeed.toggle", false);
            config::setIfEmpty("creator.previewspeed", 1.f);

            tab->addFloatToggle("creator.previewspeed", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts editor preview speed")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Preview Speed"; }
        [[nodiscard]] int32_t getPriority() const override { return -93; }
    };

    REGISTER_HACK(PreviewSpeed)
}
