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
    //地面との衝突判定
    GSvector3 ray(0.f, -1.f, 0.f);
    GSvector3 position = mPlayer.getPosition();
    if (gsOctreeCollisionRay(
        gsGetOctree(mID), //オクツリー
        &mPlayer.getPosition(), //レイの位置
        &ray, //レイの方向
        &position, //レイとの交点
        nullptr) //衝突した面の平面パラメータ
        ) {
        mPlayer.setPosition(position);
    }
}

void OctreeActor::intersectWall() {
    //壁との衝突判定
    GSvector3 position = mPlayer.getPosition();
    gsOctreeCollisionSphere(
        gsGetOctree(mID), //オクツリー
        &mPlayer.getPosition(), //球体の位置
        mPlayer.getRadius(), //球体の半径
        &position //補正後の球体の位置
    );
    mPlayer.setPosition(position);
}
