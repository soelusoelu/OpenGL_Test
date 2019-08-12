#pragma once

#include "Actor.h"

class GamePlay;
class BoxComponent;

class CubeActor : public Actor {
public:
    CubeActor(GamePlay* game);
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    float mtimer;
    BoxComponent* mBox;
};

