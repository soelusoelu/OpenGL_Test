#include "GameSystem.h"
#include "Renderer.h"
#include "Physics.h"
#include "Random.h"

GameSystem::GameSystem() :
    mRenderer(std::make_unique<Renderer>()),
    mPhysics(std::make_unique<Physics>()),
    mRandom(std::make_unique<Random>()) {
}

Renderer* GameSystem::getRenderer() const {
    return mRenderer.get();
}

Physics* GameSystem::getPhysics() const {
    return mPhysics.get();
}

Random* GameSystem::getRandom() const {
    return mRandom.get();
}
