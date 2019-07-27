#include "Component.h"
#include "Actor.h"
#include <iostream>

Component::Component(Actor& owner, int updateOrder) :
    mOwner(owner),
    mUpdateOrder(updateOrder) {
    mOwner.addComponent(this);
}

Component::~Component() {
    std::cout << "Component destructor" << std::endl;

    mOwner.removeComponent(this);
}

int Component::getUpdateOrder() const {
    return mUpdateOrder;
}

Actor& Component::getOwner() {
    return mOwner;
}
