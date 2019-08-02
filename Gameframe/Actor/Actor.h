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
        Active, //アップデート○、描画○
        Paused, //アップデート×、描画○
        Dead //死ぬ
    };

    Actor(GamePlay* game);
    virtual ~Actor();

    //各コンポーネントのstartを一度だけ実行
    void start();
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
    //コンポーネントの取得
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

    //位置、角度、スケールに変更があった際に更新
    void computeWorldTransform();

    //アクター生成
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
    //アクター削除
    void destroy(Actor* actor);

    //ゲッター、セッター
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

