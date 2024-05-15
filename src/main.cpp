#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include <regex>

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
template<typename T, typename U> constexpr size_t OFFSETBYMEMBER(U T::* member) {
    return (char*)&((T*)nullptr->*member) - (char*)nullptr;
}
std::vector<std::string> explode(std::string separator, std::string input) {
    std::vector<std::string> vec;
    for (int i{ 0 }; i < input.length(); ++i) {
        int pos = input.find(separator, i);
        if (pos < 0) { vec.push_back(input.substr(i)); break; }
        int count = pos - i;
        vec.push_back(input.substr(i, count));
        i = pos + separator.length() - 1;
    }
    if (vec.size() == 0) vec.push_back(input);/*
    std::stringstream log;
    for (auto item : vec)
        log << std::endl << item << std::endl;
    log::debug("{}(separator \"{}\", input \"{}\").rtn({})", __FUNCTION__, separator, input, log.str());*/
    return vec;
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
IconType typeForKey(std::string key) {
    auto rtn = 0;//player
    if (key == "ship") rtn = 1;
    if (key == "player_ball") rtn = 2;
    if (key == "bird") rtn = 3;
    if (key == "dart") rtn = 4;
    if (key == "robot") rtn = 5;
    if (key == "spider") rtn = 6;
    if (key == "swing") rtn = 7;
    if (key == "jetpack") rtn = 8;
    //log::debug("{}({}) = {}({})", __FUNCTION__, key, rtn, keyForType((IconType)rtn));
    return (IconType)rtn;
}
void loadIcon(int index, IconType type) {
    //icons/key_%02index.png
    {
        ghc::filesystem::path texture_path = CCString::createWithFormat("icons/%s_%02d.png", keyForType(type).c_str(), index)->getCString();
        ghc::filesystem::path plist_path = CCString::createWithFormat("icons/%s_%02d.plist", keyForType(type).c_str(), index)->getCString();
        auto texture_filepath = texture_path.string();
        auto texture_key = texture_path.filename().string();
        auto plist_filepath = plist_path.string();
        if (not CCTextureCache::sharedTextureCache()->m_pTextures->objectForKey(texture_key.data())) {
            if (CCFileUtils::sharedFileUtils()->isFileExist(texture_filepath.data())) {
                log::debug(
                    "no texture for \"{}\" key, adding image \"{}\"... result: {}",
                    texture_key, texture_filepath,
                    CCTextureCache::sharedTextureCache()->addImage(texture_filepath.data(), 0)
                );
            };
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_filepath.data());
        };
    };
    //_IconsSheet.plist
    {
        ghc::filesystem::path texture_path = "_IconsSheet.png";
        ghc::filesystem::path plist_path = "_IconsSheet.plist";
        auto texture_filepath = texture_path.string();
        auto texture_key = texture_path.filename().string();
        auto plist_filepath = plist_path.string();
        if (not CCTextureCache::sharedTextureCache()->m_pTextures->objectForKey(texture_key.data())) {
            if (CCFileUtils::sharedFileUtils()->isFileExist(texture_filepath.data())) {
                log::debug(
                    "no texture for \"{}\" key, adding image \"{}\"... result: {}",
                    texture_key, texture_filepath,
                    CCTextureCache::sharedTextureCache()->addImage(texture_filepath.data(), 0)
                );
            };
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_filepath.data());
        };
    }
}
std::vector<const char*> frameNamesInVec(int index, IconType type) {
    //naming
    auto lay1_name = CCString::createWithFormat("%s_%02d_001.png", keyForType(type).c_str(), index)->getCString();
    auto lay2_name = CCString::createWithFormat("%s_%02d_2_001.png", keyForType(type).c_str(), index)->getCString();
    auto lay3_name = CCString::createWithFormat("%s_%02d_3_001.png", keyForType(type).c_str(), index)->getCString();
    auto glow_name = CCString::createWithFormat("%s_%02d_glow_001.png", keyForType(type).c_str(), index)->getCString();
    auto extr_name = CCString::createWithFormat("%s_%02d_extra_001.png", keyForType(type).c_str(), index)->getCString();
    //load frames
    loadIcon(index, type);
    //test
    auto placeholder = "emptyGlow.png";
    auto pSpriteFrames = CCSpriteFrameCache::sharedSpriteFrameCache()->m_pSpriteFrames;
    if (not pSpriteFrames->objectForKey(lay1_name)) lay1_name = placeholder;
    if (not pSpriteFrames->objectForKey(lay2_name)) lay2_name = placeholder;
    if (not pSpriteFrames->objectForKey(lay3_name)) lay3_name = placeholder;
    if (not pSpriteFrames->objectForKey(glow_name)) glow_name = placeholder;
    if (not pSpriteFrames->objectForKey(extr_name)) extr_name = placeholder;
    //rtn
    return { lay1_name, lay2_name, lay3_name, glow_name, extr_name };
}

