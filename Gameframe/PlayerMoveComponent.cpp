#include "PlayerMoveComponent.h"
#include "PlayerActor.h"
#include "Component.h"
#include "Actor.h"
#include "TransformComponent.h"
#include <gslib.h>

PlayerMoveComponent::PlayerMoveComponent(Actor& owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f) {
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = getOwner().getTransform().getRotation();
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
    getOwner().getTransform().setRotation(rotation);

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 0.5f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -0.5;
    }
    GSvector3 position = getOwner().getTransform().getPosition();
    position.x += gsSin(getOwner().getTransform().getRotation()) * mSpeed * deltaTime;
    position.z += gsCos(getOwner().getTransform().getRotation()) * mSpeed * deltaTime;
    getOwner().getTransform().setPosition(position);
}

float PlayerMoveComponent::getSpeed() const {
    return mSpeed;
}
