#include <Geode/Geode.hpp>
#include <Geode/modify/TextGameObject.hpp>

using namespace geode::prelude;

static std::string replaceAll(std::string s, std::string const& from, std::string const& to) {
	if (from.empty()) return s;
	size_t pos = 0;
	while ((pos = s.find(from, pos)) != std::string::npos) {
		s.replace(pos, from.size(), to);
		pos += to.size();
	}
	return s;
}

class $modify(MultilineTextObject, TextGameObject) {
	void updateTextObject(std::string text, bool p1) {
		std::string str = text;
		auto token = Mod::get()->getSettingValue<std::string>("newline-token");
		str = replaceAll(str, token, "\n");
		TextGameObject::updateTextObject(str, p1);
	}
};
