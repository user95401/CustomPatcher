#include <Geode/Geode.hpp>
using namespace geode::prelude;

//i know all like use geode solutions blah blah blah but i dont like them
//here collected all helpers that i selected
#ifdef GEODE_IS_WINDOWS
#include "patterns.hpp"
#include "ModUtils.hpp"
#endif

//#define fucking37stuff toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37)
#define fucking37stuff if("asd")
#if 1
//thats sucks

uintptr_t CubePattern1;
uintptr_t CubePattern2;
uintptr_t CubePattern3;
uintptr_t CubePattern4;
uintptr_t CubePattern5;
uintptr_t CubePattern6;
uintptr_t CubePattern7;

uintptr_t ShipPattern1;
uintptr_t ShipPattern2;
uintptr_t ShipPattern3;
uintptr_t ShipPattern4;
uintptr_t ShipPattern5;
uintptr_t ShipPattern6;
uintptr_t ShipPattern7;

uintptr_t BallPattern1;
uintptr_t BallPattern2;
uintptr_t BallPattern3;
uintptr_t BallPattern4;
uintptr_t BallPattern5;
uintptr_t BallPattern6;
uintptr_t BallPattern7;

uintptr_t UfoPattern1;
uintptr_t UfoPattern2;
uintptr_t UfoPattern3;
uintptr_t UfoPattern4;
uintptr_t UfoPattern5;
uintptr_t UfoPattern6;
uintptr_t UfoPattern7;

uintptr_t WavePattern1;
uintptr_t WavePattern2;
uintptr_t WavePattern3;
uintptr_t WavePattern4;
uintptr_t WavePattern5;
uintptr_t WavePattern6;
uintptr_t WavePattern7;

uintptr_t RobotPattern1;
uintptr_t RobotPattern2;
uintptr_t RobotPattern3;
uintptr_t RobotPattern4;
uintptr_t RobotPattern5;
uintptr_t RobotPattern6;
uintptr_t RobotPattern7;

uintptr_t SpiderPattern1;
uintptr_t SpiderPattern2;
uintptr_t SpiderPattern3;
uintptr_t SpiderPattern4;
uintptr_t SpiderPattern5;
uintptr_t SpiderPattern6;
uintptr_t SpiderPattern7;

uintptr_t SwingPattern1;
uintptr_t SwingPattern2;
uintptr_t SwingPattern3;
uintptr_t SwingPattern4;
uintptr_t SwingPattern5;
uintptr_t SwingPattern6;
uintptr_t SwingPattern7;

uintptr_t JetpackPattern1;
uintptr_t JetpackPattern2;
uintptr_t JetpackPattern3;
uintptr_t JetpackPattern4;
uintptr_t JetpackPattern5;
uintptr_t JetpackPattern6;
uintptr_t JetpackPattern7;

