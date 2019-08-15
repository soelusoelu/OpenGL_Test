#include "SE.h"
#include <iostream>

SE::SE(unsigned int id, const char* filename, int count, GWAVEFLAG flag) :
    Sound(id, filename),
    mCount(count),
    mFlag(flag) {
    gsLoadSE(mID, mFilename, count, mFlag);
}

SE::~SE() {
    gsDeleteSE(mID);
    std::cout << "SE destructor" << std::endl;
}

void SE::play() {
    mActive = true;
    gsPlaySE(mID);
}

void SE::stop() {
    mActive = false;
    gsStopSE(mID);
}

void SE::pause() {
    mActive = false;
    gsPauseBGM();
}

void SE::restart() {
    mActive = true;
    gsRestartBGM();
}

void SE::setFlag(GWAVEFLAG set) {
    mFlag = set;
    gsLoadSE(mID, mFilename, mCount, mFlag);
    play();
}
