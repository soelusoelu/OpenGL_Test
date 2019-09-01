#include "AnimationComponent.h"
#include "Component.h"
#include "../Actor/Actor.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../Utility/Singleton.h"
#include <GSgraphics.h>

AnimationComponent::AnimationComponent(Actor* owner, const std::string& filename) :
    Component(owner),
    mAnimationNo(0),
    mAnimationTimer(0.f) {
    mID = Singleton<GameSystem>::instance().getRenderer()->getAnimation(filename);
}

void AnimationComponent::update(float deltaTime) {
    mAnimationTimer += 1.5f * deltaTime;
    if (mAnimationTimer > 100.f) {
        mAnimationTimer = 0.f;
    }

    gsBindAnimation(mID, mAnimationNo, mAnimationTimer);
}
