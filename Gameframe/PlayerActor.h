#pragma once

#include "Actor.h"
#include <gslib.h>

class GamePlay;
class PlayerMoveComponent;

class PlayerActor : public Actor {
public:
    PlayerActor(GamePlay& game, unsigned int id);
    ~PlayerActor();

    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;
    void vector3FromHorizontalDir(GSvector3* out) const;

    float getRadius() const;

private:
    unsigned int mID;
    float mAnimationTimer;
    unsigned int mAnimationNo;
    float mRadius;
    PlayerMoveComponent* mPlayerMove;
};

