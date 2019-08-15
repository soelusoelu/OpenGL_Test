#include "Sound.h"

Sound::Sound(unsigned int id, const char* filename) :
    mID(id),
    mFilename(filename),
    mActive(false) {
}

Sound::~Sound() {
}

const bool Sound::isPlay() const {
    return mActive;
}
