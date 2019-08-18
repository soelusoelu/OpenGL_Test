#pragma once

#include <memory>

class Renderer;
class Physics;
class Random;

class GameSystem {
public:
    GameSystem();
    Renderer* getRenderer() const;
    Physics* getPhysics() const;
    Random* getRandom() const;

private:
    std::unique_ptr<Renderer> mRenderer;
    std::unique_ptr<Physics> mPhysics;
    std::unique_ptr<Random> mRandom;
};

