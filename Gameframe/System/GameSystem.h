#pragma once

#include <memory>

class Renderer;
class Physics;
class Random;

class GameSystem {
public:
    GameSystem();
    std::shared_ptr<Renderer> getRenderer() const;
    std::shared_ptr<Physics> getPhysics() const;
    std::shared_ptr<Random> getRandom() const;

private:
    std::shared_ptr<Renderer> mRenderer;
    std::shared_ptr<Physics> mPhysics;
    std::shared_ptr<Random> mRandom;
};

