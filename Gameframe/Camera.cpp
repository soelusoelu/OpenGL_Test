#include "Camera.h"
#include "Actor/PlayerActor.h"
#include "Component/TransformComponent.h"
#include <gslib.h>

void Camera::update(PlayerActor* player) {
    //if (player != nullptr) {
    //    Vector3 eyeVec = player->vector3FromHorizontalDir();

    //    mCameraPosition = Vector3(
    //        player->getTransform()->getPosition().x - eyeVec.x * 30.f,
    //        player->getTransform()->getPosition().y + 8.f,
    //        player->getTransform()->getPosition().z - eyeVec.z * 30.f
    //    );
    //    mPlayerPosition = player->getTransform()->getPosition();
    //}
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(
    //    mCameraPosition.x, mCameraPosition.y, mCameraPosition.z, //カメラ位置
    //    mPlayerPosition.x, mPlayerPosition.y + 5.f, mPlayerPosition.z, //注視点
    //    0.f, 1.f, 0.f //カメラ姿勢
    //);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0.0f, 10.0f, -50.0f,
        0.0f, 5.0f, 0.0f,
        0.0f, 1.0f, 0.0f
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
            0.1f, //近クリップ
            1000.f //遠クリップ
        );
    }
}

void Camera::destroy() {
    delete mInstance;
    mInstance = nullptr;
}

Camera* Camera::instance() {
    return mInstance;
}

Camera* Camera::mInstance = nullptr;
Vector3 Camera::mCameraPosition = Vector3::zero;
Vector3 Camera::mPlayerPosition = Vector3::zero;
