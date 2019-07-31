#pragma once

#include "Component.h"

class Actor;

class PlayerMoveComponent : public Component {
public:
    PlayerMoveComponent(Actor& owner, int updateOrder = 10);
    virtual void update(float deltaTime) override;

    float getSpeed() const;

private:
    float mSpeed;
};

