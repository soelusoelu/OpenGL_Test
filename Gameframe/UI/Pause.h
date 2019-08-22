#pragma once

#include "UI.h"

class GamePlay;
class GameSystem;
class IUIMediator;

class Pause : public UI {
public:
    Pause(GamePlay* game, GameSystem* system, IUIMediator* interfaceUI);
    ~Pause();
    virtual void update(float deltaTime) override;
    virtual void draw() const override;

private:
    GamePlay* mGame;
};

