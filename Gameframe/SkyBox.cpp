#include "SkyBox.h"
#include "View.h"
#include <gslib.h>
#include <iostream>

SkyBox::SkyBox(unsigned int meshID, const char* filename) :
    mMeshID(meshID),
    mFilename(filename),
    mViewRoll(0.f),
    mViewPitch(0.f),
    mViewYow(0.f) {
    gsLoadMesh(mMeshID, mFilename);
}

SkyBox::~SkyBox() {
    gsDeleteMesh(mMeshID);
    std::cout << "SkyBox destructor" << std::endl;
}

void SkyBox::update(float deltaTime) {
    //if (gsGetKeyState(GKEY_Z)) {
    //    mViewRoll -= 1.f * deltaTime;
    //}
    //if (gsGetKeyState(GKEY_X)) {
    //    mViewRoll += 1.f * deltaTime;
    //}
    //if (gsGetKeyState(GKEY_UP)) {
    //    mViewPitch -= 1.f * deltaTime;
    //}
    //if (gsGetKeyState(GKEY_DOWN)) {
    //    mViewPitch += 1.f * deltaTime;
    //}
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        mViewYow -= 1.f * deltaTime;
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        mViewYow += 1.f * deltaTime;
    }
}

void SkyBox::draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(mViewRoll, 0.f, 0.f, 1.f); //z����]
    glRotatef(mViewPitch, 1.f, 0.f, 0.f); //x
    glRotatef(mViewYow, 0.f, 1.f, 0.f); //y

    //�e�탌���_�����O���[�h�̑ޔ�
    glPushAttrib(GL_ENABLE_BIT);

    //���C�e�B���O�𖳌�
    glDisable(GL_LIGHTING);

    //z�o�b�t�@�𖳌�
    glDisable(GL_DEPTH_TEST);

    //�ʃJ�����O�𖳌�
    glDisable(GL_CULL_FACE);

    //�t�H�O�𖳌�
    glDisable(GL_FOG);

    //����ϊ��s���ޔ�
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //�X�J�C�{�b�N�X�p�̕ϊ��s��
    GLfloat matView[4][4];
    glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(matView));
    matView[3][0] = 0.f; //x ���s�ړ������𖳂���
    matView[3][1] = 0.f; //y
    matView[3][2] = 0.f; //z
    glLoadMatrixf(reinterpret_cast<GLfloat*>(matView));

    //�X�J�C�{�b�N�X��`�悷��
    gsDrawMesh(mMeshID);

    //����ϊ��s��𕜋A
    glPopMatrix();

    //�e�탌���_�����O���[�h�̕��A
    glPopAttrib();
}
