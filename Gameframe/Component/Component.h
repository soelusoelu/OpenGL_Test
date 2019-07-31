#pragma once

class Actor;

class Component {
public:
    Component(Actor& owner, int updateOrder = 100);
    virtual ~Component();
    virtual void start() = 0;
    virtual void update(float deltaTime) = 0;
    //オーナーのTransformが更新されたら
    virtual void onUpdateWorldTransform();

    int getUpdateOrder() const;
    Actor& getOwner();

private:
    Actor& mOwner;
    int mUpdateOrder;
};

