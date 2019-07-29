#include "PlayerActor.h"
#include "Scene/GamePlay.h"
#include "PlayerMoveComponent.h"
#include "TransformComponent.h"
#include "MeshComponent.h"
#include "SkeltonComponent.h"
#include "AnimationComponent.h"
#include <gslib.h>
#include <iostream>

PlayerActor::PlayerActor(GamePlay& game, unsigned int id) :
    Actor(game),
    mRadius(2.f),
    mPlayerMove(new PlayerMoveComponent(*this)),
    mMesh(new MeshComponent(*this, "./res/character.msh")),
    mSkelton(new SkeltonComponent(*this, "./res/character.skl")),
    mAnimation(new AnimationComponent(*this, "./res/character.anm")) {
}

PlayerActor::~PlayerActor() {
}

void PlayerActor::updateActor(float deltaTime) {
    mPlayerMove->update(deltaTime);
    mAnimation->update(deltaTime);
}

void PlayerActor::drawActor() const {
    mMesh->draw();
}

void PlayerActor::vector3FromHorizontalDir(GSvector3* out) const {
    gsVector3FromEleDir(out, 0.f, getTransform().getRotation());
}

float PlayerActor::getRadius() const {
    return mRadius;
}
