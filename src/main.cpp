#include "_main.hpp"

void ruinGame() {
    "FONTS"; {
        int FONT = Mod::get()->getSettingValue<int64_t>("FONT");
        auto toRewrite = intToBytes(FONT);
        "GeometryDash.exe+1797CA - (?)"; if (true) {
            patch(
                geode::base::get() + 0x1797CA,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3]}
            );
        };
        "GeometryDash.exe+27C8BC - FONT ARRAY"; if (true) {
            patch(
                geode::base::get() + 0x27C8BC,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3]}
            );
        };
        "GeometryDash.exe+27C7B2 - FONT VISIBILITY"; if (true) {
            patch(
                geode::base::get() + 0x27C7B2,
                { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+17987A - (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x17987A,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+181A22 - FONT2. (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x181A22,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+1FFAE7 - FONT3. (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x1FFAE7,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+2CB650 - FONT4. (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x2CB650,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+A4E78 - FONT5. (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0xA4E78,
                { 0xbf, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+A51CF - FONT6 -TEXT?. (?)"; if (true) {
            //fuckin cmp so idk
            patch(
                geode::base::get() + 0xA51CF,
                { 0x83, 0xF8, toRewrite[0]/*59*/}
            );
        };
        "GeometryDash.exe+19D82C - FONT7 - . (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x19D82C,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+383E3A - FONT9 - . (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x383E3A,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+487140 - FONT10 - . (?)"; if (true) {
            //maybe loading
            patch(
                geode::base::get() + 0x487140,
                { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
    };
    "Trail"; {
        int Trails = Mod::get()->getSettingValue<int64_t>("Trails");
        auto toRewrite = intToBytes(Trails);
        "GeometryDash.exe+3669A4 - Trail visibility in the playing field (+ editor)"; {
            patch(
                geode::base::get() + 0x3669A4,
                { 186, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
    };
    "BGs"; {
        int BGs = Mod::get()->getSettingValue<int64_t>("BGs");
        int BGInthebootscene = Mod::get()->getSettingValue<int64_t>("BGInthebootscene");
        auto toRewrite = intToBytes(BGs);
        auto toRewrite2 = intToBytes(BGInthebootscene);
        "GeometryDash.exe+49D190 - BG (?)"; {
            patch(
                geode::base::get() + 0x49D190,
                { 0x83, 0xFF, toRewrite[0] }
            );
        };
        "GeometryDash.exe+495F70 - BG2 (?)"; {
            patch(
                geode::base::get() + 0x495F70,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+1E949F - BG4"; {
            patch(
                geode::base::get() + 0x1E949F,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+1FC630 - BG BACKGROUND IN THE GAME"; {
            patch(
                geode::base::get() + 0x1FC630,
                { 0xbd, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+310B99 - BG in the main menu"; {
            patch(
                geode::base::get() + 0x310B99,
                { 0xb9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+30DD22 - BG In the boot scene.."; {
            patch(
                geode::base::get() + 0x30DD22,
                { 0xba, toRewrite2[0], toRewrite2[1], toRewrite2[2], toRewrite2[3] }
            );
        };
        "GeometryDash.exe+301D54 - bg button array"; {
            patch(
                geode::base::get() + 0x301D54,
                { 0x41, 0xbd, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+44644F - bgknop (?)"; {
            patch(
                geode::base::get() + 0x44644F,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+445BCD - bgknop2 (?)"; {
            patch(
                geode::base::get() + 0x445BCD,
                { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+2FF5CA - BGKNOP3 (?)"; {
            patch(
                geode::base::get() + 0x2FF5CA,
                { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }
            );
        };
        "GeometryDash.exe+2FF5C5 - BGKNOP4 (?)"; {
            patch(
                geode::base::get() + 0x2FF5C5,
                { 0x83, 0xFA, toRewrite[0] }
            );
        };
    };
};
void settingChanged() {
    ruinGame();
    //checks
    auto errors = std::string("");
    int FONT = Mod::get()->getSettingValue<int64_t>("FONT");
    for (int i = FONT; i != 0; i--) {
        auto ifnt = CCString::createWithFormat("gjFont%02d.fnt", i)->getCString();
        if (not cocos::fileExistsInSearchPaths(ifnt)) {
            errors.append(fmt::format("- <cr>font</c> <co>{}</c> <cr>isnt exists</c>\n", ifnt));
        }
    }
    if (errors.size() > 1) createWideMDPopup("Checks Warn", errors, "Oh Ok");
}

#include <Geode/loader/SettingEvent.hpp>
$on_mod(DataLoaded) { 
    ruinGame();
    listenForAllSettingChanges([](auto) { settingChanged(); });
}