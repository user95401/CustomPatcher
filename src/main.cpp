#include <Geode/Geode.hpp>
using namespace geode::prelude;

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
template<typename T, typename U> constexpr size_t OFFSETBYMEMBER(U T::* member) {
    return (char*)&((T*)nullptr->*member) - (char*)nullptr;
}
std::string keyForType(IconType type = IconType::Cube) {
    switch ((int)type)
    {
    case 1: return ("ship");
    case 2: return ("player_ball");
    case 3: return ("bird");
    case 4: return ("dart");
    case 5: return ("robot");
    case 6: return ("spider");
    case 7: return ("swing");
    case 8: return ("jetpack");
    default: return ("player");
    };
}
void loadIcon(int index, IconType type) {
    //icons/key_%02index.png
    {
        auto texture_name = CCString::createWithFormat("icons/%s_%02d.png", keyForType(type).c_str(), index)->getCString();
        auto plist_name = CCString::createWithFormat("icons/%s_%02d.plist", keyForType(type).c_str(), index)->getCString();
        if (not CCTextureCache::sharedTextureCache()->textureForKey(texture_name)) {
            CCTextureCache::sharedTextureCache()->addImage(texture_name, 0);
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_name);
        };
    };
    //key_%02index.png
    {
        auto texture_name = CCString::createWithFormat("%s_%02d.png", keyForType(type).c_str(), index)->getCString();
        auto plist_name = CCString::createWithFormat("%s_%02d.plist", keyForType(type).c_str(), index)->getCString();
        if (not CCTextureCache::sharedTextureCache()->textureForKey(texture_name)) {
            CCTextureCache::sharedTextureCache()->addImage(texture_name, 0);
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_name);
        };
    };
    //_IconsSheet.plist
    {
        auto texture_name = "_IconsSheet.png";
        auto plist_name = "_IconsSheet.plist";
        if (not CCTextureCache::sharedTextureCache()->textureForKey(texture_name)) {
            CCTextureCache::sharedTextureCache()->addImage(texture_name, 0);
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_name);
        };
    }
}
std::vector<const char*> frameNamesInVec(int index, IconType type) {
    //load frames
    loadIcon(index, type);
    //naming
    auto lay1_name = CCString::createWithFormat("%s_%02d_001.png", keyForType(type).c_str(), index)->getCString();
    auto lay2_name = CCString::createWithFormat("%s_%02d_2_001.png", keyForType(type).c_str(), index)->getCString();
    auto lay3_name = CCString::createWithFormat("%s_%02d_3_001.png", keyForType(type).c_str(), index)->getCString();
    auto glow_name = CCString::createWithFormat("%s_%02d_glow_001.png", keyForType(type).c_str(), index)->getCString();
    auto extr_name = CCString::createWithFormat("%s_%02d_extra_001.png", keyForType(type).c_str(), index)->getCString();
    //test
    auto placeholder = "emptyGlow.png";
    if (not CCSprite::createWithSpriteFrameName(lay1_name)) lay1_name = placeholder;
    if (not CCSprite::createWithSpriteFrameName(lay2_name)) lay2_name = placeholder;
    if (not CCSprite::createWithSpriteFrameName(lay3_name)) lay3_name = placeholder;
    if (not CCSprite::createWithSpriteFrameName(glow_name)) glow_name = placeholder;
    if (not CCSprite::createWithSpriteFrameName(extr_name)) extr_name = placeholder;
    //rtn
    return { lay1_name, lay2_name, lay3_name, glow_name, extr_name };
}

