#include "SceneBase.h"

SceneBase::SceneBase() :
    mSystem(std::make_unique<GameSystem>()) {
}

GameSystem* SceneBase::getSystem() const {
    return mSystem.get();
}
