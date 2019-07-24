#include "Sprite3D.h"
#include <gslib.h>
#include <iostream>

Sprite3D::Sprite3D(unsigned int textureID, const char* filename) :
    mTextureID(textureID),
    mFilename(filename),
    mPosition(0.f, 0.f, 0.f),
    mScale(1.f, 1.f),
    mRotate(0.f),
    mRect(-0.5f, -0.5f, 0.5f, 0.5f),
    mColor(1.f, 1.f, 1.f, 1.f),
    mTexCoord(0.f, 0.f, 1.f, 1.f) {
    gsLoadTexture(mTextureID, mFilename);
}

Sprite3D::~Sprite3D() {
    gsDeleteTexture(mTextureID);
    std::cout << "Sprite3D destructor" << std::endl;
}

void Sprite3D::setPosition(const GSvector3& position) {
    mPosition = position;
}

void Sprite3D::setScale(const GSvector2& scale) {
    mScale = scale;
}

void Sprite3D::setRotate(float rotate) {
    mRotate = rotate;
}

void Sprite3D::setRect(const GSrect& rect) {
    mRect = rect;
}

void Sprite3D::setColor(const GScolor4& color) {
    mColor = color;
}

void Sprite3D::setImageRect(const GSrect& rect) {
    //�e�N�X�`�����o�C���h
    gsBindTexture(mTextureID);

    //�o�C���h���̃e�N�X�`���̕��ƍ������擾
    GLint width, height;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

    //�e�N�X�`�����W�̌v�Z
    mTexCoord.left = rect.left / width;
    mTexCoord.top = rect.top / height;
    mTexCoord.right = rect.right / width;
    mTexCoord.bottom = rect.bottom / height;
}

void Sprite3D::draw() {
    //�e�탌���_�����O���[�h�̑ޔ�
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

    //�ʃJ�����O�𖳌�
    glDisable(GL_CULL_FACE);

    //�e�N�X�`�����o�C���h
    gsBindTexture(mTextureID);

    //���f���r���[�ϊ��s��̑ޔ�
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //�r���{�[�h�����p�̕ϊ��s����쐬
    GSmatrix4 billboard;
    glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(&billboard));
    billboard.setPosition(GSvector3(0.f, 0.f, 0.f));
    billboard.transpose();

    //���s�ړ���
    glTranslatef(mPosition.x, mPosition.y, mPosition.z);

    //�r���{�[�h�̕ϊ��s��
    glMultMatrixf(reinterpret_cast<GLfloat*>(&billboard));

    //��]�p�x
    glRotatef(mRotate, 0.f, 0.f, 1.f);

    //�g��k��
    glScalef(mScale.x, -mScale.y, 1.f);

    //�e�N�X�`���J���[
    glColor4fv(reinterpret_cast<GLfloat*>(&mColor));

    //�l�p�`�̕`��
    glBegin(GL_QUADS);
    //�@���x�N�g��
    glNormal3f(0.f, 0.f, 1.f);
    glTexCoord2f(mTexCoord.left, mTexCoord.top);
    glVertex2f(mRect.left, mRect.top);
    glTexCoord2f(mTexCoord.left, mTexCoord.bottom);
    glVertex2f(mRect.left, mRect.bottom);
    glTexCoord2f(mTexCoord.right, mTexCoord.bottom);
    glVertex2f(mRect.right, mRect.bottom);
    glTexCoord2f(mTexCoord.right, mTexCoord.top);
    glVertex2f(mRect.right, mRect.top);
    glEnd();

    //���f���r���[�ϊ��s��𕜋A
    glPopMatrix();

    //�����_�����O���[�h�̕��A
    glPopAttrib();
}
