#include "Component.h"
#include "../Actor/Actor.h"
#include <iostream>

Component::Component(Actor* owner, int updateOrder) :
    mOwner(owner),
    mUpdateOrder(updateOrder) {
    mOwner->addComponent(this);
}

Component::~Component() {
    mOwner->removeComponent(this);
}

void Component::start() {
}

void Component::onUpdateWorldTransform() {
}

int Component::getUpdateOrder() const {
    return mUpdateOrder;
}

Actor* Component::getOwner() const {
    return mOwner;
}
