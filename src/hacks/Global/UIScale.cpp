#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/CCNode.hpp>

namespace eclipse::hacks::Global {
    class $hack(UIScale) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.uiscale.toggle", false);
            config::setIfEmpty("global.uiscale", 1.f);

            tab->addFloatToggle("global.uiscale", 0.5f, 3.0f, "%.2f")
                ->setDescription("Scales all UI elements in menus")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "UI Scale"; }
        [[nodiscard]] int32_t getPriority() const override { return -11; }
    };

    REGISTER_HACK(UIScale)

    class $modify(UIScaleCCNodeHook, cocos2d::CCNode) {
        ADD_HOOKS_DELEGATE("global.uiscale")

        void setScale(float scale) override {
            float uiScale = config::get<float>("global.uiscale", 1.f);
            cocos2d::CCNode::setScale(scale * uiScale);
        }
    };
}
