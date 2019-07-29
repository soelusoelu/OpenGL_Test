#include "TransformComponent.h"
#include "Component.h"
#include "Actor.h"
#include <gslib.h>

TransformComponent::TransformComponent(Actor& owner, int updateOrder) :
    Component(owner, updateOrder),
    mPosition(GSvector3(0.f, 0.f, 0.f)),
    mRotation(0.f),
    mScale(GSvector3(1.f, 1.f, 1.f)),
    mRecomputeTransform(true) {
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::update(float deltaTime) {
}

const GSvector3& TransformComponent::getPosition() const {
    return mPosition;
}

void TransformComponent::setPosition(const GSvector3& pos) {
    mPosition = pos;
    mRecomputeTransform = true;
}

float TransformComponent::getRotation() const {
    return mRotation;
}

void TransformComponent::setRotation(const float rotation) {
    mRotation = rotation;
    mRecomputeTransform = true;
}

void TransformComponent::rotate(float rotation) {
    mRotation += rotation;
}

const GSvector3& TransformComponent::getScale() const {
    return mScale;
}

void TransformComponent::setScale(const GSvector3& scale) {
    mScale = scale;
    mRecomputeTransform = true;
}

bool TransformComponent::getRecomputeTransform() const {
    return mRecomputeTransform;
}

void TransformComponent::setRecomputeTransform(bool set) {
    mRecomputeTransform = set;
}
