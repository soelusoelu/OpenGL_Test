#include "Actor.h"
#include "Scene/GamePlay.h"
#include "Component.h"
#include <gslib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

Actor::Actor(GamePlay& game) :
    mState(State::Active),
    mPosition(GSvector3(0.f, 0.f, 0.f)),
    mRotation(0.f),
    mScale(GSvector3(1.f, 1.f, 1.f)),
    mGame(game) {
    mGame.addActor(this);
}

Actor::~Actor() {
    mGame.removeActor(this);

    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void Actor::update(float deltaTime) {
    if (mState == State::Active) {
        updateComponents(deltaTime);
        updateActor(deltaTime);
    }
}

void Actor::updateComponents(float deltaTime) {
    for (auto comp : mComponents) {
        comp->update(deltaTime);
    }
}

void Actor::addComponent(Component* component) {
    int myOrder = component->getUpdateOrder();
    auto itr = mComponents.begin();
    for (; itr != mComponents.end(); ++itr) {
        if (myOrder < (*itr)->getUpdateOrder()) {
            break;
        }
    }
    mComponents.insert(itr, component);

    std::cout << "Component total count : " << std::to_string(mComponents.size()) << std::endl;
}

void Actor::removeComponent(Component* component) {
    auto itr = std::find(mComponents.begin(), mComponents.end(), component);
    if (itr != mComponents.end()) {
        mComponents.erase(itr);
    }

    std::cout << "Component total count : " << std::to_string(mComponents.size()) << std::endl;
}

const GSvector3& Actor::getPosition() const {
    return mPosition;
}

void Actor::setPosition(const GSvector3& pos) {
    mPosition = pos;
}

float Actor::getRotation() const {
    return mRotation;
}

void Actor::setRotation(const float rotation) {
    mRotation = rotation;
}

const GSvector3& Actor::getScale() const {
    return mScale;
}

void Actor::setScale(const GSvector3& scale) {
    mScale = scale;
}

Actor::State Actor::getState() const {
    return mState;
}

void Actor::setState(State state) {
    mState = state;
}

GamePlay& Actor::getGame() const {
    return mGame;
}

const std::vector<Component*>& Actor::getComponents() const {
    return mComponents;
}
