#pragma once

#include "Actor.h"
#include <string>

class GamePlay;
class PlayerActor;

class OctreeActor : public Actor {
public:
    enum Type {
        Ground,
        Wall
    };

    OctreeActor(GamePlay& game, unsigned int id, std::string filename, PlayerActor& player, Type type = Type::Ground);
    ~OctreeActor();
    virtual void updateActor(float deltaTime) override;
    virtual void drawActor() const override;
    void intersectGround();
    void intersectWall();

private:
    unsigned int mID;
    Type mType;
    PlayerActor& mPlayer;
};

