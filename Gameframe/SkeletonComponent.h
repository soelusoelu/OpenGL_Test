#pragma once

#include "Component.h"
#include <string>

class Actor;

class SkeltonComponent : public Component {
public:
    SkeltonComponent(Actor& owner, const std::string& filename);
    virtual void update(float deltaTime) override;

private:
    unsigned int mID;
};

