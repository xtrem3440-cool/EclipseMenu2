#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/GJListLayer.hpp>

namespace eclipse::hacks::Global {
    class $hack(IconSize) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");

            config::setIfEmpty("global.iconsize.toggle", false);
            config::setIfEmpty("global.iconsize", 1.f);

            tab->addFloatToggle("global.iconsize", 0.3f, 3.0f, "%.2f")
                ->setDescription("Scales all icon sizes")->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Icon Size"; }
        [[nodiscard]] int32_t getPriority() const override { return -32; }
    };

    REGISTER_HACK(IconSize)

    class $modify(IconSizeGLHook, GJListLayer) {
        ADD_HOOKS_DELEGATE("global.iconsize")

        void setupList() override {
            GJListLayer::setupList();
            float scale = config::get<float>("global.iconsize", 1.f);
            for (auto child : CCArrayExt<cocos2d::CCNode*>(m_listLayer->m_pChildren)) {
                if (child) child->setScale(child->getScale() * scale);
            }
        }
    };
}