#include <Geode/modify/PlayerObject.hpp>
class $modify(PlayerObject) {
    auto frame(const char* name) {
        return CCSpriteFrameCache::sharedSpriteFrameCache()
            ->spriteFrameByName(name);
    }
    void customFramesUpate(int index, IconType type, bool forVehicle = false) {
        auto names = frameNamesInVec(index, type);
        if (not forVehicle) {
            if (m_iconSprite) m_iconSprite->setDisplayFrame(frame(names[0]));
            if (m_iconSpriteSecondary) m_iconSpriteSecondary->setDisplayFrame(frame(names[1]));
            if (m_iconSpriteWhitener) m_iconSpriteWhitener->setDisplayFrame(frame(names[4]));
            if (m_iconGlow) m_iconGlow->setDisplayFrame(frame(names[3]));
            //set pos
            this->m_iconSprite->setPosition({
                this->m_iconSprite->displayFrame()->getOriginalSize().width / this->m_iconSprite->getContentSize().width,
                this->m_iconSprite->displayFrame()->getOriginalSize().height / this->m_iconSprite->getContentSize().height,
                });
            this->m_iconSpriteSecondary->setPosition(this->m_iconSprite->getContentSize() / 2);// ({ 16.600f, 16.200f });
            this->m_iconSpriteWhitener->setPosition(this->m_iconSprite->getContentSize() / 2);// ({ 16.800f, 16.200f });
            this->m_iconGlow->setPosition({
                this->m_iconGlow->displayFrame()->getOriginalSize().width / this->m_iconGlow->getContentSize().width,
                this->m_iconGlow->displayFrame()->getOriginalSize().height / this->m_iconGlow->getContentSize().height,
                });
        }
        else {
            if (m_vehicleSprite) m_vehicleSprite->setDisplayFrame(frame(names[0]));
            if (m_vehicleSpriteSecondary) m_vehicleSpriteSecondary->setDisplayFrame(frame(names[1]));
            if (m_vehicleSpriteWhitener) m_vehicleSpriteWhitener->setDisplayFrame(frame(names[4]));
            if (m_vehicleGlow) m_vehicleGlow->setDisplayFrame(frame(names[3]));
            if (m_unk604) m_unk604->setDisplayFrame(frame(names[2]));
            //set pos
            this->m_vehicleSprite->setPosition({
                this->m_vehicleSprite->displayFrame()->getOriginalSize().width / this->m_vehicleSprite->getContentSize().width,
                this->m_vehicleSprite->displayFrame()->getOriginalSize().height / this->m_vehicleSprite->getContentSize().height,
                });
            this->m_vehicleSpriteSecondary->setPosition(this->m_vehicleSprite->getContentSize() / 2);// ({ 16.600f, 16.200f });
            this->m_vehicleSpriteWhitener->setPosition(this->m_vehicleSprite->getContentSize() / 2);// ({ 16.800f, 16.200f });
            this->m_unk604->setPosition(this->m_vehicleSprite->getContentSize() / 2);// ({ 16.800f, 16.200f });
            this->m_vehicleGlow->setPosition({
                this->m_vehicleGlow->displayFrame()->getOriginalSize().width / this->m_vehicleGlow->getContentSize().width,
                this->m_vehicleGlow->displayFrame()->getOriginalSize().height / this->m_vehicleGlow->getContentSize().height,
                });
        };
    }
    int init_id() {
        return getChildByID("init_id")->getTag();
    }
    static PlayerObject* create(int p0, int p1, GJBaseGameLayer * p2, cocos2d::CCLayer * p3, bool p4) {
        auto __this = PlayerObject::create(p0, p1, p2, p3, p4);
        //cube tag
        auto init_id = CCNode::create();
        init_id->setID("init_id");
        init_id->setTag(p0);
        __this->addChild(init_id);
        //preupdate
        __this->updatePlayerFrame(p0);
        return __this;
    }
    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0);
        customFramesUpate(p0, IconType::Cube);
    };
    void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        customFramesUpate(p0, IconType::Ship, true);
        customFramesUpate(init_id(), IconType::Cube);
    };
    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0);
        customFramesUpate(p0, IconType::Ball);
    };
    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        customFramesUpate(p0, IconType::Ufo, true);
        customFramesUpate(init_id(), IconType::Cube);
    };
    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0);
        customFramesUpate(p0, IconType::Wave);
    };
    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0);
        customFramesUpate(p0, IconType::Swing);
    };
    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        customFramesUpate(p0, IconType::Jetpack);
    };
};