#endif
void UpdateIconsCount() {
#ifdef GEODE_IS_WINDOWS
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
    {
        /*
        * Cube:
        * 484(10)=1E4(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Cube);
        fucking37stuff;
        log::info("toRewrite:Cube:{}", Cube);
        if (CubePattern1 == 0) CubePattern1 = patterns::find_pattern("BB E4 01 00 00 8B 8F 10 02 00 00 85 C9 74 12");
        if (CubePattern2 == 0) CubePattern2 = patterns::find_pattern("81 C6 E4 01 00 00 EB 2C 81 C6 A9 00 00 00 EB 24");
        if (CubePattern3 == 0) CubePattern3 = patterns::find_pattern("B9 E4 01 00 00 39 4D 08 89 97 20 02 00 00 0F 4C");
        if (CubePattern4 == 0) CubePattern4 = patterns::find_pattern("BA E4 01 00 00 8B 75 0C 3B C2 B9 01 00 00 00 0F");
        if (CubePattern5 == 0) CubePattern5 = patterns::find_pattern("B9 E4 01 00 00 FF B3 20 02 00 00 0F 4C 4C 24 1C");
        if (CubePattern6 == 0) CubePattern6 = patterns::find_pattern("BB E4 01 00 00 89 4D F8 39 5D 08 56 0F 4C 5D 08");
        if (CubePattern7 == 0) CubePattern7 = patterns::find_pattern("B8 E4 01 00 00 C3 B8 A9 00 00 00 C3 B8 76 00 00");
        WriteProcMem(CubePattern1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern1");
        WriteProcMem(CubePattern2, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern2");
        WriteProcMem(CubePattern3, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern3");
        WriteProcMem(CubePattern4, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern4");
        WriteProcMem(CubePattern5, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern5");
        WriteProcMem(CubePattern6, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern6");
        WriteProcMem(CubePattern7, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "CubePattern7");
    };
    {
        /*
        * Ship:
        * A9(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Ship);
        fucking37stuff;
        log::info("toRewrite:Ship:{}", Ship);
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
        * Ball:
        * 76(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Ball);
        fucking37stuff;
        log::info("toRewrite:Ball:{}", Ball);
        if (BallPattern1 == 0) BallPattern1 = patterns::find_pattern("B8 76 00 00 00 C3");
        if (BallPattern3 == 0) BallPattern3 = patterns::find_pattern("B8 76 00 00 00 C7 45");//
        if (BallPattern4 == 0) BallPattern4 = patterns::find_pattern("BB 76 00 00 00 E9");
        if (BallPattern5 == 0) BallPattern5 = patterns::find_pattern("BA 76 00 00 00 89");
        WriteProcMem(BallPattern1, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BallPattern1");
        WriteProcMem(BallPattern3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BallPattern3");
        WriteProcMem(BallPattern4, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BallPattern4");
        WriteProcMem(BallPattern5, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "BallPattern5");
    };
    {
        /*
        * Ufo:
        * 95(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Ufo);
        fucking37stuff;
        log::info("toRewrite:Ufo:{}", Ufo);
        /*patterns log

        */
        if (UfoPattern1 == 0) UfoPattern1 = patterns::find_pattern("b8 95 0 0 0 c3 b8");
        if (UfoPattern2 == 0) UfoPattern2 = patterns::find_pattern("81 c6 95 0 0 0 eb 17");//
        if (UfoPattern3 == 0) UfoPattern3 = patterns::find_pattern("b8 95 0 0 0 c7 45");//
        //if (UfoPattern4 == 0) UfoPattern4 = patterns::find_pattern("68 95 0 0 0 e8 82");
        if (UfoPattern5 == 0) UfoPattern5 = patterns::find_pattern("bb 95 0 0 0 eb 7e");
        if (UfoPattern6 == 0) UfoPattern6 = patterns::find_pattern("ba 95 0 0 0 89 4d");
        //2.200
        /*//addreses
        14:00:48 CE [InDeCreaseIcons]: toRewrite:Ufo:150
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 345480 (base rva: 125480) with "b8 96 0 0 0", org was "b8 95 0 0 0 c3 b8 60 0 0 0 c3 b8 44 0 0"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 345b0a (base rva: 125b0a) with "81 c6 96 0 0 0", org was "81 c6 95 0 0 0 eb 17 83 c6 60 eb 12 83 c6 44"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 3861b7 (base rva: 1661b7) with "b8 96 0 0 0", org was "b8 95 0 0 0 c7 45 a4 6 0 0 0 89 45 a0 e9"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 2e4d34 (base rva: c4d34) with "68 96 0 0 0", org was "68 95 0 0 0 e8 82 1f 0 0 8b 8d 68 fe ff ff"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 4101f1 (base rva: 1f01f1) with "bb 96 0 0 0", org was "bb 95 0 0 0 eb 7e 68 54 87 61 0 8d 4c 24 2c"
        14:00:48 CE [InDeCreaseIcons]: WriteProcMem at 4f1777 (base rva: 2d1777) with "ba 96 0 0 0", org was "ba 95 0 0 0 89 4d f8 39 55 8 bb 1 0 0 0"
        UfoPattern1 = base + 0x125480;
        UfoPattern2 = base + 0x125B0A;
        UfoPattern3 = base + 0x1661B7;
        UfoPattern4 = base + 0xC4D34;//whotf is this
        UfoPattern5 = base + 0x1F01F1;
        UfoPattern6 = base + 0x2D1777;
        */
        WriteProcMem(UfoPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern1");
        WriteProcMem(UfoPattern2, { 0x81, 0xc6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern2");
        WriteProcMem(UfoPattern3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern3");
        //WriteProcMem(UfoPattern4, { 0x68, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern4");
        WriteProcMem(UfoPattern5, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern5");
        WriteProcMem(UfoPattern6, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "UfoPattern6");
    };
    {
        /*
        * Wave:
        * 29(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Wave);
        fucking37stuff;
        log::info("toRewrite:Wave:{}", Wave);
        if (WavePattern1 == 0) WavePattern1 = patterns::find_patterns("b8 60 0 0 0 c3 b8 44 0 0 0")[0];//0=5ff18
        if (WavePattern2 == 0) WavePattern2 = patterns::find_pattern("b8 60 0 0 0 c7");//
        if (WavePattern3 == 0) WavePattern3 = patterns::find_pattern("ba 60 0 0 0 89");//
        if (WavePattern5 == 0) WavePattern5 = patterns::find_pattern("bb 60 0 0 0 eb");
        WriteProcMem(WavePattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3 }, "WavePattern1");
        WriteProcMem(WavePattern2, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7 }, "WavePattern2");
        WriteProcMem(WavePattern3, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89 }, "WavePattern3");
        WriteProcMem(WavePattern5, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb }, "WavePattern5");
    };
    {//
        /*
        * Robot:
        * 44(16)
        *
        */
        std::vector<unsigned char> toRewrite = intToBytes(Robot);
        fucking37stuff;
        log::info("toRewrite:Robot:{}", Robot); //b8 ? ? ? ? ff 15 ? ? ? ? 80 7d
        if (RobotPattern1 == 0) RobotPattern1 = patterns::find_pattern("b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 33 c0 c3 8d 49");//base + 0x12548C
        if (RobotPattern2 == 0) RobotPattern2 = patterns::find_pattern("b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 33 c0 c3 b8");//base + 0x5FDE3;
        if (RobotPattern3 == 0) RobotPattern3 = patterns::find_pattern("B8 44 00 00 00 C7 45");//base + 0x1661DF;
        if (RobotPattern4 == 0) RobotPattern4 = patterns::find_pattern("BB 44 00 00 00 EB 54");//base + 0x1F021B;
        if (RobotPattern5 == 0) RobotPattern5 = patterns::find_pattern("B8 44 00 00 00 3B C8");//base + 0x2CF186;
        WriteProcMem(RobotPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "RobotPattern1");
        WriteProcMem(RobotPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "RobotPattern2");
        WriteProcMem(RobotPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "RobotPattern3");
        WriteProcMem(RobotPattern4, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "RobotPattern4");
        WriteProcMem(RobotPattern5, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "RobotPattern5");
    };
    {//
        /*
        * Spider:
        * 45(16)
        *
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x125492), "\xB8\x46\x00\x00\x00", 5, NULL);
        //GeometryDash.exe+125492 - B8 46 00 00 00
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1661F3), "\xB8\x46\x00\x00\x00", 5, NULL);
        //GeometryDash.exe+1661F3 - B8 46 00 00 00
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EB453), "\xB8\x46\x00\x00\x00", 5, NULL);
        //GeometryDash.exe+1EB453 - B8 46 00 00 00
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2CF494), "\xB8\x46\x00\x00\x00", 5, NULL);
        //GeometryDash.exe+2CF494 - B8 46 00 00 00
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1F0230), "\xBB\x46\x00\x00\x00", 5, NULL);
        //GeometryDash.exe+1F0230 - BB 46 00 00 00
        */
        std::vector<unsigned char> toRewrite = intToBytes(Spider);
        fucking37stuff;
        log::info("toRewrite:Spider:{}", Spider);
        if (SpiderPattern1 == 0) SpiderPattern1 = patterns::find_pattern("b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 b8 ? ? ? ? c3 33 c0 c3 8d 49");//base + 0x125492;
        if (SpiderPattern2 == 0) SpiderPattern2 = patterns::find_pattern("b8 ? ? ? ? c7 45 ? ? ? ? ? 89 45 ? e9 ? ? ? ? b8 ? ? ? ? c7 45 ? ? ? ? ? 89 45 ? e9 ? ? ? ? b8 ? ? ? ? c7 45 ? ? ? ? ? 89 45 ? eb");//base + 0x1661F3;
        if (SpiderPattern3 == 0) SpiderPattern3 = patterns::find_pattern("B8 45 00 00 00 39 44 24");//base + 0x1EB453;
        if (SpiderPattern4 == 0) SpiderPattern4 = patterns::find_pattern("B8 45 00 00 00 3B C8 0F");//base + 0x2CF494;
        if (SpiderPattern5 == 0) SpiderPattern5 = patterns::find_pattern("bb ? ? ? ? eb ? 68 ? ? ? ? 8d 4c 24 ? e8 ? ? ? ? bb ? ? ? ? eb ? 68 ? ? ? ? 8d 4c 24 ? e8 ? ? ? ? bb ? ? ? ? eb ? 6a");//base + 0x1F0230;
        WriteProcMem(SpiderPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "SpiderPattern1");
        WriteProcMem(SpiderPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "SpiderPattern2");
        WriteProcMem(SpiderPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "SpiderPattern3");
        WriteProcMem(SpiderPattern4, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "SpiderPattern4");
        WriteProcMem(SpiderPattern5, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] }, "SpiderPattern5");
    };
    {//
        /*
        * Swing:
        * 2b(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Swing);
        fucking37stuff;
        log::info("toRewrite:Swing:{}", Swing);
        if (SwingPattern1 == 0) SwingPattern1 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 7");//base + 0x125498;
        if (SwingPattern2 == 0) SwingPattern2 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 63");//base + 0x5FF54;
        if (SwingPattern3 == 0) SwingPattern3 = patterns::find_pattern("b8 2b 0 0 0 c7 45 a4");//base + 0x16625C;
        if (SwingPattern4 == 0) SwingPattern4 = patterns::find_pattern("b8 2b 0 0 0 c3 b8 1b");//base + 0x1812B6;
        if (SwingPattern5 == 0) SwingPattern5 = patterns::find_pattern("bb 2b 0 0 0 eb 2a 68");//base + 0x1F0245;
        if (SwingPattern6 == 0) SwingPattern6 = patterns::find_pattern("ba 2b 0 0 0 89 4d f8");//base + 0x2D1B57;
        WriteProcMem(SwingPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x07 }, "SwingPattern1");
        WriteProcMem(SwingPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x63 }, "SwingPattern2");
        WriteProcMem(SwingPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7, 0x45, 0xa4 }, "SwingPattern3");
        WriteProcMem(SwingPattern4, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x1b }, "SwingPattern4");
        WriteProcMem(SwingPattern5, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb, 0x2a, 0x68 }, "SwingPattern5");
        WriteProcMem(SwingPattern6, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89, 0x4d, 0xf8 }, "SwingPattern6");
    };
    {//
        /*
        * Jetpack:
        * 05(16)
        */
        std::vector<unsigned char> toRewrite = intToBytes(Jetpack);
        fucking37stuff;
        log::info("toRewrite:Jetpack:{}", Jetpack);
        if (JetpackPattern1 == 0) JetpackPattern1 = patterns::find_pattern("b8 5 0 0 0 c3 b8 6 0 0 0 c3 33 c0 c3 8d");//base + 0x1254AA; fucku >:T
        if (JetpackPattern2 == 0) JetpackPattern2 = patterns::find_pattern("b8 5 0 0 0 c7 45 a4");//base + 0x16626D;
        if (JetpackPattern3 == 0) JetpackPattern3 = patterns::find_pattern("b8 5 0 0 0 39 44 24");//base + 0x1EB72E;
        if (JetpackPattern4 == 0) JetpackPattern4 = patterns::find_pattern("bb 5 0 0 0 eb 15");//base + 0x1F025A;
        if (JetpackPattern5 == 0) JetpackPattern5 = patterns::find_pattern("ba 5 0 0 0 89 4d f8");//base + 0x2D15B7;
        WriteProcMem(JetpackPattern1, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc3, 0xb8, 0x06 }, "JetpackPattern1");
        WriteProcMem(JetpackPattern2, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xc7, 0x45, 0xa4 }, "JetpackPattern2");
        WriteProcMem(JetpackPattern3, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x39, 0x44, 0x24 }, "JetpackPattern3");
        WriteProcMem(JetpackPattern4, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0xeb, 0x15, 0x6a }, "JetpackPattern4");
        WriteProcMem(JetpackPattern5, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3], 0x89, 0x4d, 0xf8 }, "JetpackPattern5");
    };
