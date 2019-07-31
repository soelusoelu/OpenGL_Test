#pragma once

#include "Actor.h"

class GamePlay;

class SkyBoxActor : public Actor {
public:
    SkyBoxActor(GamePlay& game, unsigned int meshID);
    ~SkyBoxActor();
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    unsigned int mMeshID;
    float mViewRoll; //z����]
    float mViewPitch; //x����]
    float mViewYow; //y����]
};