#include <Geode/modify/SimplePlayer.hpp>
class $modify(SimplePlayer) {
    void updatePlayerFrame(int p0, IconType p1) {
        auto index = p0;
        auto type = p1;
        SimplePlayer::updatePlayerFrame(index, type);
        //not simple ones
        if (type == IconType::Robot) {
            //SimplePlayer::updatePlayerFrame(index, type);
            return;
        }
        if (type == IconType::Spider) {
            //SimplePlayer::updatePlayerFrame(index, type);
            return;
        }
        //update frames
        auto names = frameNamesInVec(index, type);
        setFrames(names[0], names[1], names[2], names[3], names[4]);
    }
};

#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
#if defined(GEODE_IS_WINDOWS)
    static int countForType(IconType p0) {
        auto rtn = GameManager::countForType(p0);
#else
    int countForType(IconType p0) {
        auto rtn = GameManager::countForType(p0);
#endif
        if (p0 == IconType::Cube) return Mod::get()->getSettingValue<int64_t>("Cube");
        if (p0 == IconType::Ship) return Mod::get()->getSettingValue<int64_t>("Ship");
        if (p0 == IconType::Ball) return Mod::get()->getSettingValue<int64_t>("Ball");
        if (p0 == IconType::Ufo) return Mod::get()->getSettingValue<int64_t>("Ufo");
        if (p0 == IconType::Wave) return Mod::get()->getSettingValue<int64_t>("Wave");
        if (p0 == IconType::Robot) return Mod::get()->getSettingValue<int64_t>("Robot");
        if (p0 == IconType::Spider) return Mod::get()->getSettingValue<int64_t>("Spider");
        if (p0 == IconType::Swing) return Mod::get()->getSettingValue<int64_t>("Swing");
        if (p0 == IconType::Jetpack) return Mod::get()->getSettingValue<int64_t>("Jetpack");
        if (p0 == IconType::DeathEffect) return Mod::get()->getSettingValue<int64_t>("DeathEffect");
        if (p0 == IconType::Special) return Mod::get()->getSettingValue<int64_t>("Special");
        if (p0 == IconType::ShipFire) return Mod::get()->getSettingValue<int64_t>("ShipFire");
        return rtn;
    }
    bool isIconUnlocked(int p0, IconType p1) {
        matjson::Value asd = Mod::get()->getMetadata().getRawJSON();
        if (p1 == IconType::Cube and p0 > asd["settings"]["Cube"]["default"].as_int()) return 1;
        if (p1 == IconType::Ship and p0 > asd["settings"]["Ship"]["default"].as_int()) return 1;
        if (p1 == IconType::Ball and p0 > asd["settings"]["Ball"]["default"].as_int()) return 1;
        if (p1 == IconType::Ufo and p0 > asd["settings"]["Ufo"]["default"].as_int()) return 1;
        if (p1 == IconType::Wave and p0 > asd["settings"]["Wave"]["default"].as_int()) return 1;
        if (p1 == IconType::Robot and p0 > asd["settings"]["Robot"]["default"].as_int()) return 1;
        if (p1 == IconType::Spider and p0 > asd["settings"]["Spider"]["default"].as_int()) return 1;
        if (p1 == IconType::Swing and p0 > asd["settings"]["Swing"]["default"].as_int()) return 1;
        if (p1 == IconType::Jetpack and p0 > asd["settings"]["Jetpack"]["default"].as_int()) return 1;
        return GameManager::isIconUnlocked(p0, p1);
    }
};

