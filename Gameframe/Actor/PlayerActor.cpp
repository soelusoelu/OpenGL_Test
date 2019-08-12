#include "PlayerActor.h"
#include "../Scene/GamePlay.h"
#include "../Component/PlayerMoveComponent.h"
#include "../Component/TransformComponent.h"
#include "../Component/MeshComponent.h"
#include "../Component/SkeletonComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/Collider/BoxComponent.h"
#include <gslib.h>
#include <iostream>

PlayerActor::PlayerActor(GamePlay* game) :
    Actor(game),
    mRadius(2.f),
    mPlayerMove(new PlayerMoveComponent(this)),
    mMesh(new MeshComponent(this, "./res/character.msh")),
    mSkelton(new SkeletonComponent(this, "./res/character.skl")),
    mAnimation(new AnimationComponent(this, "./res/character.anm")),
    mBox(new BoxComponent(this)) {
}

PlayerActor::~PlayerActor() {
}

void PlayerActor::updateActor(float deltaTime) {
}

void PlayerActor::drawActor() const {
    mMesh->draw();
}

float PlayerActor::getRadius() const {
    return mRadius;
}
