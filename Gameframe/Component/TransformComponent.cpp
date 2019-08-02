#include "TransformComponent.h"
#include "Component.h"
#include <gslib.h>

TransformComponent::TransformComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mPosition(GSvector3(0.f, 0.f, 0.f)),
    mRotation(GSvector3(0.f, 0.f, 0.f)),
    mScale(GSvector3(1.f, 1.f, 1.f)),
    mRecomputeTransform(true) {
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::start() {
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

void TransformComponent::translete(const GSvector3& translation) {
    mPosition += translation;
    mRecomputeTransform = true;
}

const GSvector3& TransformComponent::getRotation() const {
    return mRotation;
}

void TransformComponent::setRotation(const GSvector3& angle) {
    mRotation = angle;
    mRecomputeTransform = true;
}

void TransformComponent::setRotation(float angleX, float angleY, float angleZ) {
    mRotation.x = angleX;
    mRotation.y = angleY;
    mRotation.z = angleZ;
    mRecomputeTransform = true;
}

void TransformComponent::rotate(float angle, const GSvector3& axis) {
    mRotation += axis * angle;
    if (mRotation.x > 180.f) {
        mRotation.x -= 360.f;
    } else if (mRotation.x < -180.f) {
        mRotation.x += 360.f;
    }
    if (mRotation.y > 180.f) {
        mRotation.y -= 360.f;
    } else if (mRotation.y < -180.f) {
        mRotation.y += 360.f;
    }
    if (mRotation.z > 180.f) {
        mRotation.z -= 360.f;
    } else if (mRotation.z < -180.f) {
        mRotation.z += 360.f;
    }
    mRecomputeTransform = true;
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
