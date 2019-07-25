#pragma once

#include "SceneBase.h"

class Actor;

class GamePlay : public SceneBase {
public:
    virtual void update(float deltaTime) override;
    void addActor(Actor* actor);
};

