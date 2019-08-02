#pragma once

#include "Component.h"
#include <gslib.h>

class Actor;

class TransformComponent : public Component {
public:
    TransformComponent(Actor& owner, int updateOrder = 100);
    ~TransformComponent();
    virtual void start() override;
    virtual void update(float deltaTime) override;

    const GSvector3& getPosition() const;
    void setPosition(const GSvector3& pos);
    void translete(const GSvector3& translation);
    const GSvector3& getRotation() const;
    void setRotation(const GSvector3& angle);
    void setRotation(float angleX, float angleY, float angleZ);
    void rotate(float angle, const GSvector3& axis);
    const GSvector3& getScale() const;
    void setScale(const GSvector3& scale);
    bool getRecomputeTransform() const;
    void setRecomputeTransform(bool set);

private:
    GSvector3 mPosition;
    GSvector3 mRotation;
    GSvector3 mScale;
    bool mRecomputeTransform;
};

