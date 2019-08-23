#pragma once

#include "Actor.h"

class BoxComponent;

class CubeActor : public Actor {
public:
    CubeActor(IGameMediator* iGameMediator);
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    BoxComponent* mBox;
};

