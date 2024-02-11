#include "ModUtils.hpp"
#include "HooksUtils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace ModUtils;

#include "SimpleIni.h"

//#define fucking37stuff toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37)
#define fucking37stuff if("asd")

const char* MainSection;
std::string IniPath;
void ConfigInit() {

    CSimpleIni Ini;

    MainSection = "InDeCreaseIcons";
    IniPath = (GetModPath().parent_path() / "IconsCount.ini").string();

    Ini.LoadFile(IniPath.c_str());
    if (!(Ini.KeyExists(MainSection, "Player")))
        Ini.SetLongValue(MainSection, "Player", 484,
            //"; WARN: u cant set less than 36 for cubes" "\n"
            "; - RUHAX TEAM, user666's original" "\n"
            "\n"
            "; org count of cubes 484"
        );
    if (!(Ini.KeyExists(MainSection, "Ship")))
        Ini.SetLongValue(MainSection, "Ship", 169, "; org count of ships 169");
    if (!(Ini.KeyExists(MainSection, "Player_ball")))
        Ini.SetLongValue(MainSection, "Player_ball", 118, "; org count of BALLS 118");
    if (!(Ini.KeyExists(MainSection, "Bird")))
        Ini.SetLongValue(MainSection, "Bird", 149, "; org count of ufos 149");
    if (!(Ini.KeyExists(MainSection, "Dart")))
        Ini.SetLongValue(MainSection, "Dart", 96, "; org count of waves 96");
    if (!(Ini.KeyExists(MainSection, "Swingcopter")))
        Ini.SetLongValue(MainSection, "Swingcopter", 43, "; org count of Swingcopters 43");
    if (!(Ini.KeyExists(MainSection, "JetPack")))
        Ini.SetLongValue(MainSection, "JetPack", 5, "; org count of JetPacks 5");
    if (!(Ini.KeyExists(MainSection, "AutoCalc")))
        Ini.SetBoolValue(MainSection, "AutoCalc", true, "; automatically change values by testing every frame for its existing");
    if (!(Ini.KeyExists(MainSection, "NewSearchPath")))
        Ini.SetBoolValue(MainSection, "NewSearchPath", false, "; u can store icon resources at \"GAME_DIR/MOD_NAME/icons\"");
    if (!(Ini.KeyExists(MainSection, "LoadCustomSpritesheet")))
        Ini.SetBoolValue(MainSection, "LoadCustomSpritesheet", true, "; load frames via \"icons/_IconsSheet.plist\" and \"_IconsSheet.plist\"");
    Ini.SaveFile(IniPath.c_str());
}

void CalcIconsCount() {
    return;//shit
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    if (!Ini.GetBoolValue(MainSection, "AutoCalc", true)) return;
    std::stringstream num;

    int Player = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("player_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Player;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Player", Player);

    int Ship = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("ship_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Ship;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Ship", Ship);

    int Player_ball = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("player_ball_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Player_ball;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Player_ball", Player_ball);

    int Bird = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("bird_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Bird;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Bird", Bird);

    int Dart = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("dart_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Dart;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Dart", Dart);

    int Swingcopter = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("swing_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++Swingcopter;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Swingcopter", Swingcopter);

    int JetPack = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto FrameToTest = ("jetpack_" + num.str() + "_001.png");
        if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) 
            ++JetPack;
        num.str("");
    }
    Ini.SetLongValue(MainSection, "JetPack", JetPack);

    Ini.SaveFile(IniPath.c_str());
}

#if 1
//thats sucks

uintptr_t PlayerPattern1;
uintptr_t PlayerPattern2;
uintptr_t PlayerPattern3;
uintptr_t PlayerPattern4;
uintptr_t PlayerPattern5;
uintptr_t PlayerPattern6;
uintptr_t PlayerPattern7;

uintptr_t ShipPattern1;
uintptr_t ShipPattern2;
uintptr_t ShipPattern3;
uintptr_t ShipPattern4;
uintptr_t ShipPattern5;
uintptr_t ShipPattern6;
uintptr_t ShipPattern7;

uintptr_t Player_ballPattern1;
uintptr_t Player_ballPattern2;
uintptr_t Player_ballPattern3;
uintptr_t Player_ballPattern4;
uintptr_t Player_ballPattern5;
uintptr_t Player_ballPattern6;
uintptr_t Player_ballPattern7;

