#pragma once

#include "Component.h"
#include <string>

class Actor;
class MeshComponent;

class AnimationComponent : public Component {
public:
    AnimationComponent(Actor* owner, const std::string& filename);
    ~AnimationComponent();
    virtual void update(float deltaTime) override;

private:
    unsigned mID;
    unsigned mAnimationNo;
    float mAnimationTimer;
};

