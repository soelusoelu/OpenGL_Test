#pragma once

#include "Actor.h"

class PlayerMoveComponent;
class MeshComponent;
class SkeletonComponent;
class AnimationComponent;
class BoxComponent;

class PlayerActor : public Actor {
public:
    PlayerActor(const char* tag = "Player");
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    PlayerMoveComponent* mPlayerMove;
    MeshComponent* mMesh;
    SkeletonComponent* mSkelton;
    AnimationComponent* mAnimation;
    BoxComponent* mBox;
};

