#pragma once

class GameSystem;

class SceneBase {
public:
    SceneBase(GameSystem* gameSystem);
    virtual ~SceneBase();
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    GameSystem* getSystem() const;

private:
    GameSystem* mGameSystem;
};