#include <Geode/modify/PlayerObject.hpp>
class $modify(PlayerObjectExt, PlayerObject) {
    static void loadShipStreak() {
        return;
        auto shipStreak = GameManager::get()->getPlayerShipFire();
        for (auto index = 1; index <= 60; index++) {
            auto texture_name = CCString::createWithFormat("shipfire%02d_%03d.png", shipStreak, index)->getCString();
            if (not CCTextureCache::sharedTextureCache()->textureForKey(texture_name)) {
                CCTextureCache::sharedTextureCache()->addImage(texture_name, 0);
            };
        };
    }
    static PlayerObject* create(int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4) {
        loadShipStreak();
        auto __this = PlayerObject::create(p0, p1, p2, p3, p4);
        //cube tag
        auto init_id = CCNode::create();
        {
            init_id->setID("init_id");
            init_id->setTag(p0);
            __this->addChild(init_id);
        };
        //preload frames
        {
            loadIcon(p0, IconType::Cube);//
            loadIcon(p0, IconType::Ship);// = 1,
            loadIcon(p0, IconType::Ball);// = 2,
            loadIcon(p0, IconType::Ufo);// = 3,
            loadIcon(p0, IconType::Wave);// = 4,
            loadIcon(p0, IconType::Robot);//= 5,
            loadIcon(p0, IconType::Spider);// = 6,
            loadIcon(p0, IconType::Swing);// = 7,
            loadIcon(p0, IconType::Jetpack);// = 8,
            loadIcon(p0, IconType::DeathEffect);// = 98,
            loadIcon(p0, IconType::Special);// = 99,
            loadIcon(p0, IconType::ShipFire);// = 101,
        };
        //preupdate cube
        ((PlayerObjectExt*)__this)->customFramesUpateFor(p0, IconType::Cube);
        //also update trail
        {
            auto texture_name = CCString::createWithFormat(
                "streak_%02d_001.png",
                GameManager::get()->getPlayerStreak()
            )->getCString();
            auto texture = CCTextureCache::sharedTextureCache()->textureForKey(texture_name);
            if (not texture) {
                CCTextureCache::sharedTextureCache()->reloadTexture(texture_name);
                texture = CCTextureCache::sharedTextureCache()->textureForKey(texture_name);
            }
            if (__this->m_regularTrail and texture) __this->m_regularTrail->setTexture(texture);
        };
        //
        return __this;
    }
    int init_id() {
        auto init_id = getChildByID("init_id");
        return init_id ? init_id->getTag() : 0;
    }
    static auto frame(const char* name) {
        return CCSpriteFrameCache::sharedSpriteFrameCache()
            ->spriteFrameByName(name);
    }
    void customFramesUpateFor(int index, IconType type, bool forVehicle = false) {
        if (not (GameManager::get()->m_playLayer or GameManager::get()->m_levelEditorLayer)) return;
        {
            if (not m_iconSprite) return;
            if (not m_iconSprite) return;
            if (not m_iconSpriteSecondary) return;
            if (not m_iconSpriteWhitener) return;
            if (not m_iconGlow) return;
            if (not m_vehicleSprite) return;
            if (not m_vehicleSpriteSecondary) return;
            if (not m_unk604) return;
            if (not m_vehicleSpriteWhitener) return;
            if (not m_vehicleGlow) return;
        };
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
    void updatePlayerSpriteExtra(gd::string p0) {
        PlayerObject::updatePlayerSpriteExtra(p0);
        auto key = std::string("player");
        auto expl = explode("_", p0);
        if (expl[1] == "ball") key = key + "_ball";
        else key = expl[0];
        auto type = typeForKey(key);
        auto user_icon = GameManager::get()->activeIconForType(type);
        auto tar_icon = std::stoi(expl[expl.size() - 2]);
        customFramesUpateFor(tar_icon, type);
    }
    void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        customFramesUpateFor(p0, IconType::Ship, true);
        customFramesUpateFor(init_id(), IconType::Cube);
    };
    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        customFramesUpateFor(p0, IconType::Ufo, true);
        customFramesUpateFor(init_id(), IconType::Cube);
    };
    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        customFramesUpateFor(p0, IconType::Jetpack, true);
        customFramesUpateFor(init_id(), IconType::Cube);
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
        auto item = dynamic_cast<CCMenuItemSpriteExtra*>(sender);
        auto menu = dynamic_cast<CCMenu*>(item->getParent());
        if (not item) return;
        //action
        if (item->getParent()->getID() == "trails") {
            //cursor
            m_cursor1->setVisible(true);
            m_cursor1->setPosition(menu->convertToWorldSpace(item->getPosition()));
            //userstats
            GameManager::get()->setPlayerStreak(item->getTag());
        }
        if (item->getParent()->getID() == "ship_fires") {
            //cursor
            m_cursor2->setVisible(true);
            m_cursor2->setPosition(menu->convertToWorldSpace(item->getPosition()));
            //userstats
            GameManager::get()->setPlayerShipStreak(item->getTag());
        }
    }
    void setupSpecialPage() {
        //remove dots arrows selectors, all the stuff
        this->setupPage(0, IconType::DeathEffect);
        m_iconSelection->removeAllChildrenWithCleanup(false);
        //placeholdera
        m_iconSelection->addChild(CCLabelTTF::create("UNFINISHED...", "arial", 20.f), 1, 85629);
        auto labelnode = m_iconSelection->getChildByTag(85629);
        labelnode->setPosition(m_iconSelectionMenu->getPosition());
        labelnode->setPositionY((labelnode->getPositionY() * 2.5f));
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
            menu->setContentSize({
                selector_bg->getContentSize().width - 30.f,
                selector_bg->getContentSize().height - 12.f
                });
            menu->setPosition(selector_bg->getPosition());
            //bad eng ya layout here
            menu->setLayout(
                ColumnLayout::create()
                ->setGap(3.f)
                ->setAxisAlignment(AxisAlignment::Even)
                ->setCrossAxisAlignment(AxisAlignment::Start)
                ->setCrossAxisOverflow(true)
                ->setAutoScale(false)
                ->setAxisReverse(true)
            );
        }
        //lists base shhit idk
        auto lists_size = CCSize(menu->getContentWidth(), menu->getContentHeight() / 3);
        auto lists_items_scale = 0.86f;
        auto lists_lay = RowLayout::create();
        lists_lay->setGap(6.f);
        lists_lay->setCrossAxisOverflow(false);
        lists_lay->setAxisAlignment(AxisAlignment::Start);
        //trails
        auto trails = CCMenu::create();
        {
            menu->addChild(trails);
            trails->setID("trails");
            trails->setContentSize(lists_size);
            trails->setLayout(lists_lay);
            for (auto i = 1; i <= Mod::get()->getSettingValue<int64_t>("Special"); i++) {
                //sprite
                auto name = CCString::createWithFormat("player_special_%02d_001.png", i)->getCString();
                auto placeholder = CCSprite::createWithSpriteFrameName("player_special_01_001.png");
                auto sprite = CCSprite::createWithSpriteFrameName(name);
                if (not sprite) sprite = CCSprite::create(name);
                if (not sprite) sprite = placeholder;
                sprite->setScale(lists_items_scale);
                //item
                auto item = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(GJGarageLayerExt::selectFakeOne));
                item->setTag(i);
                trails->addChild(item);
                trails->updateLayout();
            }
        }
        //ship_fires
        auto ship_fires = CCMenu::create();
        {
            menu->addChild(ship_fires);
            ship_fires->setID("ship_fires");
            ship_fires->setContentSize(lists_size);
            ship_fires->setLayout(lists_lay);
            for (auto i = 1; i < Mod::get()->getSettingValue<int64_t>("ShipFire"); i++) {
                //sprite
                auto name = CCString::createWithFormat("shipfireIcon_%02d_001.png", i)->getCString();
                auto placeholder = CCSprite::createWithSpriteFrameName("shipfireIcon_01_001.png");
                auto sprite = CCSprite::createWithSpriteFrameName(name);
                if (not sprite) sprite = CCSprite::create(name);
                if (not sprite) sprite = placeholder;
                sprite->setScale(lists_items_scale);
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
        //update
        menu->updateLayout();
        //move cursor1 to trail
        dynamic_cast<CCMenuItemSpriteExtra*>(
            trails->getChildByTag(GameManager::get()->getPlayerStreak())
            )->activate();
        //move cursor2 to ship trail
        dynamic_cast<CCMenuItemSpriteExtra*>(
            ship_fires->getChildByTag(GameManager::get()->getPlayerShipFire())
            )->activate();
        return;//GJGarageLayer::setupSpecialPage();
    }
};

