#pragma once

#include "../Singleton.h"
#include <unordered_set>

class Actor;
class PlayerActor;
class IGameMediator;

class ActorManager {
    friend class Singleton<ActorManager>;
public:
    void update(float deltaTime);
    void draw() const;

    //アクター追加
    void addActor(Actor* actor);

    //所有アクターをすべて削除
    void clear();

    PlayerActor* getPlayer() const;
    const std::unordered_set<Actor*>& getActors() const;

private:
    ActorManager();
    ~ActorManager() {};
    //Dead状態のアクターを削除
    void removeDeadActor();

    std::unordered_set<Actor*> mActors;
    std::unordered_set<Actor*> mPendingActors;
    bool mUpdatingActors;
};