#endif
}
#include <Geode/loader/SettingEvent.hpp>
$execute{
        listenForAllSettingChanges([](SettingValue* hi) {
                if (bool(hi->getModID() == Mod::get()->getID()) and !CCDirector::get()->m_pRunningScene->getChildByIDRecursive("RELOAD_POP"_spr)) {
                    auto asd = geode::createQuickPopup(
                        "Reload All",
                        "Reload resources to take effect?",
                        "Later", "Yes",
                        [](auto, bool btn2) {
                            if (btn2) GameManager::get()->reloadAll(false, false, true);
                        }
                    );
                    asd->setID("RELOAD_POP"_spr);
                };
            });
};
#include <Geode/modify/LoadingLayer.hpp>
class $modify(LoadingLayer) {
    void loadingFinished() {
        UpdateIconsCount();
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
        {
            std::stringstream num;
            for (int io = 1; io <= Cube; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/player_" + num.str() + ".plist");
                auto FrameToTest = ("player_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
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
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        {
            std::stringstream num;
            for (int io = 1; io <= Ball; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/player_ball_" + num.str() + ".plist");
                auto FrameToTest = ("player_ball_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        {
            std::stringstream num;
            for (int io = 1; io <= Ufo; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/bird_" + num.str() + ".plist");
                auto FrameToTest = ("bird_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        {
            std::stringstream num;
            for (int io = 1; io <= Wave; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/dart_" + num.str() + ".plist");
                auto FrameToTest = ("dart_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        {
            std::stringstream num;
            for (int io = 1; io <= Swing; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/swing_" + num.str() + ".plist");
                auto FrameToTest = ("swing_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        {
            std::stringstream num;
            for (int io = 1; io <= Jetpack; io++) {
                num << std::setw(2) << std::setfill('0') << io;
                auto TarFile = ("icons/jetpack_" + num.str() + ".plist");
                auto FrameToTest = ("jetpack_" + num.str() + "_001.png");
                if (!CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameToTest.c_str())) break;
                log::debug("Adding frames with file \"{}\"", TarFile);
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TarFile.c_str());
                num.str("");
            }
        }
        LoadingLayer::loadingFinished();
    };
};

#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
#ifndef GEODE_IS_WINDOWS
    static int countForType(IconType p0) {
        auto rtn = GameManager::countForType(p0);
        auto log = fmt::format("{}({}) org rtn: {}", __func__, (int)p0, rtn);
        log::debug("{}", log);
        geode::createQuickPopup(__func__, log, "asd", nullptr, nullptr);
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
#endif
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
