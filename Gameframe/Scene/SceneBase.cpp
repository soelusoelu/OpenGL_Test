#include "SceneBase.h"

SceneBase::SceneBase() :
    mSystem(std::make_unique<GameSystem>()),
    mUIManager(std::make_unique<UIManager>()) {
}

GameSystem* SceneBase::getSystem() const {
    return mSystem.get();
}
