#include "Camera.h"
#include "Player.h"
#include "View.h"
#include <gslib.h>
#include <iostream>

void Camera::update(const Player& player) const {
    GSvector3 eyeVec;
    player.vector3FromHorizontalDir(&eyeVec);

    GSvector3 cameraPos(
        player.getPosition().x - eyeVec.x * 30.f,
        player.getPosition().y + 8.f,
        player.getPosition().z - eyeVec.z * 30.f
    );
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(
    //    cameraPos.x, cameraPos.y, cameraPos.z, //�J�����ʒu
    //    player.getPosition().x, player.getPosition().y + 5.f, player.getPosition().z, //�����_
    //    0.f, 1.f, 0.f //�J�����p��
    //);

    GSmatrix4 v;
    View::myLookAt(
        &v,
        cameraPos.x, cameraPos.y, cameraPos.z, //�J�����ʒu
        player.getPosition().x, player.getPosition().y + 5.f, player.getPosition().z, //�����_
        0.f, 1.f, 0.f //�J�����p��
    );
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(reinterpret_cast<float*>(&v));
}

void Camera::create() {
    if (!mInstance) {
        mInstance = new Camera();

        GSmatrix4 p;
        View::myPerspective(
            &p,
            45.f,
            1280.f / 720.f,
            0.2f,
            1000.f
        );
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(reinterpret_cast<float*>(&p));
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