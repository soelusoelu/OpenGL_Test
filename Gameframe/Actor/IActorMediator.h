#pragma once

class Actor;

class IActorMediator {
public:
    virtual ~IActorMediator() {};
    virtual void addActor(Actor* actor) = 0;
};

