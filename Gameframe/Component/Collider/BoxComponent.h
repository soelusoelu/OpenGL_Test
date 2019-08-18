#pragma once

#include "Collider.h"
#include "../../Utility/Collision.h"
#include "../../Utility/Math.h"

class Actor;

class BoxComponent : public Collider {
public:
    BoxComponent(Actor* owner, bool isTrigger = false);
    ~BoxComponent();
    virtual void onUpdateWorldTransform() override;
    virtual ColliderType getColliderType() const override;
    void setCollision(const AABB& model);
    const AABB& getCollision() const;
    void setShouldRotate(bool set);

private:
    AABB mDefaultCollision;
    AABB mCollision;
    bool mShouldRotate;
};