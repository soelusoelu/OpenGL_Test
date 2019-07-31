#include "OctreeActor.h"
#include "Actor.h"
#include "PlayerActor.h"
#include "../Component/TransformComponent.h"
#include "../Scene/GamePlay.h"
#include <gslib.h>
#include <string>

OctreeActor::OctreeActor(GamePlay& game, unsigned int octreeID, const std::string& filename, PlayerActor& player, OctreeActor::Type type) :
    Actor(game),
    mOctreeID(octreeID),
    mType(type),
    mPlayer(player) {
    gsLoadOctree(mOctreeID, filename.c_str());
}

OctreeActor::~OctreeActor() {
    gsDeleteOctree(mOctreeID);
}

void OctreeActor::updateActor(float deltaTime) {
    switch (mType) {
    case OctreeActor::Ground:
        intersectGround();
        break;
    case OctreeActor::Wall:
        intersectWall();
        break;
    }
}

void OctreeActor::drawActor() const {
    gsDrawOctree(mOctreeID);
}

void OctreeActor::intersectGround() {
    //�n�ʂƂ̏Փ˔���
    GSvector3 ray(0.f, -1.f, 0.f);
    GSvector3 position = mPlayer.getTransform().getPosition();
    if (gsOctreeCollisionRay(
        gsGetOctree(mOctreeID), //�I�N�c���[
        &mPlayer.getTransform().getPosition(), //���C�̈ʒu
        &ray, //���C�̕���
        &position, //���C�Ƃ̌�_
        nullptr) //�Փ˂����ʂ̕��ʃp�����[�^
        ) {
        mPlayer.getTransform().setPosition(position);
    }
}

void OctreeActor::intersectWall() {
    //�ǂƂ̏Փ˔���
    GSvector3 position = mPlayer.getTransform().getPosition();
    gsOctreeCollisionSphere(
        gsGetOctree(mOctreeID), //�I�N�c���[
        &mPlayer.getTransform().getPosition(), //���̂̈ʒu
        mPlayer.getRadius(), //���̂̔��a
        &position //�␳��̋��̂̈ʒu
    );
    mPlayer.getTransform().setPosition(position);
}
