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

#include <Geode/loader/SettingEvent.hpp>
//$execute{
//        listenForAllSettingChanges([](SettingValue* hi) {
//                if (bool(hi->getModID() == Mod::get()->getID()) and !CCDirector::get()->m_pRunningScene->getChildByIDRecursive("RELOAD_POP"_spr)) {
//                    auto asd = geode::createQuickPopup(
//                        "Reload All",
//                        "Reload resources to take effect?",
//                        "Later", "Yes",
//                        [](auto, bool btn2) {
//                            if (btn2) GameManager::get()->reloadAll(false, false, true);
//                        }
//                    );
//                    asd->setID("RELOAD_POP"_spr);
//                };
//            });
//};

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

#include <Geode/modify/GJGarageLayer.hpp>
class $modify(GJGarageLayer) {
    /**
     * @note[short] Windows: 0x1f2590
     * @note[short] Android
     */
    void setupSpecialPage() {
        //remove dots arrows selectors, all the stuff
        this->setupPage(0, IconType::DeathEffect);
        m_iconSelection->removeAllChildrenWithCleanup(false);
        return;
    }
};

#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
    int countForType(IconType p0) {
        auto rtn = 4;//GameManager::countForType(p0);
        auto log = fmt::format("{}({})", __func__, (int)p0);
        log::debug("{}", log);
        geode::Notification::create(log)->show();
        int Cube = Mod::get()->getSettingValue<int64_t>("Cube");
        int Ship = Mod::get()->getSettingValue<int64_t>("Ship");
        int Ball = Mod::get()->getSettingValue<int64_t>("Ball");
        int Ufo = Mod::get()->getSettingValue<int64_t>("Ufo");
        int Wave = Mod::get()->getSettingValue<int64_t>("Wave");
        int Robot = Mod::get()->getSettingValue<int64_t>("Robot");
        int Spider = Mod::get()->getSettingValue<int64_t>("Spider");
        int Swing = Mod::get()->getSettingValue<int64_t>("Swing");
        int Jetpack = Mod::get()->getSettingValue<int64_t>("Jetpack");
        int DeathEffect = Mod::get()->getSettingValue<int64_t>("DeathEffect");
        int Special = Mod::get()->getSettingValue<int64_t>("Special");
        int ShipFire = Mod::get()->getSettingValue<int64_t>("ShipFire");
        if (p0 == IconType::Cube) return Cube;//) return 1;
        if (p0 == IconType::Ship) return Ship;//) return 1;
        if (p0 == IconType::Ball) return Ball;//) return 1;
        if (p0 == IconType::Ufo) return Ufo;//) return 1;
        if (p0 == IconType::Wave) return Wave;//) return 1;
        if (p0 == IconType::Robot) return Robot;//) return 1;
        if (p0 == IconType::Spider) return Spider;//) return 1;
        if (p0 == IconType::Swing) return Swing;//) return 1;
        if (p0 == IconType::Jetpack) return Jetpack;//) return 1;
        if (p0 == IconType::DeathEffect) return DeathEffect;//) return 1;
        if (p0 == IconType::Special) return Special;//) return 1;
        if (p0 == IconType::ShipFire) return ShipFire;//) return 1;
        return rtn;
    }
    bool isIconUnlocked(int p0, IconType p1) {
        auto rtn = GameManager::isIconUnlocked(p0, p1);
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
        return rtn;
    }
};