#pragma once

#include <gslib.h>

class Sound {
public:
    Sound(unsigned int id, const char* filename);
    virtual ~Sound();
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void restart() = 0;
    virtual const bool isPlay() const;

protected:
    unsigned int mID;
    const char* mFilename;
    bool mActive;
};

