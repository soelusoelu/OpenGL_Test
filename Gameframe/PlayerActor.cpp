#include "PlayerActor.h"
#include "Scene/GamePlay.h"
#include "PlayerMoveComponent.h"
#include <gslib.h>
#include <iostream>

PlayerActor::PlayerActor(GamePlay& game, unsigned int id) :
    Actor(game),
    mID(id),
    mAnimationTimer(0.f),
    mAnimationNo(0),
    mRadius(2.f),
    mPlayerMove(new PlayerMoveComponent(*this)) {
    gsLoadMesh(mID, "./res/character.msh");
    gsLoadSkeleton(mID, "./res/character.skl");
    gsLoadAnimation(mID, "./res/character.anm");
}

PlayerActor::~PlayerActor() {
    gsDeleteMesh(mID);
    gsDeleteSkeleton(mID);
    gsDeleteAnimation(mID);
}

void PlayerActor::updateActor(float deltaTime) {
    mAnimationTimer += 1.5f * deltaTime;
    mPlayerMove->update(deltaTime);
}

void PlayerActor::drawActor() const {
    gsBindAnimation(mID, mAnimationNo, mAnimationTimer);
    gsBindSkeleton(mID);

    glPushMatrix();
    glTranslatef(mPosition.x, mPosition.y, mPosition.z);
    glRotatef(mRotation, 0.f, 1.f, 0.f);
    glScalef(mScale.x, mScale.y, mScale.z);
    gsDrawMesh(mID);
    glPopMatrix();
}

void PlayerActor::vector3FromHorizontalDir(GSvector3* out) const {
    gsVector3FromEleDir(out, 0.f, mRotation);
}

float PlayerActor::getRadius() const {
    return mRadius;
}
