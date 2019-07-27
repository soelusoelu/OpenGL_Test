#pragma once

#include "SceneBase.h"
#include "..//PlayerActor.h"
#include <unordered_set>
#include <memory>

class Actor;
class Player;
class OctreeActor;
class CameraActor;

class GamePlay : public SceneBase {
public:
    enum GameState {
        Play,
        Paused,
        Quit
    };

    GamePlay();
    ~GamePlay();

    virtual void update(float deltaTime) override;
    void draw() const;

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

    //生き死にがある場合は生、ないならスマート
    PlayerActor* mPlayer;
    std::unique_ptr<OctreeActor> mGround;
    std::unique_ptr<OctreeActor> mWall;
    std::unique_ptr<CameraActor> mCamera;
};

