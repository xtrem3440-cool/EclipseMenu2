#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(ObjectSnapSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.objectsnapsize.toggle", false);
            config::setIfEmpty("creator.objectsnapsize", 1.f);

            tab->addFloatToggle("creator.objectsnapsize", 0.1f, 5.0f, "%.2f")
                ->setDescription("Adjusts snap grid size")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Object Snap Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -87; }
    };

    REGISTER_HACK(ObjectSnapSize)
}
