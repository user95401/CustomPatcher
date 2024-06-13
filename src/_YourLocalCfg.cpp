#include <Geode/Geode.hpp>
using namespace geode::prelude;

auto g_game_json = Mod::get()->getConfigDir() / "settings.json";
auto g_game_dir = Mod::get()->getConfigDir();

auto g_data_json = Mod::get()->getSaveDir() / "settings.json";
auto g_data_dir = Mod::get()->getSaveDir();

void copy_settings_from_game_dir() {
    log::info("{}", __FUNCTION__);
    log::debug("g_game_json: {}", g_game_json);
    log::debug("g_game_dir: {}", g_game_dir);
    log::debug("g_data_json: {}", g_data_json);
    log::debug("g_data_dir: {}", g_data_dir);
    if (!std::ifstream(g_game_json.string().c_str()).good()) return log::warn("cant get the {}", g_game_json);
    std::filesystem::copy(
        g_game_json, //from game dir
        g_data_json, //to game data dir
        std::filesystem::copy_options::overwrite_existing);
    Mod::get()->loadData();
};

void copy_settings_from_data_dir() {
    Mod::get()->saveData();
    log::info("{}", __FUNCTION__);
    log::debug("g_game_json: {}", g_game_json);
    log::debug("g_game_dir: {}", g_game_dir);
    log::debug("g_data_json: {}", g_data_json);
    log::debug("g_data_dir: {}", g_data_dir);
    if (!std::ifstream(g_data_json.string().c_str()).good()) return log::warn("cant get the {}", g_data_json);
    std::filesystem::copy(
        g_data_json, //from game data dir
        g_game_json, //to game dir
        std::filesystem::copy_options::overwrite_existing);
};

$on_mod(Loaded) {
    copy_settings_from_game_dir();
};

#include <Geode/loader/SettingEvent.hpp>
$execute{
    listenForAllSettingChanges([](SettingValue* hi) {
        if (bool(hi->getModID() == Mod::get()->getID())) {
            copy_settings_from_data_dir();
        };
    });
};