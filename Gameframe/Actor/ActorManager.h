#pragma once

#include "../Utility/Singleton.h"
#include <unordered_set>
#include <memory>

class Actor;
class PlayerActor;

class ActorManager {
    friend class Singleton<ActorManager>;
public:
    void update(float deltaTime);
    void draw() const;

    //アクター追加
    void addActor(Actor* actor);

    //所有アクターをすべて削除
    void clear();

    std::shared_ptr<PlayerActor> getPlayer() const;
    const std::unordered_set<std::shared_ptr<Actor>>& getActors() const;

private:
    ActorManager();
    ~ActorManager() {};
    //Dead状態のアクターを削除
    void removeDeadActor();

    std::unordered_set<std::shared_ptr<Actor>> mActors;
    std::unordered_set<std::shared_ptr<Actor>> mPendingActors;
    bool mUpdatingActors;
};

