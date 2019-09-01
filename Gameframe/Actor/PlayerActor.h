#pragma once

#include "Actor.h"

class PlayerMoveComponent;
class MeshComponent;
class SkeletonComponent;
class AnimationComponent;
class BoxComponent;

class PlayerActor : public Actor {
    friend class Actor;
public:
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    PlayerActor(const char* tag = "Player");
    ~PlayerActor() {};

    PlayerMoveComponent* mPlayerMove;
    MeshComponent* mMesh;
    SkeletonComponent* mSkelton;
    AnimationComponent* mAnimation;
    BoxComponent* mBox;
};

