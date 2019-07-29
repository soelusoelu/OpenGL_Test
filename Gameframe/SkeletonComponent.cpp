#include "SkeltonComponent.h"
#include "Component.h"
#include "IDManager.h"
#include "Actor.h"
#include "Scene/GamePlay.h"
#include "Renderer.h"
#include <gslib.h>

SkeltonComponent::SkeltonComponent(Actor& owner, const std::string& filename) :
    Component(owner) {
    mID = getOwner().getGame().getRenderer().getSkeleton(filename);
    gsBindSkeleton(mID);
}

void SkeltonComponent::update(float deltaTime) {
}
