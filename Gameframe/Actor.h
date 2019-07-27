#pragma once

#include <gslib.h>
#include <vector>
#include <unordered_set>

class Component;
class GamePlay;

class Actor {
public:
    enum State {
        Active,
        Paused,
        Dead
    };

    Actor(GamePlay& game);
    virtual ~Actor();

    void update(float deltaTime);
    void updateComponents(float deltaTime);
    virtual void updateActor(float deltaTime) = 0;
    virtual void drawActor() const = 0;
    void addComponent(Component* component);
    void removeComponent(Component* component);

    //ゲッター、セッター
    const GSvector3& getPosition() const;
    void setPosition(const GSvector3& pos);
    float getRotation() const;
    void setRotation(const float rotation);
    float getScale() const;
    void setScale(const float scale);
    State getState() const;
    void setState(State state);
    GamePlay& getGame() const;
    const std::vector<Component*>& getComponents() const;

private:
    std::vector<Component*> mComponents;

protected:
    State mState;
    GSvector3 mPosition;
    float mRotation;
    float mScale;
    GamePlay& mGame;
};

