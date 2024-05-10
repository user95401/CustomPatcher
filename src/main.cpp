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
    auto texture_name = CCString::createWithFormat("icons/%s_%02d.png", keyForType(type).c_str(), index)->getCString();
    auto plist_name = CCString::createWithFormat("icons/%s_%02d.plist", keyForType(type).c_str(), index)->getCString();
    if (not CCTextureCache::sharedTextureCache()->textureForKey(texture_name)) {
        CCTextureCache::sharedTextureCache()->addImage(texture_name, 0);
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plist_name);
    };
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

#include <Geode/modify/SimplePlayer.hpp>
class $modify(SimplePlayer) {
    void updatePlayerFrame(int p0, IconType p1) {
        auto index = p0;
        auto type = p1;
        //not simple ones
        if (type == IconType::Robot) {
            SimplePlayer::updatePlayerFrame(index, type);
            return;
        }
        if (type == IconType::Spider) {
            SimplePlayer::updatePlayerFrame(index, type);
            return;
        }
        //update frames
        auto names = frameNamesInVec(index, type);
        setFrames(names[0], names[1], names[2], names[3], names[4]);
    }
};

#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
    int countForType(IconType p0) {
        auto rtn = GameManager::countForType(p0);
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
class $modify(GJGarageLayer) {
    void setupIconSelect() {
        GJGarageLayer::setupIconSelect();
        log::debug("{}", __func__);
        if ((int)m_iconType == 0) m_iconType = GameManager::get()->m_playerIconType;
        if (m_iconID == 0) m_iconID = GameManager::get()->activeIconForType(m_iconType);
        m_playerObject->updatePlayerFrame(m_iconID, m_iconType);
        selectTab(m_iconType);
    };
    void setupSpecialPage() {
        //remove dots arrows selectors, all the stuff
        this->setupPage(0, IconType::DeathEffect);
        m_iconSelection->removeAllChildrenWithCleanup(false);
        return;
    }
};

#include <Geode/modify/LoadingLayer.hpp>
class $modify(LoadingLayer) {
    void loadingFinished() {
        //load new stuff also asd
        int LoadCustomSpritesheet = Mod::get()->getSettingValue<bool>("LoadCustomSpritesheet");
        if (LoadCustomSpritesheet) {
            //"LoadCustomSpritesheet", true, "; load frames via \"icons/_IconsSheet.plist\""
            {
                auto TarFile = "icons/_IconsSheet.plist";
                log::info("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile);
            };
            {
                auto TarFile = "_IconsSheet.plist";
                log::info("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile);
            };
        };
        LoadingLayer::loadingFinished();
    };
};