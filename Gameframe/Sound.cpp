#include "Sound.h"
#include <iostream>

Sound::Sound(unsigned int id, const char* filename) :
    mID(id),
    mFilename(filename),
    mActive(false) {
}

Sound::~Sound() {
    std::cout << "Sound destructor" << std::endl;
}

const bool Sound::isPlay() const {
    return mActive;
}
