#pragma once

#include "Collider.h"
#include "../../Utility/Collision.h"

class Actor;

class BoxComponent : public Collider {
public:
    BoxComponent(Actor* owner);
    ~BoxComponent();
    virtual void onUpdateWorldTransform() override;
    virtual ColliderType getColliderType() const override;
    void setCollision(const AABB& model);
    const AABB& getCollision() const;
    void setShouldRotate(bool set);

private:
    AABB mCollision;
    bool mShouldRotate;
};