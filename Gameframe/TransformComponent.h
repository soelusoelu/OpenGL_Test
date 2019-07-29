#pragma once

#include "Component.h"
#include <gslib.h>

class Actor;

class TransformComponent : public Component {
public:
    TransformComponent(Actor& owner, int updateOrder = 100);
    ~TransformComponent();
    virtual void update(float deltaTime) override;

    const GSvector3& getPosition() const;
    void setPosition(const GSvector3& pos);
    float getRotation() const;
    void setRotation(const float rotation);
    void rotate(float rotation);
    const GSvector3& getScale() const;
    void setScale(const GSvector3& scale);
    bool getRecomputeTransform() const;
    void setRecomputeTransform(bool set);

private:
    GSvector3 mPosition;
    float mRotation;
    GSvector3 mScale;
    bool mRecomputeTransform;
};

