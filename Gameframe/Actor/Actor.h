#pragma once

#include <gslib.h>
#include <unordered_set>
#include <vector>
#include <memory>

class Component;
class GamePlay;
class TransformComponent;

class Actor {
public:
    enum State {
        Active, //�A�b�v�f�[�g���A�`�恛
        Paused, //�A�b�v�f�[�g�~�A�`�恛
        Dead //����
    };

    Actor(GamePlay* game);
    virtual ~Actor();

    //�e�R���|�[�l���g��start����x�������s
    void start();
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
    //�R���|�[�l���g�̎擾
    template<typename T>
    T* getComponent() {
        T* comp = nullptr;
        for (auto&& c : mStartComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp != nullptr) {
                return comp;
            }
        }
        for (auto&& c : mComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp != nullptr) {
                break;
            }
        }
        return comp;
    }

    //�ʒu�A�p�x�A�X�P�[���ɕύX���������ۂɍX�V
    void computeWorldTransform();

    //�A�N�^�[����
    template<typename T>
    void instantiate() {
        T* t = new T(mGame);
    }
    template<typename T>
    void instantiate(const GSvector3& position, const GSvector3& rotation) {
        T* t = new T(mGame);
        t->mTransform->setPosition(position);
        t->mTransform->setRotation(rotation);
    }
    //�A�N�^�[�폜
    void destroy(Actor* actor);

    //�Q�b�^�[�A�Z�b�^�[
    TransformComponent* getTransform() const;
    State getState() const;
    void setState(State state);
    GamePlay* getGame() const;
    const std::vector<Component*>& getAllComponents() const;

private:
    GamePlay* mGame;
    std::unordered_set<Component*> mStartComponents;
    std::vector<Component*> mComponents;
    State mState;
    TransformComponent* mTransform;
};

