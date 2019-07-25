#include "StringRenderer.h"
#include "Sprite3D.h"
#include <gslib.h>

void StringRenderer::loadFontTexture(unsigned int textureID, const char* filename) {
    mTextureID = textureID;
    gsLoadTexture(mTextureID, filename);
    gsTextureColorKeyMode(GS_TEXCOLOR_KEY_AUTO);
}

void StringRenderer::drawChar(float x, float y, char c) {
    if (c < ' ' || c > '~') { //�\���ł��镶���R�[�h�̃`�F�b�N
        return;
    }

    //�����R�[�h����e�N�X�`�����̍��W�ɕϊ�
    GSrect rSrcRect;
    rSrcRect.left = static_cast<float>((c - ' ') % mWordCount) * mWidth;
    rSrcRect.top = static_cast<float>((c - ' ') / mWordCount) * mWidth;
    rSrcRect.right = rSrcRect.left + mWidth;
    rSrcRect.bottom = rSrcRect.top + mHeight;

    //�\���ʒu��ݒ肷��
    GSvector2 vTranslate(x, y);

    //������`��
    gsDrawSprite2D(
        mTextureID,
        &vTranslate,
        &rSrcRect,
        &GSvector2(0.f, 0.f),
        &GScolor(1.f, 1.f, 1.f, 1.f),
        &GSvector2(1.f, 1.f),
        0.f);
}

void StringRenderer::drawString(float x, float y, const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        drawChar(x, y, str[i]);

        x += mWidth;
    }
}

void StringRenderer::printf(float x, float y, const char str[], ...) {
    //�ψ������X�g�̎擾
    va_list args;
    va_start(args, str);

    //�ϊ���̕�������쐬
    char buffer[256];
    vsprintf_s(buffer, str, args);

    //������̕`��
    drawString(x, y, buffer);

    //�ψ������X�g�̏I��
    va_end(args);
}

unsigned int StringRenderer::mTextureID;