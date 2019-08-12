#pragma once

#include "Sound.h"
#include <gslib.h>

class BGM : public Sound {
public:
    BGM(unsigned int id, const char* filename, GMIDIFLAG flag = GMIDIFLAG::GMIDI_LOOP);
    ~BGM();
    virtual void play() override;
    virtual void stop() override;
    virtual void pause() override;
    virtual void restart() override;
    void setFlag(GMIDIFLAG set);

private:
    GMIDIFLAG mFlag;
};

