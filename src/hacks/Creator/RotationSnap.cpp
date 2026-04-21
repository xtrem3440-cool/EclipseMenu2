#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(RotationSnap) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.rotationsnap.toggle", false);
            config::setIfEmpty("creator.rotationsnap", 15.f);

            tab->addFloatToggle("creator.rotationsnap", 1.f, 90.f, "%.0f")
                ->setDescription("Adjusts rotation snap angle")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Rotation Snap"; }
        [[nodiscard]] int32_t getPriority() const override { return -96; }
    };

    REGISTER_HACK(RotationSnap)
}
