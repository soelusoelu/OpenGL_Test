#pragma once

#include "../Component.h"

class Actor;

class Collider : public Component {
public:
    Collider(Actor* owner);

    enum ColliderType {
        AABBT
    };

    virtual ~Collider();
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual ColliderType getColliderType() const = 0;

    bool getEnable() const;
    void setEnable(bool set);

protected:
    bool mEnabled;
};
