#include "MeshComponent.h"
#include "Component.h"
#include "IDManager.h"
#include "Actor.h"
#include "Scene/GamePlay.h"
#include "Renderer.h"
#include <gslib.h>
#include <string>
#include <unordered_set>

MeshComponent::MeshComponent(Actor& owner, const std::string& filename) :
    Component(owner) {
    mID = getOwner().getGame().getRenderer().getMesh(filename);
}

void MeshComponent::update(float deltaTime) {
}

void MeshComponent::draw() const {
    gsDrawMesh(mID);
}
