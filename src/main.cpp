#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

unsigned int SongStoppedAt = 0;

void getBackgroundMusicTimeMilli(unsigned int *i, int index) {
	FMOD::Channel* channel;
	FMOD_RESULT result;

	result = FMODAudioEngine::get()->m_backgroundMusicChannel->getChannel(index, &channel);
	if(result != FMOD_OK){
		return;
	}

	result = channel->getPosition(i, FMOD_TIMEUNIT_MS);	
}

class $modify(NewLevelEditorLayer, LevelEditorLayer){
	bool init(GJGameLevel * p0, bool p1){
		if (!LevelEditorLayer::init(p0, p1)){
			return false;
		}

		return true;
	}

	void onStopPlaytest(){
		getBackgroundMusicTimeMilli(&SongStoppedAt, 0);

		LevelEditorLayer::onStopPlaytest();
	}

};

class $modify(NewEditorPauseLayer, EditorPauseLayer){
	bool init(LevelEditorLayer * p0){
		if (!EditorPauseLayer::init(p0)){
			return false;
		}

		auto text = CCString::createWithFormat("Song stopped at %i", SongStoppedAt);
		auto text_cstr = text->getCString();
		auto label = CCLabelBMFont::create(text_cstr, "chatFont.fnt");
		auto pos_x = CCDirector::sharedDirector()->getWinSize().width / 2;
		auto pos_y = 306;

		label->setPositionX(pos_x);
		label->setPositionY(pos_y);
		label->setScale(0.65);
		this->addChild(label);

		return true;
	}
};
