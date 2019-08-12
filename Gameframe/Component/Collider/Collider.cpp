#include "Collider.h"

Collider::Collider(Actor* owner) :
    Component(owner),
    mEnabled(true) {
}

Collider::~Collider() {
}

void Collider::start() {
}

void Collider::update(float deltaTime) {
}

bool Collider::getEnable() const {
    return mEnabled;
}

void Collider::setEnable(bool set) {
    mEnabled = set;
}
