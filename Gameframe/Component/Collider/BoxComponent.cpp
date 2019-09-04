#include "BoxComponent.h"
#include "../TransformComponent.h"
#include "../../Actor/Actor.h"
#include "../../System/GameSystem.h"
#include "../../System/Physics.h"
#include "../../Utility/Singleton.h"

BoxComponent::BoxComponent(Actor* owner, bool isTrigger) :
    Collider(owner, isTrigger),
    mDefaultCollision(Vector3::negOne, Vector3::one),
    mCollision(mDefaultCollision),
    mShouldRotate(true) {
    Singleton<GameSystem>::instance().getPhysics()->addBox(this);
}

BoxComponent::~BoxComponent() {
    Singleton<GameSystem>::instance().getPhysics()->removeBox(this);
}

void BoxComponent::onUpdateWorldTransform() {
    mCollision = mDefaultCollision;
    //スケーリング
    mCollision.mMin *= mOwner->getTransform()->getScale();
    mCollision.mMax *= mOwner->getTransform()->getScale();
    //回転
    if (mShouldRotate) {
        mCollision.rotate(mOwner->getTransform()->getRotation());
    }
    //移動
    mCollision.mMin += mOwner->getTransform()->getPosition();
    mCollision.mMax += mOwner->getTransform()->getPosition();
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
