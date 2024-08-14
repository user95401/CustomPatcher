#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
using namespace geode::prelude;

#include <regex>

//lol
#define SETTING(type, key_name) Mod::get()->getSettingValue<type>(key_name)
#define public_cast(value, member) [](auto* v) { \
	class FriendClass__; \
	using T = std::remove_pointer<decltype(v)>::type; \
	class FriendeeClass__: public T { \
	protected: \
		friend FriendClass__; \
	}; \
	class FriendClass__ { \
	public: \
		auto& get(FriendeeClass__* v) { return v->member; } \
	} c; \
	return c.get(reinterpret_cast<FriendeeClass__*>(v)); \
}(value)

namespace geode::cocos {
    auto createWideMDPopup(char const* title, std::string const& content, char const* btn1, char const* btn2 = nullptr,
        float width = 400.f, utils::MiniFunction<void(FLAlertLayer*, bool)> selected = nullptr, bool doShow = true) {
        auto pop = createQuickPopup(
            title,
            "\n \n \n \n \n \n \n \n \n",
            btn1, btn2 = nullptr, width, selected, doShow
        );
        auto mdtextarea = MDTextArea::create(content, { width - 50.f, 180.f });
        mdtextarea->setPositionY(116.f);//(-(mdtextarea->getContentSize() / 2));
        public_cast(mdtextarea, m_bgSprite)->setOpacity(36);
        pop->m_buttonMenu->addChild(mdtextarea);
        handleTouchPriority(pop);
        return pop;
    }
}
namespace geode::utils {
    //std::vector<uint8_t> { intToBytes(777)[0], intToBytes(777)[1], intToBytes(777)[2],intToBytes(777)[3] }
    inline std::vector<unsigned char> intToBytes(int value) {
        std::vector<unsigned char> result;
        result.push_back(value & 0x000000ff);
        result.push_back((value & 0x0000ff00) >> 8);
        result.push_back((value & 0x00ff0000) >> 16);
        result.push_back((value & 0xff000000) >> 24);
        return result;
    }
}
namespace geode::utils::string {
    inline std::vector<std::string> explode(std::string separator, std::string input) {
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
}

template<typename Addr>
inline void patch(Addr addr, ByteVector const& data, std::string comment = "") {
    for (auto patch : Mod::get()->getPatches()) {
        if (patch->getAddress() == addr) {
            auto update = patch->updateBytes(data);
            if (update.isOk()) void();//log::debug("PATCH UPDATED: {}{}", patch->getRuntimeInfo(), comment);
            else log::error("PATCH UPDATE FAILED: {}{}", update.error(), comment);
            return;
        };
    }
    auto newp = Mod::get()->patch(reinterpret_cast<void*>
        (addr),
        data
    );
    if (newp.isOk()) void();//log::debug("CREATED PATCH: {}{}", newp.value()->getRuntimeInfo(), comment);
    else log::error("FAILED TO CREATE PATCH: {}{}", newp.error(), comment);
}