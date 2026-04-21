#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Creator {
    class $hack(AutoSave) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.creator");

            config::setIfEmpty("creator.autosave.toggle", false);

            tab->addToggle("creator.autosave")
                ->setDescription("Auto-save editor changes")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Auto Save"; }
        [[nodiscard]] int32_t getPriority() const override { return -99; }
    };

    REGISTER_HACK(AutoSave)
}
