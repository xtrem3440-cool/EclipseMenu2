#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LayerOffset) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.layeroffset.toggle", false);
            config::setIfEmpty("level.layeroffset", 0.f);

            tab->addFloatToggle("level.layeroffset", -1000.f, 1000.f, "%.1f")
                ->setDescription("Offsets layer positioning")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Layer Offset"; }
        [[nodiscard]] int32_t getPriority() const override { return -83; }
    };

    REGISTER_HACK(LayerOffset)
}
