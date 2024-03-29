#pragma once

#include <memory>

class Actor;

class Component {
public:
    Component(Actor* owner, int updateOrder = 100);
    virtual ~Component() {};
    //getComponentはここでして
    virtual void start() {};
    virtual void update(float deltaTime) = 0;
    //オーナーのTransformが更新されたら
    virtual void onUpdateWorldTransform() {};

    int getUpdateOrder() const;
    Actor* getOwner() const;

protected:
    Actor* mOwner;
    int mUpdateOrder;
};

