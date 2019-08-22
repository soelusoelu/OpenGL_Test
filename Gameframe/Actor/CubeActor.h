#pragma once

#include "Actor.h"

class IActorMediator;
class BoxComponent;

class CubeActor : public Actor {
public:
    CubeActor(IGameMediator* iGameMediator, IActorMediator* iActorMediator);
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    float mtimer;
    BoxComponent* mBox;
};

