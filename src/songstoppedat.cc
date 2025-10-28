#include "songstoppedat.hh"

static unsigned int SongStoppedAt = 0;

static void getBackgroundMusicTimeMilli(unsigned int* i, int index) {
    FMOD::Channel* channel;
    FMOD_RESULT result;

    result = FMODAudioEngine::get()->m_backgroundMusicChannel->getChannel(index, &channel);
    if (result != FMOD_OK) {
        return;
    }

    result = channel->getPosition(i, FMOD_TIMEUNIT_MS);
}

void SSA::updateBackgroundMusicTimeMilli() {
    getBackgroundMusicTimeMilli(&SongStoppedAt, 0);
}

unsigned int SSA::getSongStoppedAtMilli() {
    return SongStoppedAt;
}