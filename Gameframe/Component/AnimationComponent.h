#pragma once

#include "Component.h"
#include <string>

class Actor;

class AnimationComponent : public Component {
public:
    AnimationComponent(Actor* owner, const std::string& filename);
    virtual void update(float deltaTime) override;

private:
    unsigned mID;
    unsigned mAnimationNo;
    float mAnimationTimer;
};

