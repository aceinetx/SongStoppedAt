
using namespace geode::prelude;

#include "../songstoppedat.hh"

#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

// clang-format off
class $modify(SSAEditorUI, EditorUI){
    struct Fields {
        bool m_playbackState = false;
    };

	bool init(LevelEditorLayer* editorLayer){
		if (!EditorUI::init(editorLayer)){
			return false;
		}

		return true;
	}

    void onPlayback(cocos2d::CCObject* sender){
        if(m_fields->m_playbackState == true){
            SSA::updateBackgroundMusicTimeMilli();
        }

        m_fields->m_playbackState = !m_fields->m_playbackState;

        EditorUI::onPlayback(sender);
    }
};

