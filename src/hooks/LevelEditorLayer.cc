
using namespace geode::prelude;

#include "../songstoppedat.hh"

#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

// clang-format off
class $modify(SSALevelEditorLayer, LevelEditorLayer){
	bool init(GJGameLevel * level, bool p1){
		if (!LevelEditorLayer::init(level, p1)){
			return false;
		}

		return true;
	}

	void onStopPlaytest(){
    	SSA::updateBackgroundMusicTimeMilli();

		LevelEditorLayer::onStopPlaytest();
	}
};
