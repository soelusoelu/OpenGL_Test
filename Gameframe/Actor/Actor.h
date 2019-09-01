#pragma once

#include "../Utility/Math.h"
#include <memory>

class ComponentManagementOfActor;
class TransformComponent;

class Actor {
public:
    enum State {
        Active, //アップデート○、描画○
        Paused, //アップデート×、描画○
        Dead //死ぬ
    };
    Actor(const char* tag = "");
    virtual ~Actor() {};

    //すべての更新
    void update(float deltaTime);
    //アクター固有の更新
    virtual void updateActor(float deltaTime) = 0;
    //描画
    virtual void drawActor() const = 0;

    //位置、角度、スケールに変更があった際に更新
    void computeWorldTransform();

    //アクター生成
    //template<typename T>
    //static void instantiate(const char* tag = "") {
    //    T* t = new T(mMediator, tag);
    //}
    //template<typename T>
    //static void instantiate(const char* tag, const Vector3& position, const Quaternion& rotation) {
    //    T* t = new T(mMediator, tag);
    //    t->mTransform->setPosition(position);
    //    t->mTransform->setRotation(rotation);
    //}
    //アクター削除
    static void destroy(Actor* actor);
    static void destroy(std::shared_ptr<Actor> actor);

    //ゲッター、セッター
    std::shared_ptr<ComponentManagementOfActor> getComponentManager() const;
    const Matrix4& GetWorldTransform() const;
    TransformComponent* getTransform() const;
    State getState() const;
    void setState(State state);
    const char* getTag() const;

private:
    std::shared_ptr<ComponentManagementOfActor> mComponentManager;
    State mState;
    Matrix4 mWorldTransform;
    TransformComponent* mTransform;
    const char* mTag;
};

