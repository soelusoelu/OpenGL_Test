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

void PlayerActor::vector3FromHorizontalDir(Vector3* out) const {
    out->x = Math::Cos(Math::ToRadians(0.f)) * Math::Sin(Math::ToRadians(getTransform()->getRotation().y));
    out->y = -Math::Sin(Math::ToRadians(0.f));
    out->z = Math::Cos(Math::ToRadians(0.f)) * Math::Cos(Math::ToRadians(getTransform()->getRotation().y));
}

float PlayerActor::getRadius() const {
    return mRadius;
}
