#include "GamePlay.h"
#include "../Actor/Actor.h"
#include "../Actor/PlayerActor.h"
#include "../Actor/CubeActor.h"
#include "../Camera.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../UI/Pause.h"
#include "../Utility/Input.h"
#include "../UI/UIManager.h"
#include <vector>
#include <memory>

GamePlay::GamePlay() :
    SceneBase(),
    mUpdatingActors(false),
    mState(GameState::Play) {
    mPlayer = new PlayerActor(this);
    mCube = new CubeActor(this);
    Camera::create();
}

GamePlay::~GamePlay() {
    Camera::destroy();
    while (!mPendingActors.empty()) {
        delete* mPendingActors.begin();
    }
    while (!mActors.empty()) {
        delete* mActors.begin();
    }
}

void GamePlay::update(float deltaTime) {
    if (mState == GameState::Play) {
        //アクター関連
        mUpdatingActors = true;
        for (auto&& actor : mActors) {
            actor->update(deltaTime);
        }
        mUpdatingActors = false;

        for (auto&& pending : mPendingActors) {
            mActors.emplace(pending);
        }
        mPendingActors.clear();

        std::vector<Actor*> deadActors;
        for (const auto& actor : mActors) {
            if (actor->getState() == Actor::State::Dead) {
                deadActors.emplace_back(actor);
            }
        }
        for (auto&& actor : deadActors) {
            delete actor;
            actor = nullptr;
        }

        if (Input::getKeyDown(Input::KeyCode::Space)) {
            new Pause(this, mSystem.get(), mUIManager.get());
        }
    }

    //UI関連
    mUIManager->update(deltaTime);
}

void GamePlay::draw() const {
    for (const auto& actor : mActors) {
        glPushMatrix();

        glMultMatrixf(*actor->GetWorldTransform().mat);

        actor->drawActor();

        glPopMatrix();
    }
    mUIManager->draw();
    Camera::instance()->update(mPlayer);
}

void GamePlay::addActor(Actor* actor) {
    if (mUpdatingActors) {
        mPendingActors.emplace(actor);
    } else {
        mActors.emplace(actor);
    }
    actor->computeWorldTransform();
}

void GamePlay::removeActor(Actor* actor) {
    auto itr = mPendingActors.find(actor);
    if (itr != mPendingActors.end()) {
        mPendingActors.erase(actor);
    }

    itr = mActors.find(actor);
    if (itr != mActors.end()) {
        mActors.erase(actor);
    }
}

GamePlay::GameState GamePlay::getState() const {
    return mState;
}

void GamePlay::setState(GameState state) {
    mState = state;
}

const std::unordered_set<Actor*>& GamePlay::getActors() const {
    return mActors;
}
