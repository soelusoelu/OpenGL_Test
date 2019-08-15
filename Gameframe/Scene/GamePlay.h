#pragma once

#include "SceneBase.h"
#include <unordered_set>
#include <memory>

class GameSystem;
class Actor;
class PlayerActor;
class CubeActor;

class GamePlay : public SceneBase {
public:
    enum GameState {
        Play,
        Paused,
        Quit
    };

    GamePlay(GameSystem* gameSystem);
    ~GamePlay();

    virtual void update(float deltaTime) override;
    virtual void draw() const override;

    void addActor(Actor* actor);
    void removeActor(Actor* actor);

    GameState getState() const;
    void setState(GameState state);
    const std::unordered_set<Actor*>& getActors() const;

private:
    std::unordered_set<Actor*> mActors;
    std::unordered_set<Actor*> mPendingActors;
    bool mUpdatingActors;
    GameState mState;

    //全部生ポインタじゃないとエラー出る
    PlayerActor* mPlayer;
    CubeActor* mCube;
};

