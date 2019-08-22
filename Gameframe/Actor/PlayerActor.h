#pragma once

#include "../Utility/Math.h"
#include "Actor.h"

class IGameMediator;
class IActorMediator;
class PlayerMoveComponent;
class MeshComponent;
class SkeletonComponent;
class AnimationComponent;
class BoxComponent;

class PlayerActor : public Actor {
public:
    PlayerActor(IGameMediator* iGameMediator, IActorMediator* iActorMediator, const char* tag = "Player");
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    PlayerMoveComponent* mPlayerMove;
    MeshComponent* mMesh;
    SkeletonComponent* mSkelton;
    AnimationComponent* mAnimation;
    BoxComponent* mBox;
};

