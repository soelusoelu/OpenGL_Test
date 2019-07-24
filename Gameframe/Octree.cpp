#include "Octree.h"
#include "Player.h"
#include <gslib.h>
#include <iostream>

Octree::Octree(unsigned int octreeID, const char* filename) :
    Octree(octreeID, filename, GSvector3(0.f, 0.f, 0.f)) {
}

Octree::Octree(unsigned int octreeID, const char* filename, const GSvector3& position) :
    mOctreeID(octreeID),
    mFilename(filename),
    mSpherePosition(position) {
    gsLoadOctree(mOctreeID, mFilename);

    static float bgColor[] = { 0.6f, 0.6f, 1.f, 1.f }; //背景色
    glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //画面クリア時のカラーの設定

    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 400.f - 50.f);
    glFogf(GL_FOG_END, 400.f);
    glFogfv(GL_FOG_COLOR, bgColor);
}

Octree::~Octree() {
    gsDeleteOctree(mOctreeID);
    std::cout << "Octree destructor" << std::endl;
}

void Octree::intersectGround(Player* player) {
    //地面との衝突判定
    GSvector3 ray(0.f, -1.f, 0.f);
    GSvector3 intersectPos;
    if (gsOctreeCollisionRay(
        gsGetOctree(mOctreeID), //オクツリー
        &player->getPosition(), //レイの位置
        &ray, //レイの方向
        &intersectPos, //レイとの交点
        nullptr) //衝突した面の平面パラメータ
        ) {
        player->intersectShiftPosition(GSvector3(player->getPosition().x, intersectPos.y, player->getPosition().z));
    }
}

void Octree::intersectWall(Player* player) {
    //壁との衝突判定
    GSvector3 out;
    gsOctreeCollisionSphere(
        gsGetOctree(1), //オクツリー
        &player->getPosition(), //球体の位置
        player->getRadius(), //球体の半径
        //&out //補正後の球体の位置
        &player->getPosition()
    );
    //player->intersectShiftPosition(out);
}

void Octree::draw() const {
    gsDrawOctree(mOctreeID);
}

