#pragma once

#include "Sound.h"
#include <gslib.h>

class SE : public Sound {
public:
    SE(unsigned int id, const char* filename, int count, GWAVEFLAG flag = GWAVE_DEFAULT);
    ~SE();
    virtual void play() override;
    virtual void stop() override;
    virtual void pause() override;
    virtual void restart() override;
    void setFlag(GWAVEFLAG set);

private:
    int mCount;
    GWAVEFLAG mFlag;
};

