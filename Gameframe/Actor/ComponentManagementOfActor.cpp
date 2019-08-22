#include "ComponentManagementOfActor.h"
#include "../Component/Component.h"
#include <algorithm>

ComponentManagementOfActor::ComponentManagementOfActor() {
}

ComponentManagementOfActor::~ComponentManagementOfActor() {
    auto itr = mStartComponents.begin();
    while (itr != mStartComponents.end()) {
        delete* itr;
    }
    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void ComponentManagementOfActor::start() {
    for (auto&& comp : mStartComponents) {
        comp->start();

        int myOrder = comp->getUpdateOrder();
        auto itr = mComponents.begin();
        for (; itr != mComponents.end(); ++itr) {
            if (myOrder < (*itr)->getUpdateOrder()) {
                break;
            }
        }
        mComponents.insert(itr, comp);
    }
    mStartComponents.clear();
}

void ComponentManagementOfActor::update(float deltaTime) {
    for (auto&& comp : mComponents) {
        comp->update(deltaTime);
    }
}

void ComponentManagementOfActor::addComponent(Component* component) {
    mStartComponents.emplace(component);
}

void ComponentManagementOfActor::removeComponent(Component* component) {
    auto itr = std::find(mComponents.begin(), mComponents.end(), component);
    if (itr != mComponents.end()) {
        mComponents.erase(itr);
    }
}

const std::vector<Component*>& ComponentManagementOfActor::getAllComponents() const {
    return mComponents;
}
