#include "MeshComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../Scene/GamePlay.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include <GSgraphics.h>
#include <string>

MeshComponent::MeshComponent(Actor* owner, const std::string& filename) :
    Component(owner),
    mEnabled(true) {
    mID = getOwner()->getGamePlay()->getSystem()->getRenderer()->getMesh(filename);
}

MeshComponent::~MeshComponent() {
}

void MeshComponent::start() {
}

void MeshComponent::update(float deltaTime) {
}

void MeshComponent::draw() const {
    if (mEnabled) {
        gsDrawMesh(mID);
    }
}

void MeshComponent::setEnable(bool set) {
    mEnabled = set;
}

bool MeshComponent::getEnable() const {
    return mEnabled;
}
