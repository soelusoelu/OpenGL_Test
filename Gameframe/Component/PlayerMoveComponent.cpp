#include "PlayerMoveComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"

PlayerMoveComponent::PlayerMoveComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f) {
}

void PlayerMoveComponent::start() {
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = 0.f;
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        rotation = 1.f;
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        rotation = -1.f;
    }
    getOwner()->getTransform()->rotate(rotation * deltaTime, Vector3::up);

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 1.f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -1.f;
    }
    getOwner()->getTransform()->translete(Vector3(
        Math::Sin(Math::ToRadians(getOwner()->getTransform()->getRotation().y)) * mSpeed * deltaTime,
        0.f,
        Math::Cos(Math::ToRadians(getOwner()->getTransform()->getRotation().y)) * mSpeed * deltaTime
    ));
}

float PlayerMoveComponent::getSpeed() const {
    return mSpeed;
}
