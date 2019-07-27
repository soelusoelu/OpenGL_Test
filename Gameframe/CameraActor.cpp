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

    static float bgColor[] = { 0.6f, 0.6f, 1.f, 1.f }; //背景色
    glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //画面クリア時のカラーの設定

    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 400.f - 50.f);
    glFogf(GL_FOG_END, 400.f);
    glFogfv(GL_FOG_COLOR, bgColor);
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
