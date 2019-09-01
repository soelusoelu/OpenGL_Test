#pragma once

#include "UI.h"
#include <memory>

class GamePlay;
class Texture;

class Pause : public UI {
public:
    Pause(GamePlay* game);
    ~Pause();
    virtual void update(float deltaTime) override;
    virtual void draw() const override;

private:
    GamePlay* mGame;
    std::unique_ptr<Texture> mTexture;
};
