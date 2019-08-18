﻿#pragma once

#include "../Utility/Math.h"
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

    Actor(GamePlay* gamePlay, const char* tag = "");
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
    T* getComponent() const {
        T* comp = nullptr;
        for (const auto& c : mStartComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp) {
                return comp;
            }
        }
        for (const auto& c : mComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp) {
                break;
            }
        }
        //最後まで見つからなければnullptrを返す
        return comp;
    }

    //位置、角度、スケールに変更があった際に更新
    void computeWorldTransform();

    //アクター生成
    template<typename T>
    void instantiate() {
        T* t = new T(mGamePlay);
    }
    template<typename T>
    void instantiate(const Vector3& position, const Quaternion& rotation) {
        T* t = new T(mGamePlay);
        t->mTransform->setPosition(position);
        t->mTransform->setRotation(rotation);
    }
    //アクター削除
    void destroy(Actor* actor);

    //ゲッター、セッター
    const Matrix4& GetWorldTransform() const;
    TransformComponent* getTransform() const;
    State getState() const;
    void setState(State state);
    GamePlay* getGamePlay() const;
    const std::vector<Component*>& getAllComponents() const;
    const char* getTag() const;

private:
    GamePlay* mGamePlay;
    std::unordered_set<Component*> mStartComponents;
    std::vector<Component*> mComponents;
    State mState;
    Matrix4 mWorldTransform;
    TransformComponent* mTransform;
    const char* mTag;
};

