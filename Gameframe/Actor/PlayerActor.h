#pragma once

#include "../Math.h"
#include "Actor.h"

class GamePlay;
class PlayerMoveComponent;
class MeshComponent;
class SkeletonComponent;
class AnimationComponent;

class PlayerActor : public Actor {
public:
    PlayerActor(GamePlay* game);
    ~PlayerActor();

    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;
    Vector3& vector3FromHorizontalDir() const;

    float getRadius() const;

private:
    float mRadius;
    PlayerMoveComponent* mPlayerMove;
    MeshComponent* mMesh;
    SkeletonComponent* mSkelton;
    AnimationComponent* mAnimation;
};

