#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "../songstoppedat.hh"

#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

// clang-format off
class $modify(SSAEditorPauseLayer, EditorPauseLayer){
	bool init(LevelEditorLayer * editorLayer){
		if (!EditorPauseLayer::init(editorLayer))
			return false;

		auto text = CCString::createWithFormat("Song stopped at %i", SSA::getSongStoppedAtMilli());
		auto text_cstr = text->getCString();
		auto label = CCLabelBMFont::create(text_cstr, "chatFont.fnt");
		auto pos_x = CCDirector::sharedDirector()->getWinSize().width / 2;
		auto pos_y = 306;

		label->setPositionX(pos_x);
		label->setPositionY(pos_y);
		label->setScale(0.65);
		label->setID("song-stopped-at");
		this->addChild(label);

		return true;
	}
};
