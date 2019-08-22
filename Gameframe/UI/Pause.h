#pragma once

#include "UI.h"

class GamePlay;
class GameSystem;
class InterfaceUI;

class Pause : public UI {
public:
    Pause(GamePlay* game, GameSystem* system, InterfaceUI* interfaceUI);
    ~Pause();
    virtual void update(float deltaTime) override;
    virtual void draw() const override;

private:
    GamePlay* mGame;
};

