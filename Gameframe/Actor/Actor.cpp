#include "Actor.h"
#include "../Scene/GamePlay.h"
#include "../Component/Component.h"
#include "../Component/TransformComponent.h"
#include <gslib.h>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

Actor::Actor(GamePlay& game) :
    mGame(game),
    mState(State::Active),
    mTransform(new TransformComponent(*this)) {
    mGame.addActor(this);
}

Actor::~Actor() {
    mGame.removeActor(this);

    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void Actor::start() {
    for (auto comp : mStartComponents) {
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

void Actor::update(float deltaTime) {
    start();
    if (mState == State::Active) {
        updateComponents(deltaTime);
        updateActor(deltaTime);

        computeWorldTransform();
    }
}

void Actor::updateComponents(float deltaTime) {
    for (auto comp : mComponents) {
        comp->update(deltaTime);
    }
}

void Actor::addComponent(Component* component) {
    mStartComponents.emplace(component);
}

void Actor::removeComponent(Component* component) {
    auto itr = std::find(mComponents.begin(), mComponents.end(), component);
    if (itr != mComponents.end()) {
        mComponents.erase(itr);
    }
}

void Actor::computeWorldTransform() { //C³•K—v‚©‚à
    if (mTransform->getRecomputeTransform()) {
        mTransform->setRecomputeTransform(false);

        //glPushMatrix();
        //glTranslatef(mTransform->getPosition().x, mTransform->getPosition().y, mTransform->getPosition().z);
        //glRotatef(mTransform->getRotation(), 0.f, 1.f, 0.f);
        //glScalef(mTransform->getScale().x, mTransform->getScale().y, mTransform->getScale().z);

        //drawActor();

        //glPopMatrix();

        for (auto comp : mComponents) {
            comp->onUpdateWorldTransform();
        }
    }
}

void Actor::destroy(Actor* actor) {
    actor->mState = Actor::State::Dead;
}

TransformComponent& Actor::getTransform() const {
    return *mTransform;
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

const std::vector<Component*>& Actor::getAllComponents() const {
    return mComponents;
}
