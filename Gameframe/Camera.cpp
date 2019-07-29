#include "Camera.h"
#include "PlayerActor.h"
#include "View.h"
#include "TransformComponent.h"
#include <gslib.h>
#include <iostream>

void Camera::update(PlayerActor* player) {
    if (player != nullptr) {
        GSvector3 eyeVec;
        player->vector3FromHorizontalDir(&eyeVec);

        mCameraPosition = GSvector3(
            player->getTransform().getPosition().x - eyeVec.x * 30.f,
            player->getTransform().getPosition().y + 8.f,
            player->getTransform().getPosition().z - eyeVec.z * 30.f
        );
        mPlayerPosition = player->getTransform().getPosition();
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        mCameraPosition.x, mCameraPosition.y, mCameraPosition.z, //カメラ位置
        mPlayerPosition.x, mPlayerPosition.y + 5.f, mPlayerPosition.z, //注視点
        0.f, 1.f, 0.f //カメラ姿勢
    );
}

void Camera::create() {
    if (!mInstance) {
        mInstance = new Camera();

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(
            45.f, //視野角
            1280.f / 720.f, //アスペクト比
            0.2f, //近クリップ
            1000.f //遠クリップ
        );
    }
}

void Camera::destroy() {
    delete mInstance;
    mInstance = nullptr;
}

Camera& Camera::instance() {
    return *mInstance;
}

Camera* Camera::mInstance = nullptr;
GSvector3 Camera::mCameraPosition = GSvector3(0.f, 0.f, 0.f);
GSvector3 Camera::mPlayerPosition = GSvector3(0.f, 0.f, 0.f);
