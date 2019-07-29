#pragma once

#include "Component.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

class Actor;

class MeshComponent : public Component {
public:
    MeshComponent(Actor& owner, const std::string& filename);
    virtual void update(float deltaTime) override;
    void draw() const;

private:
    unsigned int mID;
};

