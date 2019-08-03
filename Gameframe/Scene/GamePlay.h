#pragma once

#include "SceneBase.h"
#include <unordered_set>
#include <memory>

class Actor;
class PlayerActor;
class SkyBoxActor;
class OctreeActor;
class CubeActor;
class Renderer;
class StringRenderer;

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

    void addActor(Actor* actor);
    void removeActor(Actor* actor);

    GameState getState() const;
    void setState(GameState state);
    const std::unordered_set<Actor*>& getActors() const;
    Renderer* getRenderer() const;

private:
    std::unordered_set<Actor*> mActors;
    std::unordered_set<Actor*> mPendingActors;
    bool mUpdatingActors;
    GameState mState;
    std::unique_ptr<Renderer> mRenderer;
    std::unique_ptr<StringRenderer> mStringRenderer;

    //全部生ポインタじゃないとエラー出る
    PlayerActor* mPlayer;
    OctreeActor* mGround;
    CubeActor* mCube;
};

