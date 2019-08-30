#pragma once

#include "UI.h"

class Renderer;
class GamePlay;
class Texture;

class Pause : public UI {
public:
    Pause(std::shared_ptr<Renderer> renderer, GamePlay* game);
    ~Pause();
    virtual void update(float deltaTime) override;
    virtual void draw() const override;

private:
    GamePlay* mGame;
    std::unique_ptr<Texture> mTexture;
};

