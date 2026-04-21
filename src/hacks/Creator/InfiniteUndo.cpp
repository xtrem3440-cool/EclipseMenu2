#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(InfiniteUndo) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.infiniteundo.toggle", false);

            tab->addToggle("creator.infiniteundo")
                ->setDescription("Unlimited undo history")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Infinite Undo"; }
        [[nodiscard]] int32_t getPriority() const override { return -90; }
    };

    REGISTER_HACK(InfiniteUndo)
}
