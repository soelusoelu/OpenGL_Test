#include "TransformComponent.h"
#include "Component.h"

TransformComponent::TransformComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mPosition(Vector3::zero),
    mRotation(Quaternion::identity),
    mScale(Vector3::one),
    mRecomputeTransform(true) {
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::start() {
}

void TransformComponent::update(float deltaTime) {
}

const Vector3& TransformComponent::getPosition() const {
    return mPosition;
}

void TransformComponent::setPosition(const Vector3& pos) {
    mPosition = pos;
    mRecomputeTransform = true;
}

void TransformComponent::translete(const Vector3& translation) {
    mPosition += translation;
    mRecomputeTransform = true;
}

const Quaternion& TransformComponent::getRotation() const {
    return mRotation;
}

void TransformComponent::setRotation(const Quaternion& rot) {
    mRotation = rot;
    mRecomputeTransform = true;
}

void TransformComponent::setRotation(const Vector3& axis, float angle) {
    angle *= 0.5f * Math::deg2Rad;
    float sinAngle = Math::Sin(angle);

    mRotation.x = axis.x * sinAngle;
    mRotation.y = axis.y * sinAngle;
    mRotation.z = axis.z * sinAngle;
    mRotation.w = Math::Cos(angle);

    mRecomputeTransform = true;
}

void TransformComponent::rotate(const Vector3& euler) {
    Vector3 angles = euler * 0.5f * Math::deg2Rad;
    Quaternion inc;
    inc.x = Math::Sin(angles.x);
    inc.y = Math::Sin(angles.y);
    inc.z = Math::Sin(angles.z);
    inc.w = Math::Cos(angles.x) * Math::Cos(angles.y) * Math::Cos(angles.z);

    mRotation = Quaternion::Concatenate(mRotation, inc);

    mRecomputeTransform = true;
}

void TransformComponent::rotate(const Vector3& axis, float angle) {
    angle *= 0.5f * Math::deg2Rad;
    float sinAngle = Math::Sin(angle);

    Quaternion inc;
    inc.x = axis.x * sinAngle;
    inc.y = axis.y * sinAngle;
    inc.z = axis.z * sinAngle;
    inc.w = Math::Cos(angle);

    mRotation = Quaternion::Concatenate(mRotation, inc);

    mRecomputeTransform = true;
}

void TransformComponent::lookAt(const Vector3& target) {
    Matrix4::CreateLookAt(mPosition, target, Vector3::up);
    mRecomputeTransform = true;
}

const Vector3& TransformComponent::getScale() const {
    return mScale;
}

void TransformComponent::setScale(const Vector3& scale) {
    mScale = scale;
    mRecomputeTransform = true;
}

const Vector3 TransformComponent::forward() const {
    return Vector3::Transform(Vector3::forward, mRotation);
}

const Vector3 TransformComponent::right() const {
    return Vector3::Transform(Vector3::right, mRotation);
}

bool TransformComponent::getRecomputeTransform() const {
    return mRecomputeTransform;
}

void TransformComponent::setRecomputeTransform(bool set) {
    mRecomputeTransform = set;
}
