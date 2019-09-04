#include "SkeletonComponent.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include <GSgraphics.h>

SkeletonComponent::SkeletonComponent(Actor* owner, const std::string& filename) :
    Component(owner) {
    mID = Singleton<GameSystem>::instance().getRenderer()->getSkeleton(filename);
    gsBindSkeleton(mID);
}

void SkeletonComponent::update(float deltaTime) {
}
