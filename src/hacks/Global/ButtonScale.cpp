#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>

namespace eclipse::hacks::Global {
    class $hack(ButtonScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.buttonscale.toggle", false);
            config::setIfEmpty("global.buttonscale", 1.f);

            tab->addFloatToggle("global.buttonscale", 0.5f, 2.5f, "%.2f")
                ->setDescription("Scales button sizes in menus")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Button Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -15; }
    };

    REGISTER_HACK(ButtonScale)

    class $modify(ButtonScaleBtnHook, CCMenuItemSpriteExtra) {
        ADD_HOOKS_DELEGATE("global.buttonscale")

        void setScale(float scale) override {
            float buttonScale = config::get<float>("global.buttonscale", 1.f);
            CCMenuItemSpriteExtra::setScale(scale * buttonScale);
        }
    };
}
