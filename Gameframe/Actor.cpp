#include "Actor.h"
#include "Component.h"
#include "Scene/GamePlay.h"
#include <gslib.h>
#include <unordered_set>

Actor::Actor(GamePlay* game) :
    mState(State::Active),
    mPosition(GSvector3(0.f, 0.f, 0.f)),
    mRotation(0.f),
    mGame(game) {
}

Actor::~Actor() {
}

void Actor::upadte(float deltaTime) {
}

void Actor::updateComponents(float deltaTime) {
}

void Actor::processInput(const GKEYCODE& key) {
}

void Actor::addComponent(Component* component) {
}

void Actor::removeComponent(Component* component) {
}

const GSvector3& Actor::getPosition() const {
    return mPosition;
}

void Actor::setPosition(const GSvector3& pos) {
    mPosition = pos;
}

const float Actor::getRotation() const {
    return mRotation;
}

GamePlay* Actor::getGame() const {
    return mGame;
}

const std::unordered_set<Component*>& Actor::getComponents() const {
    return mComponents;
}
