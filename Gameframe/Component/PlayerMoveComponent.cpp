#include "PlayerMoveComponent.h"
#include "../Actor/Actor.h"
#include "TransformComponent.h"
#include "../Utility/Math.h"
#include "../Utility/Input.h"
#include "../Utility/Collision.h"
#include "Collider/BoxComponent.h"
#include "../Scene/IGameMediator.h"
#include "../System/GameSystem.h"
#include "../System/Physics.h"

PlayerMoveComponent::PlayerMoveComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f),
    mBox(nullptr) {
}

void PlayerMoveComponent::start() {
    mBox = getOwner()->getComponent<BoxComponent>();
}

void PlayerMoveComponent::update(float deltaTime) {
    float rotation = Input::horizontal() * deltaTime;
    if (!Math::nearZero(rotation)) {
        getOwner()->getTransform()->rotate(Vector3::up, rotation);
    }

    mSpeed = Input::vertical() * deltaTime;
    if (!Math::nearZero(mSpeed) && canMovement()) {
        getOwner()->getTransform()->translete(getOwner()->getTransform()->forward() * mSpeed);
    }
}

bool PlayerMoveComponent::canMovement() {
    //自身の当たり判定が無効になってれば問答無用でtrue
    if (!mBox->getEnable()) {
        return true;
    }

    getOwner()->computeWorldTransform();

    //コピーで大丈夫
    AABB playerBox = mBox->getCollision();
    playerBox.mMin += getOwner()->getTransform()->forward() * mSpeed;
    playerBox.mMax += getOwner()->getTransform()->forward() * mSpeed;

    const auto& boxes = getOwner()->getIGameMediator()->getSystem()->getPhysics()->getBoxes();
    for (const auto& box : boxes) {
        if (box->getIsTrigger() || !box->getEnable() || box->getOwner()->getTag() == "Player") {
            continue;
        }
        //このアクターと衝突するか？
        const AABB& otherBox = box->getCollision();
        if (intersect(playerBox, otherBox)) {
            return false;
        }
    }

    //誰ともぶつかっていないから動ける
    return true;
}