#include <Geode/modify/GJGarageLayer.hpp>
class $modify(GJGarageLayerExt, GJGarageLayer) {
    void setupIconSelect() {
        GJGarageLayer::setupIconSelect();
        if ((int)m_iconType == 0) m_iconType = GameManager::get()->m_playerIconType;
        if (m_iconID == 0) m_iconID = GameManager::get()->activeIconForType(m_iconType);
        m_playerObject->updatePlayerFrame(m_iconID, m_iconType);
        selectTab(m_iconType);
    };
    void selectFakeOne(CCObject* sender) {
        this->onSelect(sender);
    }
    void setupSpecialPage() {
        //remove dots arrows selectors, all the stuff
        this->setupPage(0, IconType::DeathEffect);
        m_iconSelection->removeAllChildrenWithCleanup(false);
        m_iconType = IconType::Special;
        m_selectedIconType = IconType::Special;
        //placeholdera
        m_iconSelection->addChild(CCLabelTTF::create("todo...", "arial", 20.f), 1, 85629);
        auto labelnode = m_iconSelection->getChildByTag(85629);
        labelnode->setPosition(m_iconSelectionMenu->getPosition());
        labelnode->setPositionY((labelnode->getPositionY() * 3));
        //get the selector bg
        CCScale9Sprite* selector_bg;
        for (auto i = 0; i < this->getChildrenCount(); i++) {
            if (auto node = cocos::getChild(this, i)) {
                if (selector_bg = typeinfo_cast<CCScale9Sprite*>(node))
                    break;
            }
        }
        //base menu
        auto menu = CCMenu::create();
        {
            m_iconSelection->addChild(menu);
            //make it positioning at bg
            menu->setContentSize(selector_bg->getContentSize() - 12.f);
            menu->setPosition(selector_bg->getPosition());
            //bad eng ya layout here
            menu->setLayout(
                ColumnLayout::create()
                ->setGap(0.f)
                ->setAxisAlignment(AxisAlignment::Even)
                ->setCrossAxisAlignment(AxisAlignment::Start)
                ->setCrossAxisOverflow(false)
                ->setAxisReverse(true)
            );
        }
        //lists base shhit idk
        auto lists_size = CCSize(menu->getContentWidth(), menu->getContentHeight() / 3);
        auto lists_lay = RowLayout::create();
        lists_lay->setGap(4.f);
        lists_lay->setCrossAxisOverflow(false);
        lists_lay->setAxisAlignment(AxisAlignment::Start);
        //trails
        {
            auto trails = CCMenu::create();
            menu->addChild(trails);
            trails->setID("trails");
            trails->setContentSize(lists_size);
            trails->setLayout(lists_lay);
            for (auto i = 1; i <= Mod::get()->getSettingValue<int64_t>("Special"); i++) {
                //sprite
                auto name = CCString::createWithFormat("player_special_%02d_001.png", i)->getCString();
                auto placeholder = CCSprite::createWithSpriteFrameName("player_special_01_001.png");
                auto sprite = CCSprite::createWithSpriteFrameName(name);
                if (not sprite) sprite = placeholder;
                sprite->setScale(0.9f);
                //item
                auto item = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(GJGarageLayerExt::selectFakeOne));
                item->setTag(i);
                trails->addChild(item);
                trails->updateLayout();
            }
        }
        //ship_fires
        {
            auto ship_fires = CCMenu::create();
            menu->addChild(ship_fires);
            ship_fires->setID("ship_fires");
            ship_fires->setContentSize(lists_size);
            ship_fires->setLayout(lists_lay);
            for (auto i = 0; i < Mod::get()->getSettingValue<int64_t>("ShipFire"); i++) {
                //sprite
                auto name = CCString::createWithFormat("shipfireIcon_%02d_001.png", i)->getCString();
                auto placeholder = CCSprite::createWithSpriteFrameName("shipfireIcon_01_001.png");
                auto sprite = CCSprite::createWithSpriteFrameName(name);
                if (not sprite) sprite = placeholder;
                sprite->setScale(0.9f);
                //item
                auto item = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(GJGarageLayerExt::selectFakeOne));
                item->setTag(i);
                ship_fires->addChild(item);
                ship_fires->updateLayout();
            }
        }
        //animation_ext
        {
            auto animation_ext = CCMenu::create();
            menu->addChild(animation_ext);
            animation_ext->setID("animation_ext");
            animation_ext->setContentSize(lists_size);
            animation_ext->setLayout(lists_lay);
            for (auto i = 0; i < 3; i++) {
                auto entry = CircleButtonSprite::create(
                    CCLabelTTF::create(fmt::to_string(i).data(), "arial", 16.f),
                    CircleBaseColor::Gray,
                    CircleBaseSize::Small
                );
                animation_ext->addChild(entry);
                animation_ext->updateLayout();
            }
        }
        menu->updateLayout();
        return;//GJGarageLayer::setupSpecialPage();
    }
};