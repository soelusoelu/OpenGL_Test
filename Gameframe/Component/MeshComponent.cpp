#include "MeshComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../Utility/Singleton.h"
#include <GSgraphics.h>
#include <string>

MeshComponent::MeshComponent(Actor* owner, const std::string& filename) :
    Component(owner),
    mEnabled(true) {
    mID = Singleton<GameSystem>::instance().getRenderer()->getMesh(filename);
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
