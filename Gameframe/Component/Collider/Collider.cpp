#include "Collider.h"
#include "../../Actor/Actor.h"
#include "../../Scene/GamePlay.h"
#include "../../System/GameSystem.h"
#include "../../System/Physics.h"
#include "BoxComponent.h"
#include <vector>
#include <algorithm>

Collider::Collider(Actor* owner, bool isTrigger, int updateOrder) :
    Component(owner, updateOrder),
    mIsTrigger(isTrigger),
    mEnabled(true) {
}

void Collider::update(float deltaTime) {
}

bool Collider::getIsTrigger() const {
    return mIsTrigger;
}

void Collider::setIsTrigger(bool set) {
    mIsTrigger = set;
}

bool Collider::getEnable() const {
    return mEnabled;
}

void Collider::setEnable(bool set) {
    mEnabled = set;
}
