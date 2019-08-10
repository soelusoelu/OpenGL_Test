#pragma once

#include "Component.h"
#include "../Collision.h"

class Actor;

class BoxComponent : public Component {
public:
    BoxComponent(Actor* owner);
    ~BoxComponent();
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onUpdateWorldTransform() override;
    void setCollision(const AABB& model);
    const AABB& getCollision() const;
    void setShouldRotate(bool set);

private:
    AABB mCollision;
    bool mShouldRotate;
};