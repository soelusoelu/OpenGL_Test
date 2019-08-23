#include "Actor.h"
#include "ComponentManagementOfActor.h"
#include "../Component/TransformComponent.h"
#include "../Scene/IGameMediator.h"
#include "ActorManager.h"
#include <string>

Actor::Actor(IGameMediator* iGameMediator, const char* tag) :
    mComponentManager(new ComponentManagementOfActor()),
    mState(State::Active),
    mTransform(new TransformComponent(this)),
    mTag(tag),
    mIGameMediator(iGameMediator) {
    Singleton<ActorManager>::instance().addActor(this);
}

Actor::~Actor() {
    delete mComponentManager;
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

ComponentManagementOfActor* Actor::getComponentManager() const {
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

IGameMediator* Actor::getIGameMediator() const {
    return mIGameMediator;
}
