#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Level {
    class $hack(LevelZoom) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.level");

            config::setIfEmpty("level.levelzoom.toggle", false);
            config::setIfEmpty("level.levelzoom", 1.f);

            tab->addFloatToggle("level.levelzoom", 0.1f, 5.0f, "%.2f")
                ->setDescription("Zooms the level view")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Level Zoom"; }
        [[nodiscard]] int32_t getPriority() const override { return -69; }
    };

    REGISTER_HACK(LevelZoom)
}
