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

void Sprite2D::draw() {
    //各種レンダリングモードの退避
    glPushAttrib(GL_ENABLE_BIT);

    //ライティングを無効
    glDisable(GL_LIGHTING);

    //zバッファを無効
    glDisable(GL_DEPTH_TEST);

    //面カリングを無効
    glDisable(GL_CULL_FACE);

    //カレントカラーを取得する
    //glGetFloatv(GL_CURRENT_COLOR, reinterpret_cast<float*>(&mColor));

    //テクスチャをバインド
    gsBindTexture(mTextureID);

    //透視変換行列の退避
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    //透視変換行列の設定
    glLoadIdentity();
    gluOrtho2D(0, 1280, 720, 0);

    //モデルビュー変換行列の退避
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //変換行列の初期化
    glLoadIdentity();

    //ビルボード処理用の変換行列を作成
    //GSmatrix4 billboard;
    //glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(&billboard));
    //billboard.setPosition(GSvector3(0.f, 0.f, 0.f));
    //billboard.transpose();

    //平行移動量
    glTranslatef(mPosition.x, mPosition.y, 0);

    //ビルボードの変換行列
    //glMultMatrixf(reinterpret_cast<GLfloat*>(&billboard));

    //回転角度
    glRotatef(mRotate, 0.f, 0.f, 1.f);

    //拡大縮小
    glScalef(mScale.x * 100, mScale.y * 100, 1.f);

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

    //透視変換行列を復帰
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    //モデルビュー変換行列に設定
    glMatrixMode(GL_MODELVIEW);

    //カレントカラーを復帰する
    //glColor4fv(reinterpret_cast<float*>(&mColor));

    //レンダリングモードの復帰
    glPopAttrib();
}
