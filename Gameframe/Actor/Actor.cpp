#include "Actor.h"
#include "../Component/Component.h"
#include "../Component/TransformComponent.h"
#include "../Scene/IGameMediator.h"
#include "IActorMediator.h"
#include <string>
#include <algorithm>

Actor::Actor(IGameMediator* iGameMediator, IActorMediator* iActorMediator, const char* tag) :
    mState(State::Active),
    mTransform(new TransformComponent(this)),
    mTag(tag),
    mIGameMediator(iGameMediator),
    mIActorMediator(iActorMediator) {
    iActorMediator->addActor(this);
}

Actor::~Actor() {
    while (!mStartComponents.empty()) {
        delete* mStartComponents.begin();
    }
    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void Actor::start() {
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

void Actor::update(float deltaTime) {
    start();
    if (mState == State::Active) {
        updateComponents(deltaTime);
        updateActor(deltaTime);

        computeWorldTransform();
    }
}

void Actor::updateComponents(float deltaTime) {
    for (auto&& comp : mComponents) {
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

void Actor::computeWorldTransform() {
    if (mTransform->getRecomputeTransform()) {
        mTransform->setRecomputeTransform(false);

        mWorldTransform = Matrix4::createScale(mTransform->getScale());
        mWorldTransform *= Matrix4::createFromQuaternion(mTransform->getRotation());
        mWorldTransform *= Matrix4::createTranslation(mTransform->getPosition());

        for (auto&& comp : mComponents) {
            comp->onUpdateWorldTransform();
        }
    }
}

void Actor::destroy(Actor* actor) {
    actor->mState = Actor::State::Dead;
}

const Matrix4& Actor::GetWorldTransform() const {
    return mWorldTransform;
}

TransformComponent* Actor::getTransform() const {
    return mTransform;
}

Actor::State Actor::getState() const {
    return mState;
}

void Actor::setState(State state) {
    mState = state;
}

const std::vector<Component*>& Actor::getAllComponents() const {
    return mComponents;
}

const char* Actor::getTag() const {
    return mTag;
}

IGameMediator* Actor::getIGameMediator() const {
    return mIGameMediator;
}

IActorMediator* Actor::getIActorMediator() const {
    return mIActorMediator;
}
