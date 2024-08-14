#include "_main.hpp"

inline void PB10(std::string str_addr, std::string str_int10_list, std::string comment = "") {
    str_addr = string::replace(str_addr, "GeometryDash.exe+", "");
    ByteVector data;
    for (std::string str_byte : string::explode(" ", str_int10_list)) {
        data.push_back(utils::numFromString<uint8_t>(str_byte, 10).value_or(0));
    };
    patch(
        base::get() + utils::numFromString<int>(str_addr, 16).value_or(0),
        data,
        comment
    );
}
inline std::vector<std::string> bytesAsIntStrs(int value) {
    std::vector<std::string> result;
    for (int byteInt : intToBytes(value)) result.push_back(numToString(byteInt));
    return result;
}

void ruinGame() {
    
    auto Fonts = bytesAsIntStrs(SETTING(int64_t, "Fonts"));
    auto Backgrounds = bytesAsIntStrs(SETTING(int64_t, "Backgrounds"));
    auto Grounds = bytesAsIntStrs(SETTING(int64_t, "Grounds"));
    auto MiddleGrounds = bytesAsIntStrs(SETTING(int64_t, "MiddleGrounds"));
    auto LoadingLayerBackground = bytesAsIntStrs(SETTING(int64_t, "LoadingLayerBackground"));
    auto Cubes = bytesAsIntStrs(SETTING(int64_t, "Cubes"));
    auto Ships = bytesAsIntStrs(SETTING(int64_t, "Ships"));
    auto Balls = bytesAsIntStrs(SETTING(int64_t, "Balls"));
    auto Ufos = bytesAsIntStrs(SETTING(int64_t, "Ufos"));
    auto Waves = bytesAsIntStrs(SETTING(int64_t, "Waves"));
    auto Robots = bytesAsIntStrs(SETTING(int64_t, "Robots"));
    auto Spiders = bytesAsIntStrs(SETTING(int64_t, "Spiders"));
    auto Swings = bytesAsIntStrs(SETTING(int64_t, "Swings"));
    auto Jetpacks = bytesAsIntStrs(SETTING(int64_t, "Jetpacks"));
    auto DeathEffects = bytesAsIntStrs(SETTING(int64_t, "DeathEffects"));
    auto Specials = bytesAsIntStrs(SETTING(int64_t, "Specials"));
    auto ShipFires = bytesAsIntStrs(SETTING(int64_t, "ShipFires"));

#define v3(...) __VA_ARGS__[0], __VA_ARGS__[1], __VA_ARGS__[2], __VA_ARGS__[3]
#define v2(...) __VA_ARGS__[0], __VA_ARGS__[1], __VA_ARGS__[2]
#define fmt(...) fmt::format(__VA_ARGS__)

    //======================================WPuFTbl===================================
    //59

    PB10("GeometryDash.exe+1797CA", fmt("184 {} {} {} {}", v3(Fonts)), "//");
    PB10("GeometryDash.exe+27C8BC", fmt("184 {} {} {} {}", v3(Fonts)), "// - MACCuB WPuFTOB");
    PB10("GeometryDash.exe+27C7B2", fmt("187 {} {} {} {}", v3(Fonts)), "//         - BuDuMOCTb WPuFTOB ");

    PB10("GeometryDash.exe+17987A", fmt("184 {} {} {} {}", v3(Fonts)), "//   - WPuFT. (?)");
    PB10("GeometryDash.exe+181A22", fmt("187 {} {} {} {}", v3(Fonts)), "//    - WPuFT2. (?)");
    PB10("GeometryDash.exe+1FFAE7", fmt("187 {} {} {} {}", v3(Fonts)), "//     - WPuFT3. (?)");
    PB10("GeometryDash.exe+2CB650", fmt("187 {} {} {} {}", v3(Fonts)), "//     - WPuFT4. (?)");
    PB10("GeometryDash.exe+A4E78", fmt("191 {} {} {} {}", v3(Fonts)), "//      - WPuFT5. (?)");
    PB10("GeometryDash.exe+A51CF", fmt("131 248 {} 15 76", Fonts[0]), "//       - WPuFT6 - TEXT?. (?)");
    PB10("GeometryDash.exe+19D82C", fmt("187 {} {} {} {}", v3(Fonts)), "//        - WPuFT7 - . (?)");

    PB10("GeometryDash.exe+383E3A", fmt("187 {} {} {} {}", v3(Fonts)), "//          - WPuFT9 - . (?)");
    PB10("GeometryDash.exe+487140", fmt("187 {} {} {} {}", v3(Fonts)), "//           - WPuFT10 - . (?)");



    PB10("GeometryDash.exe+3669A4", fmt("186 {} {} {} {}", v3(Specials)), "//     - BuguMocTb TpeuJlbl B urpoBoM noJle (+ pegakTop)");


    //======================================FOHbl===================================
    //59
    PB10("GeometryDash.exe+49D190", fmt("131 255 {} 126 203", Backgrounds[0]), "// - 6r (?)");
    PB10("GeometryDash.exe+495F70", fmt("184 {} {} {} {}", v3(Backgrounds)), "//  - 6r2 (?)");
    PB10("GeometryDash.exe+1FC6A0", fmt("131 255 {} 15 76", v3(Backgrounds)), "//   - 6r3 (nPuKOJl: Bbl6OP FOHA JlOMAETC9l)");
    PB10("GeometryDash.exe+1E949F", fmt("184 {} {} {} {}", v3(Backgrounds)), "//    - 6r4 (?)");


    PB10("GeometryDash.exe+1FC630", fmt("189 {} {} {} {}", v3(Backgrounds)), "// - 6r FOH B urPE");
    PB10("GeometryDash.exe+310B99", fmt("185 {} {} {} {}", v3(Backgrounds)), "//   - 6r B rJl MeHl-o");
    PB10("GeometryDash.exe+30DD22", fmt("186 {} {} {} {}", v3(LoadingLayerBackground)), "//  - 6r B 3arpy3o4Hou cueHe..");
    PB10("GeometryDash.exe+301D54", fmt("65 189 {} {} {} {}", v3(Backgrounds)), "// - MaccuB kHonku 6r");

    PB10("GeometryDash.exe+44644F", fmt("184 {} {} {} {}", v3(Backgrounds)), "// - 6rKHonka (?)");
    PB10("GeometryDash.exe+445BCD", fmt("184 {} {} {} {}", v3(Backgrounds)), "//  - 6rKHonka2 (?)");
    PB10("GeometryDash.exe+2FF5CA", fmt("186 {} {} {} {}", v3(Backgrounds)), "//   - 6rKHonka3 (?)");
    PB10("GeometryDash.exe+2FF5C5", fmt("131 250 {} 126 7", Backgrounds[0]), "//    - 6rKHonka4 (?)");


    //======================================nOJlbl===================================
    //22
    PB10("GeometryDash.exe+179C2A", fmt("184 {} {} {} {}", v3(Grounds)), "// - nOJl B rJl MeHl-o ");
    PB10("GeometryDash.exe+26C0FB", fmt("184 {} {} {} {}", v3(Grounds)), "//  - nOJl B urpe");
    PB10("GeometryDash.exe+301D7B", fmt("65 189 {} {} {} {}", v3(Grounds)), "// - MaccuB kHonku nOJl");


    PB10("GeometryDash.exe+495E34", fmt("184 {} {} {} {}", v3(Grounds)), "// noJlbl (?)");

    //=====================================CPEDHEE nOJlE============================
    //3
    PB10("GeometryDash.exe+301DB1", fmt("68 141 104 {} 235", v3(MiddleGrounds)), "//  - MACCuB KHOnKu CPEDHEE nOJlE");

    PB10("GeometryDash.exe+1799DA", fmt("184 {} {} {} {}", v3(MiddleGrounds)), "// -  CPEDHEE nOJlE (?)");
    PB10("GeometryDash.exe+179C8C", fmt("131 248 {} 119 43", v3(MiddleGrounds)), "// - CPEDHEE nOJlE2 (?)");
    PB10("GeometryDash.exe+26CF16", fmt("184 {} {} {} {}", v3(MiddleGrounds)), "// - CPEDHEE nOJlE3 (?)");
    PB10("GeometryDash.exe+495D22", fmt("184 {} {} {} {}", v3(MiddleGrounds)), "//  - CPEDHEE nOJlE4 (?)");
    PB10("GeometryDash.exe+26D136", fmt("65 184 {} {} {} {}", v3(MiddleGrounds)), "//   - CPEDHEE nOJlE5 (?)");


    //===========================uKOHKu==========================================
    //228 1
    //169
    //118
    //149
    //96
    //68
    //69
    //43
    //5

    PB10("GeometryDash.exe+3649B5", fmt("184 {} {} {} {}", v3(Cubes)), "// - BuguMocTb ky6a B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37BEA3", fmt("184 {} {} {} {}", v3(Ships)), "//  - BuguMocTb kopa6Jl9l B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37C0D3", fmt("184 {} {} {} {}", v3(Jetpacks)), "//  - BuguMocTb g)l(eTnak B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37C309", fmt("184 {} {} {} {}", v3(Ufos)), "//  - BuguMocTb l-ofo B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37C5A3", fmt("184 {} {} {} {}", v3(Balls)), "//   - BuguMocTb wap B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37C7D3", fmt("184 {} {} {} {}", v3(Swings)), "//   - BuguMocTb cBuHrkonTep B urpoBoM noJle (+ pegakTop)");
    PB10("GeometryDash.exe+37CA03", fmt("184 {} {} {} {}", v3(Waves)), "//    - BuguMocTb BoJlHbl B urpoBoM noJle (+ pegakTop)");

    PB10("GeometryDash.exe+2680C2", fmt("190 {} {} {} {}", v3(Cubes)), "//  - MaccuB ky6oB (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+267F98", fmt("190 {} {} {} {}", v3(Ships)), "// - MaccuB kopa6Jleu (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+267FD0", fmt("190 {} {} {} {}", v3(Balls)), "//  - MaccuB wapoB (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+267FEF", fmt("190 {} {} {} {}", v3(Ufos)), "//   - MaccuB l-ofowek (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+26800E", fmt("190 {} {} {} {}", v3(Waves)), "//    - MaccuB BoJlH (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+268038", fmt("190 {} {} {} {}", v3(Robots)), "//     - MaccuB po6oToB (B Bbl6ope ukoHok + Mara3uHbl) (?)");
    PB10("GeometryDash.exe+268052", fmt("190 {} {} {} {}", v3(Spiders)), "//     - MaccuB naykoB (B Bbl6ope ukoHok + Mara3uHbl) (?)");
    PB10("GeometryDash.exe+268079", fmt("190 {} {} {} {}", v3(Swings)), "//     - MaccuB cBuHrkonTepoB (B Bbl6ope ukoHok + Mara3uHbl)");
    PB10("GeometryDash.exe+2680AB", fmt("190 {} {} {} {}", v3(Jetpacks)), "//      - MaccuB g)l(eTnakoB (B Bbl6ope ukoHok + Mara3uHbl)");

    PB10("GeometryDash.exe+178D83", fmt("184 {} {} {} {}", v3(Cubes)), "// - KOJlu4ECTBO KY6OB (B rapa)l(e)");
    PB10("GeometryDash.exe+178D89", fmt("184 {} {} {} {}", v3(Ships)), "//  - KOJlu4ECTBO kopa6Jleu (B rapa)l(e)");
    PB10("GeometryDash.exe+178D8F", fmt("184 {} {} {} {}", v3(Balls)), "//   - KOJlu4ECTBO wapoB (B rapa)l(e)");
    PB10("GeometryDash.exe+178D95", fmt("184 {} {} {} {}", v3(Ufos)), "//    - KOJlu4ECTBO l-ofowek (B rapa)l(e)");
    PB10("GeometryDash.exe+178D9B", fmt("184 {} {} {} {}", v3(Waves)), "//     - KOJlu4ECTBO cTpeJlok (B rapa)l(e)");
    PB10("GeometryDash.exe+178DA1", fmt("184 {} {} {} {}", v3(Robots)), "//      - KOJlu4ECTBO po6oTon (B rapa)l(e) (?)");
    PB10("GeometryDash.exe+178DA7", fmt("184 {} {} {} {}", v3(Spiders)), "//       - KOJlu4ECTBO naykoB (B rapa)l(e) (?)");
    PB10("GeometryDash.exe+178DAD", fmt("184 {} {} {} {}", v3(Swings)), "//        - KOJlu4ECTBO cBuHrkonTepoB (B rapa)l(e) ");
    PB10("GeometryDash.exe+178DBF", fmt("184 {} {} {} {}", v3(Jetpacks)), "//         - KOJlu4ECTBO g)l(eTnakoB (B rapa)l(e) ");


    PB10("178DB3", fmt("184 {} {} {} {}", v3(Specials)), "//         - KOJlu4ECTBO TpeuJloB (B rapa)l(e) (?)");
    PB10("178DB9", fmt("184 {} {} {} {}", v3(DeathEffects)), "//         - KOJlu4ECTBO effekTbl cMepTu (B rapa)l(e)  (?)");
    PB10("178DC5", fmt("184 {} {} {} {}", v3(ShipFires)), "//          - KOJlu4ECTBO effekTbl kopa6Jl9l (ship fire) (B rapa)l(e)  (?)");

#undef v3
#undef fmt

};

