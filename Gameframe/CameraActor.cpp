#include "CameraActor.h"
#include "Scene/GamePlay.h"
#include "PlayerActor.h"
#include <gslib.h>
#include <iostream>

CameraActor::CameraActor(GamePlay& game, PlayerActor& player) :
    Actor(game),
    mPlayer(player) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
        45.f, //����p
        1280.f / 720.f, //�A�X�y�N�g��
        0.2f, //�߃N���b�v
        1000.f //���N���b�v
    );
    // ���f���r���[���[�h�ɕύX
    //glMatrixMode(GL_MODELVIEW);
}

CameraActor::~CameraActor() {
    std::cout << "CameraActor destructor" << std::endl;
}

void CameraActor::updateActor(float deltaTime) {
    GSvector3 eyeVec;
    mPlayer.vector3FromHorizontalDir(&eyeVec);

    mPosition = GSvector3(
        mPlayer.getPosition().x - eyeVec.x * 30.f,
        mPlayer.getPosition().y + 8.f,
        mPlayer.getPosition().z - eyeVec.z * 30.f
    );
}

void CameraActor::drawActor() const {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        mPosition.x, mPosition.y, mPosition.z, //�J�����ʒu
        mPlayer.getPosition().x, mPlayer.getPosition().y + 5.f, mPlayer.getPosition().z, //�����_
        0.f, 1.f, 0.f //�J�����p��
    );
}
