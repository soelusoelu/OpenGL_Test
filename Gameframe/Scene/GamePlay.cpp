﻿#include "GamePlay.h"
#include "../Actor/ActorManager.h"
#include "../Actor/CubeActor.h"
#include "../Actor/PlayerActor.h"
#include "../Camera.h"
#include "../System/GameSystem.h"
#include "../UI/Pause.h"
#include "../UI/UIManager.h"
#include "../Utility/Input.h"

GamePlay::GamePlay() :
    SceneBase(),
    mState(GameState::Play) {
    Actor::instantiate<PlayerActor>();
    Actor::instantiate<CubeActor>();
}

GamePlay::~GamePlay() {
    Singleton<ActorManager>::instance().clear();
    Singleton<UIManager>::instance().clear();
    Singleton<GameSystem>::instance().clear();
}

void GamePlay::update(float deltaTime) {
    if (mState == GameState::Play) {
        Singleton<ActorManager>::instance().update(deltaTime);

        if (Input::getKeyDown(Input::KeyCode::Space)) {
            new Pause(this);
        }
    }

    //UIは最後に必ず
    Singleton<UIManager>::instance().update(deltaTime);
}

void GamePlay::draw() const {
    Singleton<ActorManager>::instance().draw();
    Singleton<UIManager>::instance().draw();
    Singleton<Camera>::instance().update(Singleton<ActorManager>::instance().getPlayer());
}

GamePlay::GameState GamePlay::getState() const {
    return mState;
}

void GamePlay::setState(GameState state) {
    mState = state;
}
