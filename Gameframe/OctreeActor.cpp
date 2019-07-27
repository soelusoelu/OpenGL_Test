#include "OctreeActor.h"
#include "Actor.h"
#include "PlayerActor.h"
#include "Scene/GamePlay.h"
#include <gslib.h>
#include <string>

OctreeActor::OctreeActor(GamePlay& game, unsigned int id, std::string filename, PlayerActor& player, OctreeActor::Type type) :
    Actor(game),
    mID(id),
    mType(type),
    mPlayer(player) {
    gsLoadOctree(mID, filename.c_str());
}

OctreeActor::~OctreeActor() {
    gsDeleteOctree(mID);
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
    gsDrawOctree(mID);
}

void OctreeActor::intersectGround() {
    //�n�ʂƂ̏Փ˔���
    GSvector3 ray(0.f, -1.f, 0.f);
    GSvector3 position = mPlayer.getPosition();
    if (gsOctreeCollisionRay(
        gsGetOctree(mID), //�I�N�c���[
        &mPlayer.getPosition(), //���C�̈ʒu
        &ray, //���C�̕���
        &position, //���C�Ƃ̌�_
        nullptr) //�Փ˂����ʂ̕��ʃp�����[�^
        ) {
        mPlayer.setPosition(position);
    }
}

void OctreeActor::intersectWall() {
    //�ǂƂ̏Փ˔���
    GSvector3 position = mPlayer.getPosition();
    gsOctreeCollisionSphere(
        gsGetOctree(mID), //�I�N�c���[
        &mPlayer.getPosition(), //���̂̈ʒu
        mPlayer.getRadius(), //���̂̔��a
        &position //�␳��̋��̂̈ʒu
    );
    mPlayer.setPosition(position);
}
