#include "GameSystem.h"
#include "Renderer.h"
#include "StringRenderer.h"
#include "Physics.h"

GameSystem::GameSystem() :
    mRenderer(std::make_unique<Renderer>()),
    mStringRenderer(std::make_unique<StringRenderer>(mRenderer.get())),
    mPhysics(std::make_unique<Physics>()) {
}

Renderer* GameSystem::getRenderer() const {
    return mRenderer.get();
}

Physics* GameSystem::getPhysics() const {
    return mPhysics.get();
}

StringRenderer* GameSystem::getStringRenderer() const {
    return mStringRenderer.get();
}
