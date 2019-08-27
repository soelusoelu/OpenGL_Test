#pragma once

#include "UI.h"

class GamePlay;
class GameSystem;

class Pause : public UI {
public:
    Pause(std::shared_ptr<GameSystem> system, GamePlay* game);
    ~Pause();
    virtual void update(float deltaTime) override;
    virtual void draw() const override;

private:
    GamePlay* mGame;
};

