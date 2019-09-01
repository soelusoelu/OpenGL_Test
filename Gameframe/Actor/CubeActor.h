#pragma once

#include "Actor.h"

class BoxComponent;

class CubeActor : public Actor {
    friend class Actor;
public:
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    CubeActor();
    ~CubeActor() {};

    BoxComponent* mBox;
};

