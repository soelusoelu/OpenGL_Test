#include "SkeletonComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../Scene/GamePlay.h"
#include "../Renderer.h"
#include <gslib.h>

SkeletonComponent::SkeletonComponent(Actor& owner, const std::string& filename) :
    Component(owner) {
    mID = getOwner().getGame().getRenderer().getSkeleton(filename);
    gsBindSkeleton(mID);
}

void SkeletonComponent::start() {
}

void SkeletonComponent::update(float deltaTime) {
}
