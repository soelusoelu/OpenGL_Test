#pragma once

#include <gslib.h>
#include <vector>
#include <memory>

class Component;
class GamePlay;
class TransformComponent;

class Actor {
public:
    enum State {
        Active,
        Paused,
        Dead
    };

    Actor(GamePlay& game);
    virtual ~Actor();

    //���ׂĂ̍X�V
    void update(float deltaTime);
    //���L���邷�ׂẴR���|�[�l���g���X�V
    void updateComponents(float deltaTime);
    //�A�N�^�[�ŗL�̍X�V
    virtual void updateActor(float deltaTime) = 0;
    //�`��
    virtual void drawActor() const = 0;

    //�R���|�[�l���g�̒ǉ��E�폜
    void addComponent(Component* component);
    void removeComponent(Component* component);

    //�ʒu�A�p�x�A�X�P�[���ɕύX���������ۂɍX�V
    void computeWorldTransform();

    //�A�N�^�[����
    static void instantiate(Actor* actor, const GSvector3& position, float rotation);
    //�A�N�^�[�폜
    void destroy(Actor* actor);

    //�Q�b�^�[�A�Z�b�^�[
    TransformComponent& getTransform() const;
    State getState() const;
    void setState(State state);
    GamePlay& getGame() const;
    const std::vector<Component*>& getComponents() const;

private:
    GamePlay& mGame;
    std::vector<Component*> mComponents;
    State mState;
    TransformComponent* mTransform;
};

