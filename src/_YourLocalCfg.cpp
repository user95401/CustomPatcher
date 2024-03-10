//geode
#include <Geode/Geode.hpp>
using namespace geode::prelude;

void CopyFromLocal() {
    ghc::filesystem::copy(
        Mod::get()->getConfigDir() / "settings.json", //from game dir
        Mod::get()->getSaveDir() / "settings.json", //to game save dir
        ghc::filesystem::copy_options::overwrite_existing);
};

void CopyFromData() {
    ghc::filesystem::copy(
        Mod::get()->getSaveDir() / "settings.json", //to game save dir
        Mod::get()->getConfigDir() / "settings.json", //from game dir
        ghc::filesystem::copy_options::overwrite_existing);
};

$on_mod(Loaded) {
    CopyFromLocal();
    Mod::get()->loadData();
}

#include <Geode/modify/AppDelegate.hpp>
class $modify(AppDelegate) {
    void trySaveGame(bool p0) {
        AppDelegate::trySaveGame(p0);
        CopyFromData();
    }
};