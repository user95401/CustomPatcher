#include "ModUtils.hpp"
#include "HooksUtils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

#include "SimpleIni.h"

const char* MainSection;
std::string IniPath;
void ConfigInit() {

    CSimpleIni Ini;

    MainSection = "InDeCreaseIcons";
    IniPath = (ModUtils::GetModPath().parent_path() / "IconsCount.ini").string();

    Ini.LoadFile(IniPath.c_str());
    if (!(Ini.KeyExists(MainSection, "Player")))
        Ini.SetLongValue(MainSection, "Player", 484,
            "; WARN: u cant set less than 36" "\n"
            "; - RUHAX TEAM" "\n"
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
        Ini.SetLongValue(MainSection, "Dart", 41, "; org count of waves 41");
    if (!(Ini.KeyExists(MainSection, "Swingcopter")))
        Ini.SetLongValue(MainSection, "Swingcopter", 43, "; org count of Swingcopters 43");
    if (!(Ini.KeyExists(MainSection, "JetPack")))
        Ini.SetLongValue(MainSection, "JetPack", 5, "; org count of JetPacks 5");
    if (!(Ini.KeyExists(MainSection, "Auto calculation")))
        Ini.SetBoolValue(MainSection, "Auto calculation", true, "; Auto calculation icons count by loaded textures");
    Ini.SaveFile(IniPath.c_str());
}

void CalcIconsCount() {
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    if (!Ini.GetBoolValue(MainSection, "Auto calculation", true)) return;
    std::stringstream num;

    int Player = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto TarFile = ("Resources/icons/player_" + num.str() + ".plist");
        if (std::filesystem::exists(TarFile)) {
            ++Player;
        }
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Player", Player);

    int Ship = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto TarFile = ("Resources/icons/ship_" + num.str() + ".plist");
        if (std::filesystem::exists(TarFile)) {
            ++Ship;
        }
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Ship", Ship);

    int Player_ball = 0;
    for (int i = 1; i < 1200; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        auto TarFile = ("Resources/icons/player_ball_" + num.str() + ".plist");
        if (std::filesystem::exists(TarFile)) {
            ++Player_ball;
        }
        num.str("");
    }
    Ini.SetLongValue(MainSection, "Player_ball", Player_ball);

    Ini.SaveFile(IniPath.c_str());
}

std::vector<unsigned char> intToBytes(int value) {
    std::vector<unsigned char> result;
    result.push_back(value & 0x000000ff);
    result.push_back((value & 0x0000ff00) >> 8);
    result.push_back((value & 0x00ff0000) >> 16);
    result.push_back((value & 0xff000000) >> 24);
    return result;
}

typedef size_t Type;
std::string toHex(const Type& number) {
    std::stringstream stream;
    stream << std::hex << number;
    return stream.str();
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

uintptr_t Player_ballPattern1;
uintptr_t Player_ballPattern2;
uintptr_t Player_ballPattern3;
uintptr_t Player_ballPattern4;
uintptr_t Player_ballPattern5;

#endif

void UpdateIconsCount() {
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    int Player = Ini.GetLongValue(MainSection, "Player", 484);
    int Ship = Ini.GetLongValue(MainSection, "Ship", 169);
    int Player_ball = Ini.GetLongValue(MainSection, "Player_ball", 118);
    int Bird = Ini.GetLongValue(MainSection, "Bird", 149);
    int Dart = Ini.GetLongValue(MainSection, "Dart", 69);
    int Swingcopter = Ini.GetLongValue(MainSection, "Swingcopter", 43);
    int JetPack = Ini.GetLongValue(MainSection, "JetPack", 5);
    {
        /*
        * Player:
        * 484(10)=1E4(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Player);
        toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
        if (PlayerPattern1 == 0) PlayerPattern1 = patterns::find_pattern("BB E4 01 00 00 8B 8F 10 02 00 00 85 C9 74 12");
        if (PlayerPattern2 == 0) PlayerPattern2 = patterns::find_pattern("81 C6 E4 01 00 00 EB 2C 81 C6 A9 00 00 00 EB 24");
        if (PlayerPattern3 == 0) PlayerPattern3 = patterns::find_pattern("B9 E4 01 00 00 39 4D 08 89 97 20 02 00 00 0F 4C");
        if (PlayerPattern4 == 0) PlayerPattern4 = patterns::find_patterns("BA E4 01 00 00 8B 75 0C 3B C2 B9 01 00 00 00 0F")[0];
        if (PlayerPattern5 == 0) PlayerPattern5 = patterns::find_pattern("B9 E4 01 00 00 FF B3 20 02 00 00 0F 4C 4C 24 1C");
        if (PlayerPattern6 == 0) PlayerPattern6 = patterns::find_pattern("BB E4 01 00 00 89 4D F8 39 5D 08 56 0F 4C 5D 08");
        if (PlayerPattern7 == 0) PlayerPattern7 = patterns::find_pattern("B8 E4 01 00 00 C3 B8 A9 00 00 00 C3 B8 76 00 00");
        ModUtils::WriteProcMem(PlayerPattern1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern2, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern3, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern4, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern5, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern6, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(PlayerPattern7, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
    };
    {
        /*
        * Ship:
        * A9(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Ship);
        toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
        if (ShipPattern1 == 0) ShipPattern1 = patterns::find_pattern("B8 A9 00 00 00 C3 B8 76 00 00 00 C3 B8 95 00 00");
        if (ShipPattern2 == 0) ShipPattern2 = patterns::find_pattern("81 C6 A9 00 00 00 EB 24 83 C6 76 EB 1F 81 C6 95");
        if (ShipPattern3 == 0) ShipPattern3 = patterns::find_pattern("BB A9 00 00 00");//garage showup 
        if (ShipPattern4 == 0) ShipPattern4 = patterns::find_patterns("BA A9 00 00 00 89 4D F8 39 55 08 BB 01 00 00 00")[0];
        ModUtils::WriteProcMem(ShipPattern1, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(ShipPattern2, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(ShipPattern3, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(ShipPattern4, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
    };
    {
        /*
        * Player_ball:
        * 76(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Player_ball);
        toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
        if (Player_ballPattern1 == 0) Player_ballPattern1 = patterns::find_pattern("B8 76 00 00 00 C3");
        if (Player_ballPattern2 == 0) Player_ballPattern2 = patterns::find_pattern("EB 24 ^ 83 C6 76");//wtf
        if (Player_ballPattern3 == 0) Player_ballPattern3 = patterns::find_pattern("B8 76 00 00 00 C7 45");//
        if (Player_ballPattern4 == 0) Player_ballPattern4 = patterns::find_pattern("BB 76 00 00 00 E9");
        if (Player_ballPattern5 == 0) Player_ballPattern5 = patterns::find_pattern("BA 76 00 00 00 89");
        /* для сравнения с 2.200 https://github.com/zGuschin/IconPatch-2.1---2.2/blob/master/2.2/AddIconsHexCode.md 
        ModUtils::log(std::format("Player_ballPattern1: {}", toHex(Player_ballPattern1 - base)));
        ModUtils::log(std::format("Player_ballPattern2: {}", toHex(Player_ballPattern2 - base)));
        ModUtils::log(std::format("Player_ballPattern3: {}", toHex(Player_ballPattern3 - base)));
        ModUtils::log(std::format("Player_ballPattern4: {}", toHex(Player_ballPattern4 - base)));
        ModUtils::log(std::format("Player_ballPattern5: {}", toHex(Player_ballPattern5 - base)));
        */
        ModUtils::WriteProcMem(Player_ballPattern1, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });//
        ModUtils::WriteProcMem(Player_ballPattern2, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });//fuck
        ModUtils::WriteProcMem(Player_ballPattern3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(Player_ballPattern4, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        ModUtils::WriteProcMem(Player_ballPattern5, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
    };
}

void __fastcall loadingFinished(CCLayer* self) {
    MappedHooks::getOriginal(loadingFinished)(self);
    twoTimesVoidCallEscapeByParrentNode(self);
    //load new stuff also asd
    CSimpleIni Ini;
    Ini.LoadFile(IniPath.c_str());
    int Player = Ini.GetLongValue(MainSection, "Player", 484);
    int Ship = Ini.GetLongValue(MainSection, "Ship", 169);
    int Player_ball = Ini.GetLongValue(MainSection, "Player_ball", 118);
    int Bird = Ini.GetLongValue(MainSection, "Bird", 149);
    int Dart = Ini.GetLongValue(MainSection, "Dart", 69);
    int Swingcopter = Ini.GetLongValue(MainSection, "Swingcopter", 43);
    int JetPack = Ini.GetLongValue(MainSection, "JetPack", 5);
    {
        std::stringstream num;
        auto LastOfficial = 484;
        for (int io = ++LastOfficial; io <= Player; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/player_" + num.str() + ".plist");
            ModUtils::log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        auto LastOfficial = 169;
        for (int io = ++LastOfficial; io <= Ship; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/ship_" + num.str() + ".plist");
            ModUtils::log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
    {
        std::stringstream num;
        auto LastOfficial = 118;
        for (int io = ++LastOfficial; io <= Player_ball; io++) {
            num << std::setw(2) << std::setfill('0') << io;
            auto TarFile = ("icons/player_ball_" + num.str() + ".plist");
            ModUtils::log(std::format("Adding frames with file \"{}\"", TarFile));
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
            num.str("");
        }
    }
}

DWORD WINAPI ModThread(void* hModule) {
    ConfigInit();
    MH_Initialize();
    MappedHooks::registerHook(patterns::find_pattern("C2 04 00 CC CC CC ^ ?????? 00 75 3D 56 FF 15 "), loadingFinished);
    Sleep(1000); ModUtils::OpenConsole();
    while (true) {
        CalcIconsCount();
        UpdateIconsCount();
        Sleep(1000);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) return TRUE;
    //ModUtils::OpenConsole();
    DisableThreadLibraryCalls(hModule);
    CreateThread(0, 0, ModThread, hModule, 0, 0);
    return TRUE;
}
