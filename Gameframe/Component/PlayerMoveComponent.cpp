#include "PlayerMoveComponent.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"
#include "../Utility/Math.h"
#include "../Utility/Input.h"

PlayerMoveComponent::PlayerMoveComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder) {
}

void PlayerMoveComponent::start() {
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = Input::horizontal() * 2.f * deltaTime;
    getOwner()->getTransform()->rotate(Vector3::up, rotation);

    float speed = Input::vertical() * deltaTime;
    getOwner()->getTransform()->translete(getOwner()->getTransform()->forward() * speed);
}
