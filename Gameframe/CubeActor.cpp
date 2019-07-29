#include "CubeActor.h"
#include "Actor.h"
#include "TransformComponent.h"

CubeActor::CubeActor(GamePlay& game) :
    Actor(game) {
    getTransform().setPosition(GSvector3(0.f, 50.f, 0.f));
}

void CubeActor::updateActor(float deltaTime) {
    getTransform().rotate(1.f);
}

void CubeActor::drawActor() const {
    //�����̂̕`��
    //glBegin(GL_QUADS);
    ////���
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, 1.0f, 1.0f);
    ////����
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    ////�O��
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    ////�w��
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);
    ////������
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    ////�E����
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    //glEnd();
}
