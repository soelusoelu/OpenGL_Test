#pragma once

#include "../Math.h"
#include "Component.h"

class Actor;

class TransformComponent : public Component {
public:
    TransformComponent(Actor* owner, int updateOrder = 100);
    ~TransformComponent();
    virtual void start() override;
    virtual void update(float deltaTime) override;

    const Vector3& getPosition() const;
    void setPosition(const Vector3& pos);
    void translete(const Vector3& translation);
    const Vector3& getRotation() const;
    void setRotation(const Vector3& angle);
    void setRotation(float angleX, float angleY, float angleZ);
    void rotate(float angle, const Vector3& axis);
    const Vector3& getScale() const;
    void setScale(const Vector3& scale);
    bool getRecomputeTransform() const;
    void setRecomputeTransform(bool set);

private:
    Vector3 mPosition;
    Vector3 mRotation;
    Vector3 mScale;
    bool mRecomputeTransform;
};

