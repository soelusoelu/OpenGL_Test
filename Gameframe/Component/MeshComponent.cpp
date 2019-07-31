#include "MeshComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../Scene/GamePlay.h"
#include "../Renderer.h"
#include <gslib.h>
#include <string>

MeshComponent::MeshComponent(Actor& owner, const std::string& filename) :
    Component(owner),
    mEnabled(true) {
    mID = getOwner().getGame().getRenderer().getMesh(filename);
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
