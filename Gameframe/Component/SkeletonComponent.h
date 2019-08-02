#pragma once

#include "Component.h"
#include <string>

class Actor;

class SkeletonComponent : public Component {
public:
    SkeletonComponent(Actor* owner, const std::string& filename);
    virtual void start() override;
    virtual void update(float deltaTime) override;

private:
    unsigned int mID;
};

