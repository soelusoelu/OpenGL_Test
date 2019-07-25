#pragma once

class Actor;

class Component {
public:
    Component(Actor* owner);

protected:
    Actor* mOwner;
    int mUpdateOrder;
};

