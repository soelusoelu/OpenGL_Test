#pragma once

#include "IGameMediator.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../System/Physics.h"
#include "../System/Random.h"
#include "../UI/UIManager.h"

class GameSystem;

class SceneBase : public IGameMediator {
public:
    SceneBase();
    virtual ~SceneBase() {};
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    virtual std::shared_ptr<GameSystem> getSystem() const override;

protected:
    std::shared_ptr<GameSystem> mSystem;
};
