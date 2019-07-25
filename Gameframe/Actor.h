#pragma once

#include <gslib.h>
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

    Actor(GamePlay* game);
    virtual ~Actor();
    void upadte(float deltaTime);
    void updateComponents(float deltaTime);
    virtual void updateActor(float deltaTime) = 0;
    void processInput(const GKEYCODE& key);
    virtual void actorInput(const GKEYCODE& key) = 0;
    void addComponent(Component* component);
    void removeComponent(Component* component);

    //ゲッター、セッター
    const GSvector3& getPosition() const;
    void setPosition(const GSvector3& pos);
    const float getRotation() const;
    GamePlay* getGame() const;
    const std::unordered_set<Component*>& getComponents() const;

private:
    std::unordered_set<Component*> mComponents;

protected:
    State mState;
    GSvector3 mPosition;
    float mRotation;
    GamePlay* mGame;
};

