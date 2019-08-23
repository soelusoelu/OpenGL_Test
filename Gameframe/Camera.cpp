#include "Camera.h"
#include "Actor/PlayerActor.h"
#include "Component/TransformComponent.h"
#include <gslib.h>

void Camera::update(PlayerActor* player) {
    if (player) {
        Vector3 eyeVec = player->getTransform()->forward();

        mCameraPosition = Vector3(
            player->getTransform()->getPosition().x - eyeVec.x * 50.f,
            player->getTransform()->getPosition().y + 8.f,
            player->getTransform()->getPosition().z - eyeVec.z * 50.f
        );
        mPlayerPosition = player->getTransform()->getPosition();
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        mCameraPosition.x, mCameraPosition.y, mCameraPosition.z, //カメラ位置
        mPlayerPosition.x, mPlayerPosition.y + 10.f, mPlayerPosition.z, //注視点
        0.f, 1.f, 0.f //カメラ姿勢
    );
}
