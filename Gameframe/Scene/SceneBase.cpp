#include "SceneBase.h"

SceneBase::SceneBase(GameSystem* gameSystem) :
    mGameSystem(gameSystem) {
}

SceneBase::~SceneBase() {
}

GameSystem* SceneBase::getSystem() const {
    return mGameSystem;
}
