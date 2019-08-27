#include "SceneBase.h"

SceneBase::SceneBase() :
    mSystem(std::make_shared<GameSystem>()) {
}

std::shared_ptr<GameSystem> SceneBase::getSystem() const {
    return mSystem;
}
