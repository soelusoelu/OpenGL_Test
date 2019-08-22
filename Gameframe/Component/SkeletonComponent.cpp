#include "SkeletonComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../Scene/GamePlay.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include <GSgraphics.h>

SkeletonComponent::SkeletonComponent(Actor* owner, const std::string& filename) :
    Component(owner) {
    mID = getOwner()->getGamePlay()->getSystem()->getRenderer()->getSkeleton(filename);
    gsBindSkeleton(mID);
}

void SkeletonComponent::update(float deltaTime) {
}
