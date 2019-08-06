#include "PlayerMoveComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"
#include "../Math.h"
#include <gslib.h>

PlayerMoveComponent::PlayerMoveComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f) {
}

void PlayerMoveComponent::start() {
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = 0.f;
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        rotation = 2.f;
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        rotation = -2.f;
    }
    getOwner()->getTransform()->rotate(Vector3::up, rotation * deltaTime);

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 1.f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -1.f;
    }
    Vector3 t = getOwner()->getTransform()->forward() * mSpeed * deltaTime + getOwner()->getTransform()->right() * mSpeed * deltaTime;
    getOwner()->getTransform()->translete(
        getOwner()->getTransform()->forward() * mSpeed * deltaTime
    );
}

float PlayerMoveComponent::getSpeed() const {
    return mSpeed;
}
