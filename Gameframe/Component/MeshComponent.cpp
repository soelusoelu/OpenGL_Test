#include "MeshComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../Scene/IGameMediator.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include <string>

MeshComponent::MeshComponent(Actor* owner, const std::string& filename) :
    Component(owner),
    mEnabled(true) {
    mID = mOwner->getIGameMediator()->getSystem()->getRenderer()->getMesh(filename);
}

MeshComponent::~MeshComponent() {
}

void MeshComponent::update(float deltaTime) {
}

void MeshComponent::draw() const {
    if (mEnabled) {
        mOwner->getIGameMediator()->getSystem()->getRenderer()->drawMesh(mID);
    }
}

void MeshComponent::setEnable(bool set) {
    mEnabled = set;
}

bool MeshComponent::getEnable() const {
    return mEnabled;
}
