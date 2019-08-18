﻿#include "BoxComponent.h"
#include "../Component.h"
#include "../../Actor/Actor.h"
#include "../TransformComponent.h"
#include "../../Scene/GamePlay.h"
#include "../../System/GameSystem.h"
#include "../../System/Physics.h"

BoxComponent::BoxComponent(Actor* owner, bool isTrigger) :
    Collider(owner, isTrigger),
    mDefaultCollision(Vector3::negOne, Vector3::one),
    mCollision(mDefaultCollision),
    mShouldRotate(true) {
    getOwner()->getGamePlay()->getSystem()->getPhysics()->addBox(this);
}

BoxComponent::~BoxComponent() {
    getOwner()->getGamePlay()->getSystem()->getPhysics()->removeBox(this);
}

void BoxComponent::onUpdateWorldTransform() {
    mCollision = mDefaultCollision;
    //スケーリング
    mCollision.mMin *= getOwner()->getTransform()->getScale();
    mCollision.mMax *= getOwner()->getTransform()->getScale();
    //回転
    if (mShouldRotate) {
        mCollision.rotate(getOwner()->getTransform()->getRotation());
    }
    //移動
    mCollision.mMin += getOwner()->getTransform()->getPosition();
    mCollision.mMax += getOwner()->getTransform()->getPosition();
}

void BoxComponent::setCollision(const AABB& model) {
    mDefaultCollision = model;
}

const AABB& BoxComponent::getCollision() const {
    return mCollision;
}

void BoxComponent::setShouldRotate(bool set) {
    mShouldRotate = set;
}

Collider::ColliderType BoxComponent::getColliderType() const {
    return ColliderType::AABBT;
}