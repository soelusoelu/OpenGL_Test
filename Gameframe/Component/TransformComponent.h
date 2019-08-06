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

    //ˆÊ’uAˆÚ“®
    const Vector3& getPosition() const;
    void setPosition(const Vector3& pos);
    void translete(const Vector3& translation);

    //Šp“xA‰ñ“]
    const Quaternion& getRotation() const;
    void setRotation(const Quaternion& rot);
    void setRotation(const Vector3& axis, float angle);
    void rotate(const Vector3& euler); //‹““®‰ö‚µ‚¢
    void rotate(const Vector3& axis, float angle);
    void lookAt(const Vector3& target);

    //Šgk
    const Vector3& getScale() const;
    void setScale(const Vector3& scale);

    //Œü‚«
    const Vector3 forward() const;
    const Vector3 right() const;

    bool getRecomputeTransform() const;
    void setRecomputeTransform(bool set);

private:
    Vector3 mPosition;
    Quaternion mRotation;
    Vector3 mScale;
    bool mRecomputeTransform;
};

