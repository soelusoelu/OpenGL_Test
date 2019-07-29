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

    //すべての更新
    void update(float deltaTime);
    //所有するすべてのコンポーネントを更新
    void updateComponents(float deltaTime);
    //アクター固有の更新
    virtual void updateActor(float deltaTime) = 0;
    //描画
    virtual void drawActor() const = 0;

    //コンポーネントの追加・削除
    void addComponent(Component* component);
    void removeComponent(Component* component);

    //位置、角度、スケールに変更があった際に更新
    void computeWorldTransform();

    //アクター生成
    static void instantiate(Actor* actor, const GSvector3& position, float rotation);
    //アクター削除
    void destroy(Actor* actor);

    //ゲッター、セッター
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

