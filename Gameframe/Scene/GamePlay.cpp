#include "GamePlay.h"
#include "../Actor/Actor.h"
#include "../Actor/PlayerActor.h"
#include "../Actor/OctreeActor.h"
#include "../Actor/SkyBoxActor.h"
#include "../Actor/CubeActor.h"
#include "../Camera.h"
#include "../Component/TransformComponent.h"
#include "..//Renderer.h"
#include "..//StringRenderer.h"
#include <gslib.h>
#include <vector>
#include <unordered_set>
#include <memory>
#include <iostream>
#include <string>

GamePlay::GamePlay() :
    mUpdatingActors(false),
    mState(GameState::Play),
    mRenderer(std::make_unique<Renderer>()),
    mStringRenderer(std::make_unique<StringRenderer>(mRenderer.get())) {
    mPlayer = new PlayerActor(*this);
    mGround = new OctreeActor(*this, 0, "./res/map.oct", *mPlayer, OctreeActor::Type::Ground);
    mCube = new CubeActor(*this);
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
        mUpdatingActors = true;
        for (auto actor : mActors) {
            actor->update(deltaTime);
        }
        mUpdatingActors = false;

        for (auto pending : mPendingActors) {
            //pending->computeWorldTransform();
            mActors.emplace(pending);
        }
        mPendingActors.clear();

        std::vector<Actor*> deadActors;
        for (auto actor : mActors) {
            if (actor->getState() == Actor::State::Dead) {
                deadActors.emplace_back(actor);
            }
        }
        for (auto actor : deadActors) {
            delete actor;
            actor = nullptr;
        }

        if (gsGetKeyTrigger(GKEY_SPACE)) {
            mState = GameState::Paused;
        }
    } else if (mState == GameState::Paused) {
        if (gsGetKeyTrigger(GKEY_SPACE)) {
            mState = GameState::Play;
        }
    }
}

void GamePlay::draw() const {
    for (auto actor : mActors) {
        glPushMatrix();
        glTranslatef(actor->getTransform().getPosition().x, actor->getTransform().getPosition().y, actor->getTransform().getPosition().z);
        glRotatef(actor->getTransform().getRotation(), 0.f, 1.f, 0.f);
        glScalef(actor->getTransform().getScale().x, actor->getTransform().getScale().y, actor->getTransform().getScale().z);

        actor->drawActor();

        glPopMatrix();
    }
    Camera::instance().update(mPlayer);

    if (mState == GameState::Paused) {
        mStringRenderer->printf(600.f, 300.f, "Pause");
    }
}

void GamePlay::addActor(Actor* actor) {
    if (mUpdatingActors) {
        mPendingActors.emplace(actor);
    } else {
        mActors.emplace(actor);
    }
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

Renderer& GamePlay::getRenderer() const {
    return *mRenderer;
}
