#pragma once

#include <memory>

class Renderer;
class StringRenderer;
class Physics;

class GameSystem {
public:
    GameSystem();
    Renderer* getRenderer() const;
    Physics* getPhysics() const;
    StringRenderer* getStringRenderer() const;

private:
    std::unique_ptr<Renderer> mRenderer;
    std::unique_ptr<StringRenderer> mStringRenderer;
    std::unique_ptr<Physics> mPhysics;
};

