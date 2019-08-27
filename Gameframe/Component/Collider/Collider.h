#pragma once

#include "../Component.h"

class Actor;
class BoxComponent;

class Collider : public Component {
public:
    Collider(Actor* owner, bool isTrigger, int updateOrder = 100);
    virtual ~Collider() {};

    enum ColliderType {
        AABBT
    };

    virtual void update(float deltaTime) override;
    virtual ColliderType getColliderType() const = 0;

    bool getIsTrigger() const;
    void setIsTrigger(bool set);
    bool getEnable() const;
    void setEnable(bool set);

protected:
    bool mIsTrigger;
    bool mEnabled;
};
