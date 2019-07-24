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
    //テクスチャをバインド
    gsBindTexture(mTextureID);

    //バインド中のテクスチャの幅と高さを取得
    GLint width, height;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

    //テクスチャ座標の計算
    mTexCoord.left = rect.left / width;
    mTexCoord.top = rect.top / height;
    mTexCoord.right = rect.right / width;
    mTexCoord.bottom = rect.bottom / height;
}

void Sprite3D::draw() {
    //各種レンダリングモードの退避
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

    //面カリングを無効
    glDisable(GL_CULL_FACE);

    //テクスチャをバインド
    gsBindTexture(mTextureID);

    //モデルビュー変換行列の退避
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //ビルボード処理用の変換行列を作成
    GSmatrix4 billboard;
    glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(&billboard));
    billboard.setPosition(GSvector3(0.f, 0.f, 0.f));
    billboard.transpose();

    //平行移動量
    glTranslatef(mPosition.x, mPosition.y, mPosition.z);

    //ビルボードの変換行列
    glMultMatrixf(reinterpret_cast<GLfloat*>(&billboard));

    //回転角度
    glRotatef(mRotate, 0.f, 0.f, 1.f);

    //拡大縮小
    glScalef(mScale.x, -mScale.y, 1.f);

    //テクスチャカラー
    glColor4fv(reinterpret_cast<GLfloat*>(&mColor));

    //四角形の描画
    glBegin(GL_QUADS);
    //法線ベクトル
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

    //モデルビュー変換行列を復帰
    glPopMatrix();

    //レンダリングモードの復帰
    glPopAttrib();
}
