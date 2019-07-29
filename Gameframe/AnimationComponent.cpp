#include "AnimationComponent.h"
#include "Component.h"
#include"IDManager.h"
#include "Actor.h"
#include "Scene/GamePlay.h"
#include "Renderer.h"
#include <gslib.h>

AnimationComponent::AnimationComponent(Actor& owner, const std::string& filename) :
    Component(owner),
    mAnimationNo(0),
    mAnimationTimer(0.f) {
    mID = getOwner().getGame().getRenderer().getAnimation(filename);
}

AnimationComponent::~AnimationComponent() {
}

void AnimationComponent::update(float deltaTime) {
    mAnimationTimer += 1.f * deltaTime;
    if (mAnimationTimer > 1000.f) {
        mAnimationTimer = 0.f;
    }

    gsBindAnimation(mID, mAnimationNo, mAnimationTimer);
}
