#pragma once

#include "IActorMediator.h"
#include <unordered_set>

class Actor;
class PlayerActor;
class IGameMediator;

class ActorManager : public IActorMediator {
public:
    ActorManager();
    ~ActorManager();
    void update(float deltaTime);
    void draw() const;

    //アクター追加
    virtual void addActor(Actor* actor) override;

    PlayerActor* getPlayer() const;
    const std::unordered_set<Actor*>& getActors() const;

private:
    //Dead状態のアクターを削除
    void removeDeadActor();

    std::unordered_set<Actor*> mActors;
    std::unordered_set<Actor*> mPendingActors;
    bool mUpdatingActors;
};

