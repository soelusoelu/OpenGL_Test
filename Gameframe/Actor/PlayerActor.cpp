#include "PlayerActor.h"
#include "../Math.h"
#include "../Scene/GamePlay.h"
#include "../Component/PlayerMoveComponent.h"
#include "../Component/TransformComponent.h"
#include "../Component/MeshComponent.h"
#include "../Component/SkeletonComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Actor/CubeActor.h"
#include <gslib.h>
#include <iostream>

PlayerActor::PlayerActor(GamePlay* game) :
    Actor(game),
    mRadius(2.f),
    mPlayerMove(new PlayerMoveComponent(this)),
    mMesh(new MeshComponent(this, "./res/character.msh")),
    mSkelton(new SkeletonComponent(this, "./res/character.skl")),
    mAnimation(new AnimationComponent(this, "./res/character.anm")) {
}

PlayerActor::~PlayerActor() {
}

void PlayerActor::updateActor(float deltaTime) {
}

void PlayerActor::drawActor() const {
    mMesh->draw();
}

Vector3& PlayerActor::vector3FromHorizontalDir() const {
    Vector3 out;
    //out.x = Math::Cos(0.f) * Math::Sin(getTransform()->getUp().y * Math::deg2Rad);
    //out.y = -Math::Sin(0.f);
    //out.z = Math::Cos(0.f) * Math::Cos(getTransform()->getUp().y * Math::deg2Rad);
    return out;
}

float PlayerActor::getRadius() const {
    return mRadius;
}
