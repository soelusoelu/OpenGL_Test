#include "GamePlay.h"
#include "../Actor/PlayerActor.h"
#include "../Actor/CubeActor.h"
#include "../Camera.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../UI/Pause.h"
#include "../Utility/Input.h"
#include "../UI/UIManager.h"
#include "../Actor/ActorManager.h"
#include <memory>

GamePlay::GamePlay() :
    SceneBase(),
    mActorManager(std::make_unique<ActorManager>()),
    mState(GameState::Play) {
    mPlayer = new PlayerActor(this, mActorManager.get());
    mCube = new CubeActor(this, mActorManager.get());
    Camera::create();
}

GamePlay::~GamePlay() {
    Camera::destroy();
}

void GamePlay::update(float deltaTime) {
    if (mState == GameState::Play) {
        mActorManager->update(deltaTime);

        if (Input::getKeyDown(Input::KeyCode::Space)) {
            new Pause(this, mSystem.get(), mUIManager.get());
        }
    }

    //UI‚ÍÅŒã
    mUIManager->update(deltaTime);
}

void GamePlay::draw() const {
    mActorManager->draw();
    mUIManager->draw();
    Camera::instance()->update(mActorManager->getPlayer());
}

GamePlay::GameState GamePlay::getState() const {
    return mState;
}

void GamePlay::setState(GameState state) {
    mState = state;
}
