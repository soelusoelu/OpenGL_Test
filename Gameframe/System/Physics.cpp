#include "Physics.h"
#include "../Component/Collider/BoxComponent.h"
#include <unordered_set>

bool Physics::rayCast(const Ray& ray, CollisionInfo* outColl) {
    bool collided = false;
    //closestTは、無限大で初期化
    // intersection will always update closestT
    float closestT = Math::infinity;
    Vector3 norm;
    //すべてのボックスコンポーネントをテスト
    for (const auto& box : mBoxes) {
        float t;
        //レイがボックスと交差するか
        if (box->getEnable() && intersect(ray, box->getCollision(), &t, &norm)) {
            //前の交差より近いか
            if (t < closestT) {
                closestT = t;
                outColl->mPoint = ray.pointOnSegment(t);
                outColl->mNormal = norm;
                outColl->mBox = box;
                outColl->mActor = box->getOwner();
                collided = true;
            }
        }
    }
    return collided;
}

void Physics::addBox(BoxComponent* box) {
    mBoxes.emplace(box);
}

void Physics::removeBox(BoxComponent* box) {
    mBoxes.erase(box);
}
