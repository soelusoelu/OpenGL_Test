#include "Light.h"
#include <gslib.h>

void Light::update() {
    //ÉâÉCÉgÇÃê›íË
    glLightfv(GL_LIGHT0, GL_AMBIENT, mLightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mLightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mLightSpeclar);
    glLightfv(GL_LIGHT0, GL_POSITION, mLightPosition);
    glEnable(GL_LIGHT0);
}

const float Light::mLightAmbient[] = {
    1.f, 1.f, 1.f, 1.f
};

const float Light::mLightDiffuse[] = {
    1.f, 1.f, 1.f, 1.f
};

const float Light::mLightSpeclar[] = {
    0.2f, 0.2f, 0.2f, 1.f
};

const float Light::mLightPosition[] = {
    100.f, 100.f, 100.f, 0.f
};