void settingChanged(SettingValue* val, bool checkNewOnes = false, bool first = false) {
    ruinGame();
    //checks
    auto errors = std::string("");
    matjson::Value asd = Mod::get()->getMetadata().getRawJSON();
    matjson::Value settings = asd["settings"];

    int min = 0;
    int count = 0;

#define nails(key) \
    min = checkNewOnes ? settings[key]["default"].as_int() : 0;\
    count = (SETTING(int64_t, key)); \
    min = first ? 1 : min; \
    count = first ? 1 : count; \
    if (val->getKey() == key) for (int i = count; i != min; i--)

    nails("Fonts") {
        auto ifnt = CCString::createWithFormat("gjFont%02d.fnt", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ifnt)) errors.append(fmt::format(
            "- <cr>font</c> <co>{}</c> <cr>isnt exists</c>\n",
            ifnt
        ));
        auto ipng = CCString::createWithFormat("gjFont%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>font texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

    nails("Backgrounds") {
        auto ipng = CCString::createWithFormat("game_bg_%02d_001.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>bg texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

    nails("Grounds") {
        auto ipng = CCString::createWithFormat("groundSquare_%02d_001.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>ground texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

    nails("MiddleGrounds") {
        auto ipng = CCString::createWithFormat("fg_%02d_001.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>fg texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

    auto LoadingLayerBackground = (SETTING(int64_t, "LoadingLayerBackground"));
    auto LoadingLayerBackgroundPng = CCString::createWithFormat("game_bg_%02d_001.png", LoadingLayerBackground)->getCString();
    if (not cocos::fileExistsInSearchPaths(LoadingLayerBackgroundPng)) errors.append(fmt::format(
        "- <cr>bg texture</c> <co>{}</c> <cr>isnt exists</c>\n",
        LoadingLayerBackgroundPng
    ));

    nails("Cubes") {
        auto ipng = CCString::createWithFormat("icons/player_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>player plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/player_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>player plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Ships") {
        auto ipng = CCString::createWithFormat("icons/ship_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>ship plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/ship_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>ship plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Balls") {
        auto ipng = CCString::createWithFormat("icons/player_ball_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>player ball plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/player_ball_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>player ball plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Ufos") {
        auto ipng = CCString::createWithFormat("icons/bird_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>bird plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/bird_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>bird plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Waves") {
        auto ipng = CCString::createWithFormat("icons/dart_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>dart plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/dart_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>dart plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Robots") {
        auto ipng = CCString::createWithFormat("icons/robot_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>robot plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/robot_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>robot plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Spiders") {
        auto ipng = CCString::createWithFormat("icons/spider_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>spider plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/spider_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>spider plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Swings") {
        auto ipng = CCString::createWithFormat("icons/swing_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>swing plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/swing_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>swing plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("Jetpacks") {
        auto ipng = CCString::createWithFormat("icons/jetpack_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>jetpack plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("icons/jetpack_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>jetpack plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    nails("DeathEffects") {
        auto ipng = CCString::createWithFormat("PlayerExplosion_%02d.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>PlayerExplosion plist texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
        auto plistpng = CCString::createWithFormat("PlayerExplosion_%02d.plist", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(plistpng)) errors.append(fmt::format(
            "- <cr>PlayerExplosion plist</c> <co>{}</c> <cr>isnt exists</c>\n",
            plistpng
        ));
        CCSpriteFrameCache::get()->addSpriteFramesWithFile(plistpng);
    }

    auto Specials = (SETTING(int64_t, "Specials"));
    if (val->getKey() == "Specials") for (int i = Specials; i != 0; i--) {
        auto ipng = CCString::createWithFormat("streak_%02d_001.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>streak texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

    auto ShipFires = (SETTING(int64_t, "ShipFires"));
    if (val->getKey() == "ShipFires") for (int i = ShipFires; i != 1; i--) {
        auto ipng = CCString::createWithFormat("shipfire%02d_001.png", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ipng)) errors.append(fmt::format(
            "- <cr>shipfire texture</c> <co>{}</c> <cr>isnt exists</c>\n",
            ipng
        ));
    }

#undef nails

    if (errors.size() > 1) createWideMDPopup("Checks Warn", errors, "Oh Ok");
}

#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/LoadingLayer.hpp>
class $modify(LoadingLayer) {
    $override void loadAssets() {
        if (m_loadStep == 14) {
            //preload new
            settingChanged(Mod::get()->getSetting("Cubes"), true);
            settingChanged(Mod::get()->getSetting("Ships"), true);
            settingChanged(Mod::get()->getSetting("Balls"), true);
            settingChanged(Mod::get()->getSetting("Ufos"), true);
            settingChanged(Mod::get()->getSetting("Waves"), true);
            settingChanged(Mod::get()->getSetting("Robots"), true);
            settingChanged(Mod::get()->getSetting("Spiders"), true);
            settingChanged(Mod::get()->getSetting("Swings"), true);
            settingChanged(Mod::get()->getSetting("Jetpacks"), true);
            settingChanged(Mod::get()->getSetting("DeathEffects"), true);
            //preload first
            settingChanged(Mod::get()->getSetting("Cubes"), true, true);
            settingChanged(Mod::get()->getSetting("Ships"), true, true);
            settingChanged(Mod::get()->getSetting("Balls"), true, true);
            settingChanged(Mod::get()->getSetting("Ufos"), true, true);
            settingChanged(Mod::get()->getSetting("Waves"), true, true);
            settingChanged(Mod::get()->getSetting("Robots"), true, true);
            settingChanged(Mod::get()->getSetting("Spiders"), true, true);
            settingChanged(Mod::get()->getSetting("Swings"), true, true);
            settingChanged(Mod::get()->getSetting("Jetpacks"), true, true);
            settingChanged(Mod::get()->getSetting("DeathEffects"), true, true);
        };
        return LoadingLayer::loadAssets();
    };
    $override bool init(bool p0) {
        ruinGame();
        listenForAllSettingChanges([](SettingValue* val) { settingChanged(val); });
        return LoadingLayer::init(p0);
    };
};


#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
    $override bool isIconUnlocked(int p0, IconType p1) {
        auto rtn = GameManager::isIconUnlocked(p0, p1);
        if (SETTING(bool, "UnlockNewIcons")) {
            matjson::Value asd = Mod::get()->getMetadata().getRawJSON();
            if (p1 == IconType::Cube and p0 > asd["settings"]["Cubes"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Ship and p0 > asd["settings"]["Ships"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Ball and p0 > asd["settings"]["Balls"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Ufo and p0 > asd["settings"]["Ufos"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Wave and p0 > asd["settings"]["Waves"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Robot and p0 > asd["settings"]["Robots"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Spider and p0 > asd["settings"]["Spiders"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Swing and p0 > asd["settings"]["Swings"]["default"].as_int()) rtn = 1;
            if (p1 == IconType::Jetpack and p0 > asd["settings"]["Jetpacks"]["default"].as_int()) rtn = 1;
        };
        if (SETTING(bool, "UnlockAllIcons")) rtn = 1;
        return rtn;
    }
};

#include <Geode/modify/GJGarageLayer.hpp>
class $modify(GJGarageLayerExt, GJGarageLayer) {
    $override void setupPage(int p0, IconType p1) {
        if (GameManager::sharedState()->countForType(p1) <= 36) p0 = 0;
        GJGarageLayer::setupPage(p0, p1);
        m_playerObject->updatePlayerFrame(
            GameManager::get()->activeIconForType(
                GameManager::get()->m_playerIconType
            ),
            GameManager::get()->m_playerIconType
        );
    }
};
#include <Geode/modify/ItemInfoPopup.hpp>
class $modify(ItemInfoPopupExt, ItemInfoPopup) {
    $override static ItemInfoPopup* create(int p0, UnlockType p1) {
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