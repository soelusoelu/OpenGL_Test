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
    //óßï˚ëÃÇÃï`é 
    //glBegin(GL_QUADS);
    ////è„ñ 
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, 1.0f, 1.0f);
    ////â∫ñ 
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    ////ëOñ 
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    ////îwñ 
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);
    ////ç∂ë§ñ 
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    ////âEë§ñ 
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    //glEnd();
}
