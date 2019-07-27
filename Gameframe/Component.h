#pragma once

class Actor;

class Component {
public:
    Component(Actor& owner, int updateOrder = 100);
    virtual ~Component();
    virtual void update(float deltaTime) = 0;

    int getUpdateOrder() const;
    Actor& getOwner();

private:
    Actor& mOwner;
    int mUpdateOrder;
};

