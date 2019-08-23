#pragma once

#include "SceneBase.h"
#include <unordered_set>
#include <memory>

class PlayerActor;
class CubeActor;

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
    virtual void draw() const override;

    GameState getState() const;
    void setState(GameState state);

private:
    GameState mState;

    PlayerActor* mPlayer;
    CubeActor* mCube;
};

