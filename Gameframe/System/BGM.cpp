#include "BGM.h"
#include <gslib.h>
#include <iostream>

BGM::BGM(unsigned int id, const char* filename, GMIDIFLAG flag) :
    Sound(id, filename),
    mFlag(flag) {
    gsLoadBGM(mID, mFilename, mFlag);
}

BGM::~BGM() {
    gsDeleteBGM(mID);
    std::cout << "BGM destructor" << std::endl;
}

void BGM::play() {
    mActive = true;
    gsPlayBGM(mID);
}

void BGM::stop() {
    mActive = false;
    gsStopBGM();
}

void BGM::pause() {
    mActive = false;
    gsPauseBGM();
}

void BGM::restart() {
    mActive = true;
    gsRestartBGM();
}

void BGM::setFlag(GMIDIFLAG set) {
    mFlag = set;
    gsLoadBGM(mID, mFilename, mFlag);
    play();
}
