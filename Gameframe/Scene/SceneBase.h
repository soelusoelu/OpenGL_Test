#pragma once

#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../System/Physics.h"
#include "../System/Random.h"
#include "../UI/UIManager.h"
#include <memory>

class GameSystem;
class UIManager;

class SceneBase {
public:
    SceneBase();
    virtual ~SceneBase() {};
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    GameSystem* getSystem() const;

protected:
    std::unique_ptr<GameSystem> mSystem;
    std::unique_ptr<UIManager> mUIManager;
};
