#pragma once

#include "Actor.h"

class GamePlay;

class CubeActor : public Actor {
public:
    CubeActor(GamePlay& game);
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;
};

