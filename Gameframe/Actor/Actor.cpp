#include "Actor.h"
#include "ActorManager.h"
#include "ComponentManagementOfActor.h"
#include "../Component/TransformComponent.h"

Actor::Actor(const char* tag) :
    mComponentManager(std::make_shared<ComponentManagementOfActor>()),
    mState(State::Active),
    mTransform(new TransformComponent(this)),
    mTag(tag) {
    Singleton<ActorManager>::instance().addActor(this);
}

void Actor::update(float deltaTime) {
    mComponentManager->start();
    if (mState == State::Active) {
        mComponentManager->update(deltaTime);
        updateActor(deltaTime);

        computeWorldTransform();
    }
}

void Actor::computeWorldTransform() {
    if (mTransform->getRecomputeTransform()) {
        mTransform->setRecomputeTransform(false);

        mWorldTransform = Matrix4::createScale(mTransform->getScale());
        mWorldTransform *= Matrix4::createFromQuaternion(mTransform->getRotation());
        mWorldTransform *= Matrix4::createTranslation(mTransform->getPosition());

        for (auto&& comp : mComponentManager->getAllComponents()) {
            comp->onUpdateWorldTransform();
        }
    }
}

void Actor::destroy(Actor* actor) {
    actor->mState = Actor::State::Dead;
}

void Actor::destroy(std::shared_ptr<Actor> actor) {
    actor->mState = Actor::State::Dead;
}

std::shared_ptr<ComponentManagementOfActor> Actor::getComponentManager() const {
    return mComponentManager;
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

const char* Actor::getTag() const {
    return mTag;
}
