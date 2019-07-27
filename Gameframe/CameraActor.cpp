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
        45.f, //視野角
        1280.f / 720.f, //アスペクト比
        0.2f, //近クリップ
        1000.f //遠クリップ
    );
    // モデルビューモードに変更
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
        mPosition.x, mPosition.y, mPosition.z, //カメラ位置
        mPlayer.getPosition().x, mPlayer.getPosition().y + 5.f, mPlayer.getPosition().z, //注視点
        0.f, 1.f, 0.f //カメラ姿勢
    );
}
