#include "Physics.h"
#include "Component/BoxComponent.h"

Physics::Physics(GamePlay* game) :
    mGame(game) {
}

bool Physics::RayCast(const Ray& ray, CollisionInfo* outColl) {
    bool collided = false;
    //closestT�́A������ŏ�����
    // intersection will always update closestT
    float closestT = Math::infinity;
    Vector3 norm;
    //���ׂẴ{�b�N�X�R���|�[�l���g���e�X�g
    for (const auto& box : mBoxes) {
        float t;
        //���C���{�b�N�X�ƌ������邩
        if (intersect(ray, box->getCollision(), &t, &norm)) {
            //�O�̌������߂���
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

void Physics::AddBox(BoxComponent* box) {
    mBoxes.emplace(box);
}

void Physics::RemoveBox(BoxComponent* box) {
    mBoxes.erase(box);
}
