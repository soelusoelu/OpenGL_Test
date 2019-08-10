#include "BoxComponent.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"
#include "../Scene/GamePlay.h"
#include "../Physics.h"

BoxComponent::BoxComponent(Actor* owner) :
    Component(owner),
    mCollision(Vector3::zero, Vector3::one),
    mShouldRotate(true) {
    getOwner()->getGame()->getPhysics()->AddBox(this);
}

BoxComponent::~BoxComponent() {
    getOwner()->getGame()->getPhysics()->RemoveBox(this);
}

void BoxComponent::start() {
}

void BoxComponent::update(float deltaTime) {
}

void BoxComponent::onUpdateWorldTransform() {
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
    mCollision = model;
}

const AABB& BoxComponent::getCollision() const {
    return mCollision;
}

void BoxComponent::setShouldRotate(bool set) {
    mShouldRotate = set;
}
