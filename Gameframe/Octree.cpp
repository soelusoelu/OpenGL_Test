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

    static float bgColor[] = { 0.6f, 0.6f, 1.f, 1.f }; //�w�i�F
    glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //��ʃN���A���̃J���[�̐ݒ�

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
    //�n�ʂƂ̏Փ˔���
    GSvector3 ray(0.f, -1.f, 0.f);
    GSvector3 intersectPos;
    if (gsOctreeCollisionRay(
        gsGetOctree(mOctreeID), //�I�N�c���[
        &player->getPosition(), //���C�̈ʒu
        &ray, //���C�̕���
        &intersectPos, //���C�Ƃ̌�_
        nullptr) //�Փ˂����ʂ̕��ʃp�����[�^
        ) {
        player->intersectShiftPosition(GSvector3(player->getPosition().x, intersectPos.y, player->getPosition().z));
    }
}

void Octree::intersectWall(Player* player) {
    //�ǂƂ̏Փ˔���
    GSvector3 out;
    gsOctreeCollisionSphere(
        gsGetOctree(1), //�I�N�c���[
        &player->getPosition(), //���̂̈ʒu
        player->getRadius(), //���̂̔��a
        //&out //�␳��̋��̂̈ʒu
        &player->getPosition()
    );
    //player->intersectShiftPosition(out);
}

void Octree::draw() const {
    gsDrawOctree(mOctreeID);
}

