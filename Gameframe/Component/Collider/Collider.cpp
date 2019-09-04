#include "Collider.h"
#include <algorithm>
#include <vector>

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
