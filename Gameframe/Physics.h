#pragma once

#include "Math.h"
#include "Collision.h"
#include <unordered_set>

class GamePlay;
class BoxComponent;
class Actor;

class Physics {
public:
    Physics(GamePlay* game);

    struct CollisionInfo {
        //衝突した点
        Vector3 mPoint;
        //衝突した点の法線
        Vector3 mNormal;
        //交差したコンポーネント
        BoxComponent* mBox;
        //コンポーネントを所有するアクター
        Actor* mActor;
    };

    bool RayCast(const Ray& ray, CollisionInfo* outColl);

    //ボックスコンポーネントの追加・削除
    void AddBox(BoxComponent* box);
    void RemoveBox(BoxComponent* box);

private:
    GamePlay* mGame;
    std::unordered_set<BoxComponent*> mBoxes;
};