#include <Geode/modify/ItemInfoPopup.hpp>
class $modify(ItemInfoPopupExt, ItemInfoPopup) {
    static ItemInfoPopup* create(int p0, UnlockType p1) {
        auto __this = ItemInfoPopup::create(p0, p1);
        //nodes
        CCLabelBMFont* title = nullptr;
        CCLabelBMFont* box_title = nullptr;
        TextArea* box_text = nullptr;
        for (auto i = 0; i < __this->m_mainLayer->getChildrenCount(); i++) {
            if (auto node = cocos::getChild(__this->m_mainLayer, i)) {
                if (auto label = dynamic_cast<CCLabelBMFont*>(node)) {
                    if (not title) title = label;
                    else if (not box_title) box_title = label;
                }
                if (auto text = dynamic_cast<TextArea*>(node)) {
                    box_text = text;
                }
            }
        }
        if (!box_title) {
            box_title = CCLabelBMFont::create("", title->getFntFile());
            __this->m_buttonMenu->addChild(box_title);
            box_title->setScale(0.55f);
            box_title->setPositionY(98.f);
            auto filename = (title->getString() + std::string(" Title.txt"));
            box_title->setString(fmt::format("Can't find \"{}\"!", filename).data());
            auto path = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.data(), 0);
            auto in = std::ifstream(path);
            if (in.is_open()) {
                auto sstr = std::stringstream() << in.rdbuf();
                box_title->setString(sstr.str().data());
            }
        }
        if (!box_text) {
            box_text = TextArea::create("", "bigFont.fnt", 1.0f, 1000, { 0.5f, 0.5f }, 42.f, 0);
            __this->m_buttonMenu->addChild(box_text);
            box_text->setScale(0.35f);
            box_text->setPositionY(65.f);
            auto filename = (title->getString() + std::string(" Text.txt"));
            box_text->setString(fmt::format("<cr>And can't find \"</c><co>{}</c><cr>\"...</c>", filename).data());
            auto path = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.data(), 0);
            auto in = std::ifstream(path);
            if (in.is_open()) {
                auto sstr = std::stringstream() << in.rdbuf();
                box_text->setString(sstr.str().data());
            }
        }
        return __this;
    }
};
