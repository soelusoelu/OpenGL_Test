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
        //�Փ˂����_
        Vector3 mPoint;
        //�Փ˂����_�̖@��
        Vector3 mNormal;
        //���������R���|�[�l���g
        BoxComponent* mBox;
        //�R���|�[�l���g�����L����A�N�^�[
        Actor* mActor;
    };

    bool RayCast(const Ray& ray, CollisionInfo* outColl);

    //�{�b�N�X�R���|�[�l���g�̒ǉ��E�폜
    void AddBox(BoxComponent* box);
    void RemoveBox(BoxComponent* box);

private:
    GamePlay* mGame;
    std::unordered_set<BoxComponent*> mBoxes;
};
