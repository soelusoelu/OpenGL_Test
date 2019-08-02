#include "PlayerMoveComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"
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
        rotation = 1.f;
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        rotation = -1.f;
    }
    getOwner()->getTransform()->rotate(rotation * deltaTime, GSvector3(0.f, 1.f, 0.f));

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 1.f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -1.f;
    }
    getOwner()->getTransform()->translete(GSvector3(
        gsSin(getOwner()->getTransform()->getRotation().y) * mSpeed * deltaTime,
        0.f,
        gsCos(getOwner()->getTransform()->getRotation().y) * mSpeed * deltaTime
    ));
}

float PlayerMoveComponent::getSpeed() const {
    return mSpeed;
}
