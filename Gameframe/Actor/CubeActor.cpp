#include "CubeActor.h"
#include "../Component/TransformComponent.h"
#include "../Component/Collider/BoxComponent.h"
#include "../Utility/Math.h"
#include "../Scene/IGameMediator.h"
#include <GLFW/glfw3.h>

CubeActor::CubeActor(IGameMediator* iGameMediator) :
    Actor(iGameMediator),
    mBox(new BoxComponent(this)) {
    //glDisable(GL_CULL_FACE);
    //glDisable(GL_LIGHTING);
    getTransform()->setPosition(Vector3(0.f, 0.f, 30.f));
}

void CubeActor::updateActor(float deltaTime) {
    //getTransform()->rotate(Vector3::up, -10.f);
}

void CubeActor::drawActor() const {
    //�����̂̕`��
    glBegin(GL_QUADS);
    //���
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    //����
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    //�O��
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    //�w��
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    //������
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    //�E����
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();
}
