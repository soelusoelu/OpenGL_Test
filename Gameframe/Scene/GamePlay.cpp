#include "GamePlay.h"
#include "..//Actor.h"
#include "..//PlayerActor.h"
#include "..//OctreeActor.h"
#include "..//CameraActor.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <unordered_set>

GamePlay::GamePlay() :
    mUpdatingActors(false),
    mState(GameState::Play),
    mPlayer(new PlayerActor(*this, 0)),
    mCamera(std::make_unique<CameraActor>(*this, *mPlayer)),
    mGround(std::make_unique<OctreeActor>(*this, 0, "./res/map.oct", *mPlayer)),
    mWall(std::make_unique<OctreeActor>(*this, 1, "./res/wall.oct", *mPlayer, OctreeActor::Type::Wall)) {
    std::cout << "Actor total count : " << std::to_string(mActors.size()) << std::endl;
}

GamePlay::~GamePlay() {
    mActors.clear();
    mPendingActors.clear();

    std::cout << "Actor total count : " << std::to_string(mActors.size()) << std::endl;
}

void GamePlay::update(float deltaTime) {
    if (mState == GameState::Play) {
        mUpdatingActors = true;
        for (auto actor : mActors) {
            actor->update(deltaTime);
        }
        mUpdatingActors = false;

        for (auto pending : mPendingActors) {
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
    }
}

void GamePlay::draw() const {
    for (auto actor : mActors) {
        actor->drawActor();
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
