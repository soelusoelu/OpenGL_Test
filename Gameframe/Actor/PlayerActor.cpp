#include "PlayerActor.h"
#include "../Scene/GamePlay.h"
#include "../Component/PlayerMoveComponent.h"
#include "../Component/TransformComponent.h"
#include "../Component/MeshComponent.h"
#include "../Component/SkeletonComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Actor/CubeActor.h"
#include <gslib.h>
#include <iostream>

PlayerActor::PlayerActor(GamePlay& game) :
    Actor(game),
    mRadius(2.f),
    mPlayerMove(new PlayerMoveComponent(*this)),
    mMesh(new MeshComponent(*this, "./res/character.msh")),
    mSkelton(new SkeletonComponent(*this, "./res/character.skl")),
    mAnimation(new AnimationComponent(*this, "./res/character.anm")) {
}

PlayerActor::~PlayerActor() {
}

void PlayerActor::updateActor(float deltaTime) {
}

void PlayerActor::drawActor() const {
    mMesh->draw();
}

void PlayerActor::vector3FromHorizontalDir(GSvector3* out) const {
    gsVector3FromEleDir(out, 0.f, getTransform().getRotation().y);
}

float PlayerActor::getRadius() const {
    return mRadius;
}
