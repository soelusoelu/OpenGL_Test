#pragma once

#include "Component.h"
#include <string>

class Actor;

class AnimationComponent : public Component {
public:
    AnimationComponent(Actor& owner, const std::string& filename);
    ~AnimationComponent();
    virtual void update(float deltaTime) override;

private:
    unsigned int mID;
    unsigned int mAnimationNo;
    float mAnimationTimer;
};

