#include "Sprite2D.h"
#include <gslib.h>
#include <iostream>

Sprite2D::Sprite2D(unsigned int textureID, const char* filename) :
    mTextureID(textureID),
    mFilename(filename),
    mPosition(0.f, 0.f),
    mScale(1.f, 1.f),
    mRotate(0.f),
    mRect(-0.5f, -0.5f, 0.5f, 0.5f),
    mColor(1.f, 1.f, 1.f, 1.f),
    mTexCoord(0.f, 0.f, 1.f, 1.f) {
    gsLoadTexture(mTextureID, mFilename);
}

Sprite2D::~Sprite2D() {
    gsDeleteTexture(mTextureID);
    std::cout << "Sprite2D destructor" << std::endl;
}

void Sprite2D::setPosition(const GSvector2& position) {
    mPosition = position;
}

void Sprite2D::setScale(const GSvector2& scale) {
    mScale = scale;
}

void Sprite2D::setRotate(float rotate) {
    mRotate = rotate;
}

void Sprite2D::setRect(const GSrect& rect) {
    mRect = rect;
}

void Sprite2D::setColor(const GScolor4& color) {
    mColor = color;
}

void Sprite2D::setImageRect(const GSrect& rect) {
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

void Sprite2D::draw() {
    //�e�탌���_�����O���[�h�̑ޔ�
    glPushAttrib(GL_ENABLE_BIT);

    //���C�e�B���O�𖳌�
    glDisable(GL_LIGHTING);

    //z�o�b�t�@�𖳌�
    glDisable(GL_DEPTH_TEST);

    //�ʃJ�����O�𖳌�
    glDisable(GL_CULL_FACE);

    //�J�����g�J���[���擾����
    //glGetFloatv(GL_CURRENT_COLOR, reinterpret_cast<float*>(&mColor));

    //�e�N�X�`�����o�C���h
    gsBindTexture(mTextureID);

    //�����ϊ��s��̑ޔ�
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    //�����ϊ��s��̐ݒ�
    glLoadIdentity();
    gluOrtho2D(0, 1280, 720, 0);

    //���f���r���[�ϊ��s��̑ޔ�
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //�ϊ��s��̏�����
    glLoadIdentity();

    //�r���{�[�h�����p�̕ϊ��s����쐬
    //GSmatrix4 billboard;
    //glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(&billboard));
    //billboard.setPosition(GSvector3(0.f, 0.f, 0.f));
    //billboard.transpose();

    //���s�ړ���
    glTranslatef(mPosition.x, mPosition.y, 0);

    //�r���{�[�h�̕ϊ��s��
    //glMultMatrixf(reinterpret_cast<GLfloat*>(&billboard));

    //��]�p�x
    glRotatef(mRotate, 0.f, 0.f, 1.f);

    //�g��k��
    glScalef(mScale.x * 100, mScale.y * 100, 1.f);

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

    //�����ϊ��s��𕜋A
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    //���f���r���[�ϊ��s��ɐݒ�
    glMatrixMode(GL_MODELVIEW);

    //�J�����g�J���[�𕜋A����
    //glColor4fv(reinterpret_cast<float*>(&mColor));

    //�����_�����O���[�h�̕��A
    glPopAttrib();
}
