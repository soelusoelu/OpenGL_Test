#include "PlayerMoveComponent.h"
#include "PlayerActor.h"
#include "Component.h"
#include "Actor.h"
#include <gslib.h>
#include <iostream>

PlayerMoveComponent::PlayerMoveComponent(Actor& owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f) {
}

PlayerMoveComponent::~PlayerMoveComponent() {
    std::cout << "PlayerMoveComponent destructor" << std::endl;
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = getOwner().getRotation();
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        rotation += 0.5f * deltaTime;
        if (rotation > 180.f) {
            rotation -= 360.f;
        }
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        rotation -= 0.5f * deltaTime;
        if (rotation < -180.f) {
            rotation += 360.f;
        }
    }
    getOwner().setRotation(rotation);

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 0.5f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -0.5;
    }
    if (gsGetKeyState(GKEY_LSHIFT)) {
        mSpeed += 1.f;
    }
    GSvector3 position = getOwner().getPosition();
    position.x += gsSin(getOwner().getRotation()) * mSpeed * deltaTime;
    position.z += gsCos(getOwner().getRotation()) * mSpeed * deltaTime;
    getOwner().setPosition(position);
}

float PlayerMoveComponent::getSpeed() const {
    return mSpeed;
}