uintptr_t BirdPattern1;
uintptr_t BirdPattern2;
uintptr_t BirdPattern3;
uintptr_t BirdPattern4;
uintptr_t BirdPattern5;
uintptr_t BirdPattern6;
uintptr_t BirdPattern7;

uintptr_t DartPattern1;
uintptr_t DartPattern2;
uintptr_t DartPattern3;
uintptr_t DartPattern4;
uintptr_t DartPattern5;
uintptr_t DartPattern6;
uintptr_t DartPattern7;

uintptr_t SwingcopterPattern1;
uintptr_t SwingcopterPattern2;
uintptr_t SwingcopterPattern3;
uintptr_t SwingcopterPattern4;
uintptr_t SwingcopterPattern5;
uintptr_t SwingcopterPattern6;
uintptr_t SwingcopterPattern7;

uintptr_t JetPackPattern1;
uintptr_t JetPackPattern2;
uintptr_t JetPackPattern3;
uintptr_t JetPackPattern4;
uintptr_t JetPackPattern5;
uintptr_t JetPackPattern6;
uintptr_t JetPackPattern7;

#endif

void UpdateIconsCount() {
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    int Player = Ini.GetLongValue(MainSection, "Player", 484);
    int Ship = Ini.GetLongValue(MainSection, "Ship", 169);
    int Player_ball = Ini.GetLongValue(MainSection, "Player_ball", 118);
    int Bird = Ini.GetLongValue(MainSection, "Bird", 149);
    int Dart = Ini.GetLongValue(MainSection, "Dart", 96);
    int Swingcopter = Ini.GetLongValue(MainSection, "Swingcopter", 43);
    int JetPack = Ini.GetLongValue(MainSection, "JetPack", 5);
    {
        /*
        * Player:
        * 484(10)=1E4(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Player);
        fucking37stuff;
        log(std::format("toRewrite:Player:{}", Player));
        if (PlayerPattern1 == 0) PlayerPattern1 = patterns::find_pattern("BB E4 01 00 00 8B 8F 10 02 00 00 85 C9 74 12");
        if (PlayerPattern2 == 0) PlayerPattern2 = patterns::find_pattern("81 C6 E4 01 00 00 EB 2C 81 C6 A9 00 00 00 EB 24");
        if (PlayerPattern3 == 0) PlayerPattern3 = patterns::find_pattern("B9 E4 01 00 00 39 4D 08 89 97 20 02 00 00 0F 4C");
        if (PlayerPattern4 == 0) PlayerPattern4 = patterns::find_pattern("BA E4 01 00 00 8B 75 0C 3B C2 B9 01 00 00 00 0F");
        if (PlayerPattern5 == 0) PlayerPattern5 = patterns::find_pattern("B9 E4 01 00 00 FF B3 20 02 00 00 0F 4C 4C 24 1C");
        if (PlayerPattern6 == 0) PlayerPattern6 = patterns::find_pattern("BB E4 01 00 00 89 4D F8 39 5D 08 56 0F 4C 5D 08");
        if (PlayerPattern7 == 0) PlayerPattern7 = patterns::find_pattern("B8 E4 01 00 00 C3 B8 A9 00 00 00 C3 B8 76 00 00");
        WriteProcMem(PlayerPattern1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern1");
        WriteProcMem(PlayerPattern2, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern2");
        WriteProcMem(PlayerPattern3, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern3");
        WriteProcMem(PlayerPattern4, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern4");
        WriteProcMem(PlayerPattern5, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern5");
        WriteProcMem(PlayerPattern6, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern6");
        WriteProcMem(PlayerPattern7, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "PlayerPattern7");
    };
    {
        /*
        * Ship:
        * A9(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Ship);
        fucking37stuff;
        log(std::format("toRewrite:Ship:{}", Ship));
        if (ShipPattern1 == 0) ShipPattern1 = patterns::find_pattern("B8 A9 00 00 00 C3 B8 76 00 00 00 C3 B8 95 00 00");
        if (ShipPattern2 == 0) ShipPattern2 = patterns::find_pattern("81 C6 A9 00 00 00 EB 24 83 C6 76 EB 1F 81 C6 95");
        if (ShipPattern3 == 0) ShipPattern3 = patterns::find_pattern("BB A9 00 00 00");//garage showup 
        if (ShipPattern4 == 0) ShipPattern4 = patterns::find_patterns("BA A9 00 00 00 89 4D F8 39 55 08 BB 01 00 00 00")[0];
        WriteProcMem(ShipPattern1, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "ShipPattern1");
        WriteProcMem(ShipPattern2, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "ShipPattern2");
        WriteProcMem(ShipPattern3, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "ShipPattern3");
        WriteProcMem(ShipPattern4, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "ShipPattern4");
    };
    {
        /*
        * Player_ball:
        * 76(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Player_ball);
        fucking37stuff;
        log(std::format("toRewrite:Player_ball:{}", Player_ball));
        if (Player_ballPattern1 == 0) Player_ballPattern1 = patterns::find_pattern("B8 76 00 00 00 C3");
        if (Player_ballPattern3 == 0) Player_ballPattern3 = patterns::find_pattern("B8 76 00 00 00 C7 45");//
        if (Player_ballPattern4 == 0) Player_ballPattern4 = patterns::find_pattern("BB 76 00 00 00 E9");
        if (Player_ballPattern5 == 0) Player_ballPattern5 = patterns::find_pattern("BA 76 00 00 00 89");
        WriteProcMem(Player_ballPattern1, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "Player_ballPattern1");
        WriteProcMem(Player_ballPattern3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "Player_ballPattern3");
        WriteProcMem(Player_ballPattern4, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "Player_ballPattern4");
        WriteProcMem(Player_ballPattern5, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "Player_ballPattern5");
    };
    {
        /*
        * Bird:
        * 95(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Bird);
        fucking37stuff;
        log(std::format("toRewrite:Bird:{}", Bird));
        /*patterns log
        
        */
        if (BirdPattern1 == 0) BirdPattern1 = patterns::find_pattern("b8 95 0 0 0 c3 b8");
        if (BirdPattern2 == 0) BirdPattern2 = patterns::find_pattern("81 c6 95 0 0 0 eb 17");//
        if (BirdPattern3 == 0) BirdPattern3 = patterns::find_pattern("b8 95 0 0 0 c7 45");//
        //if (BirdPattern4 == 0) BirdPattern4 = patterns::find_pattern("68 95 0 0 0 e8 82");
        if (BirdPattern5 == 0) BirdPattern5 = patterns::find_pattern("bb 95 0 0 0 eb 7e");
        if (BirdPattern6 == 0) BirdPattern6 = patterns::find_pattern("ba 95 0 0 0 89 4d");
        //2.200
        /*//addreses
        14:00:48 CE [InDeCreaseIcons]: toRewrite:Bird:150
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 345480 (base rva: 125480) with "b8 96 0 0 0", org was "b8 95 0 0 0 c3 b8 60 0 0 0 c3 b8 44 0 0"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 345b0a (base rva: 125b0a) with "81 c6 96 0 0 0", org was "81 c6 95 0 0 0 eb 17 83 c6 60 eb 12 83 c6 44"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 3861b7 (base rva: 1661b7) with "b8 96 0 0 0", org was "b8 95 0 0 0 c7 45 a4 6 0 0 0 89 45 a0 e9"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 2e4d34 (base rva: c4d34) with "68 96 0 0 0", org was "68 95 0 0 0 e8 82 1f 0 0 8b 8d 68 fe ff ff"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 4101f1 (base rva: 1f01f1) with "bb 96 0 0 0", org was "bb 95 0 0 0 eb 7e 68 54 87 61 0 8d 4c 24 2c"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 4f1777 (base rva: 2d1777) with "ba 96 0 0 0", org was "ba 95 0 0 0 89 4d f8 39 55 8 bb 1 0 0 0"
        BirdPattern1 = base + 0x125480;
        BirdPattern2 = base + 0x125B0A;
        BirdPattern3 = base + 0x1661B7;
        BirdPattern4 = base + 0xC4D34;//whotf is this
        BirdPattern5 = base + 0x1F01F1;
        BirdPattern6 = base + 0x2D1777;
        */
        WriteProcMem(BirdPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern1");
        WriteProcMem(BirdPattern2, { 0x81, 0xc6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern2");
        WriteProcMem(BirdPattern3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern3");
        //WriteProcMem(BirdPattern4, { 0x68, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern4");
        WriteProcMem(BirdPattern5, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern5");
        WriteProcMem(BirdPattern6, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BirdPattern6");
    };
    {
        /*
        * Dart:
        * 29(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Dart);
        fucking37stuff;
        log(std::format("toRewrite:Dart:{}", Dart));
        if (DartPattern1 == 0) DartPattern1 = patterns::find_patterns("b8 60 0 0 0 c3 b8 44 0 0 0")[0];//0=5ff18
        if (DartPattern2 == 0) DartPattern2 = patterns::find_pattern("b8 60 0 0 0 c7");//
        if (DartPattern3 == 0) DartPattern3 = patterns::find_pattern("ba 60 0 0 0 89");//
        if (DartPattern5 == 0) DartPattern5 = patterns::find_pattern("bb 60 0 0 0 eb");
        WriteProcMem(DartPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3 }, "DartPattern1");
        WriteProcMem(DartPattern2, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7 }, "DartPattern2");
        WriteProcMem(DartPattern3, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89 }, "DartPattern3");
        WriteProcMem(DartPattern5, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb }, "DartPattern5");
    };
    {//
        /*
        * Swingcopter:
        * 29(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Swingcopter);
        fucking37stuff;
        log(std::format("toRewrite:Swingcopter:{}", Swingcopter));
        if (SwingcopterPattern1 == 0) SwingcopterPattern1 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 7");//base + 0x125498;
        if (SwingcopterPattern2 == 0) SwingcopterPattern2 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 63");//base + 0x5FF54;
        if (SwingcopterPattern3 == 0) SwingcopterPattern3 = patterns::find_pattern("b8 2b 0 0 0 c7 45 a4");//base + 0x16625C;
        if (SwingcopterPattern4 == 0) SwingcopterPattern4 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 1b");//base + 0x1812B6;
        if (SwingcopterPattern5 == 0) SwingcopterPattern5 = patterns::find_pattern("bb 2b 0 0 0 eb 2a 68");//base + 0x1F0245;
        if (SwingcopterPattern6 == 0) SwingcopterPattern6 = patterns::find_pattern("ba 2b 0 0 0 89 4d f8");//base + 0x2D1B57;
        WriteProcMem(SwingcopterPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x07 }, "SwingcopterPattern1");
        WriteProcMem(SwingcopterPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x63 }, "SwingcopterPattern2");
        WriteProcMem(SwingcopterPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7, 0x45, 0xa4 }, "SwingcopterPattern3");
        WriteProcMem(SwingcopterPattern4, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x1b }, "SwingcopterPattern4");
        WriteProcMem(SwingcopterPattern5, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb, 0x2a, 0x68 }, "SwingcopterPattern5");
        WriteProcMem(SwingcopterPattern6, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89, 0x4d, 0xf8 }, "SwingcopterPattern6");
    };
    {//
        /*
        * JetPack:
        * 29(16)
        * //JetPacks
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1254AA), "\xB8\x06\x00\x00\x00", 5, NULL);
         //  GeometryDash.exe+1254AA - B8 06000000    
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x16626D), "\xB8\x06\x00\x00\x00", 5, NULL);
         //  GeometryDash.exe+16626D - B8 06000000          
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EB72E), "\xB8\x06\x00\x00\x00", 5, NULL);
         //  GeometryDash.exe+1EB72E - B8 06000000          
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1F025A), "\xBb\x06\x00\x00\x00", 5, NULL);
         //  GeometryDash.exe+1F025A - BB 06000000    
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2D15B7), "\xBa\x06\x00\x00\x00", 5, NULL);
         //  GeometryDash.exe+2D15B7 - BA 06000000          
         WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x125B26), "\x83\xc6\x06", 3, NULL);
         //  GeometryDash.exe+125B26 - 83 C6 06  

        */
        std::vector<unsigned char> toRewrite = intToBytes(JetPack);
        fucking37stuff;
        log(std::format("toRewrite:JetPack:{}", JetPack));
        if (JetPackPattern1 == 0) JetPackPattern1 = patterns::find_pattern("b8 5 0 0 0 c3 b8 6 0 0 0 c3 33 c0 c3 8d");//base + 0x1254AA;fucku >:T
        if (JetPackPattern2 == 0) JetPackPattern2 = patterns::find_pattern("b8 5 0 0 0 c7 45 a4");//base + 0x16626D;
        if (JetPackPattern3 == 0) JetPackPattern3 = patterns::find_pattern("b8 5 0 0 0 39 44 24");//base + 0x1EB72E;
        if (JetPackPattern4 == 0) JetPackPattern4 = patterns::find_pattern("bb 5 0 0 0 eb 15");//base + 0x1F025A;
        if (JetPackPattern5 == 0) JetPackPattern5 = patterns::find_pattern("ba 5 0 0 0 89 4d f8");//base + 0x2D15B7;
        WriteProcMem(JetPackPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x06 }, "JetPackPattern1");
        WriteProcMem(JetPackPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7, 0x45, 0xa4 }, "JetPackPattern2");
        WriteProcMem(JetPackPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x39, 0x44, 0x24 }, "JetPackPattern3");
        WriteProcMem(JetPackPattern4, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb, 0x15, 0x6a }, "JetPackPattern4");
        WriteProcMem(JetPackPattern5, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89, 0x4d, 0xf8 }, "JetPackPattern5");
    };
}

void __fastcall loadingFinished(CCLayer* self) {
    MappedHooks::getOriginal(loadingFinished)(self);
    twoTimesVoidCallEscapeByParrentNode(self);
    ConfigInit();
    UpdateIconsCount();
    //load new stuff also asd
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    if (Ini.GetBoolValue(MainSection, "NewSearchPath", false)) {
        //"NewSearchPath", false, "; u can store icon resources at \"GAME_DIR/MOD_NAME/icons\""
        std::filesystem::create_directories(GetModName() + "/icons");
        CCFileUtils::sharedFileUtils()->addSearchPath(GetModName().c_str());
    };
    if (Ini.GetBoolValue(MainSection, "LoadCustomSpritesheet", true)) {
        //"LoadCustomSpritesheet", true, "; load frames via \"icons/_IconsSheet.plist\""
        {
            auto TarFile = "icons/_IconsSheet.plist";
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile);
        };
        {
            auto TarFile = "_IconsSheet.plist";
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile);
        };
    };
    int Player = Ini.GetLongValue(MainSection, "Player", 484);
    int Ship = Ini.GetLongValue(MainSection, "Ship", 169);
    int Player_ball = Ini.GetLongValue(MainSection, "Player_ball", 118);
    int Bird = Ini.GetLongValue(MainSection, "Bird", 149);
    int Dart = Ini.GetLongValue(MainSection, "Dart", 96);
    int Swingcopter = Ini.GetLongValue(MainSection, "Swingcopter", 43);
    int JetPack = Ini.GetLongValue(MainSection, "JetPack", 5);
    {
        std::stringstream num;
        for (int io = 1; io <= Player; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/player_" + num.str() + ".plist");
            auto FrameToTest = ("player_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= Ship; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/ship_" + num.str() + ".plist");
            auto FrameToTest = ("ship_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= Player_ball; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/player_ball_" + num.str() + ".plist");
            auto FrameToTest = ("player_ball_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= Bird; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/bird_" + num.str() + ".plist");
            auto FrameToTest = ("bird_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= Dart; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/dart_" + num.str() + ".plist");
            auto FrameToTest = ("dart_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= Swingcopter; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/swing_" + num.str() + ".plist");
            auto FrameToTest = ("swing_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        for (int io = 1; io <= JetPack; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/jetpack_" + num.str() + ".plist");
            auto FrameToTest = ("jetpack_" + num.str() + "_001.png");
            if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
            log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    CalcIconsCount();
}

DWORD WINAPI ModThread(void* hModule) {
    MH_Initialize();
    MappedHooks::registerHook(patterns::find_pattern("C2 04 00 CC CC CC ^ ?????? 00 75 3D 56 FF 15 "), loadingFinished);
    Sleep(1000); 
    OpenConsole();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) return TRUE;
    //OpenConsole();
    DisableThreadLibraryCalls(hModule);
    CreateThread(0, 0, ModThread, hModule, 0, 0);
    return TRUE;
}
