#pragma once

#include "Component.h"

class Actor;
class BoxComponent;

class PlayerMoveComponent : public Component {
public:
    PlayerMoveComponent(Actor* owner, int updateOrder = 10);
    virtual void start() override;
    virtual void update(float deltaTime) override;

private:
    bool isMovement();

    float mSpeed;
    BoxComponent* mBox;
};
