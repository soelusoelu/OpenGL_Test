#pragma once

#include "Actor.h"

class PlayerActor;
class GamePlay;

class CameraActor : public Actor {
public:
    CameraActor(GamePlay& game, PlayerActor& player);
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;

private:
    PlayerActor& mPlayer;
};

