#include "Texture.h"
#include "../System/Renderer.h"
#include <GSgraphics.h>
#include <GLFW/glfw3.h>

Texture::Texture(std::shared_ptr<Renderer> renderer) :
    mTextureID(0),
    mPosition(Vector2::zero),
    mScale(Vector2::one),
    mRotation(0.f),
    mColor(ColorPalette::white, 1.f),
    mRect(-0.5f, -0.5f, 0.5f, 0.5f),
    mTextureCoord(0.f, 0.f, 1.f, 1.f),
    mRenderer(renderer) {
}

void Texture::setTexture(const std::string& filename) {
    mTextureID = mRenderer->getTexture(filename);
}

void Texture::setPosition(const Vector2& position) {
    mPosition = position;
}

void Texture::setScale(const Vector2& scale) {
    mScale = scale;
}

void Texture::setRotate(float rotation) {
    mRotation = rotation;
}

void Texture::setRect(const Rect& rect) {
    mRect = rect;
}

void Texture::setColor(float r, float g, float b, float a) {
    mColor = Color(r, g, b, a);
}

void Texture::setColor(const Vector3& color, float alpha) {
    setColor(color.x, color.y, color.z, alpha);
}

void Texture::setImageRect(const Rect& rect) {
    //テクスチャをバインド
    gsBindTexture(mTextureID);

    //バインド中のテクスチャの幅と高さを取得
    GLint width, height;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

    //テクスチャ座標の計算
    mTextureCoord.left = rect.left / width;
    mTextureCoord.top = rect.top / height;
    mTextureCoord.right = rect.right / width;
    mTextureCoord.bottom = rect.bottom / height;
}

void Texture::drawTexture() {
    //各種レンダリングモードの退避
    glPushAttrib(GL_ENABLE_BIT);

    //ライティングを無効
    glDisable(GL_LIGHTING);

    //zバッファを無効
    glDisable(GL_DEPTH_TEST);

    //面カリングを無効
    glDisable(GL_CULL_FACE);

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

    //平行移動量
    glTranslatef(mPosition.x, mPosition.y, 0);

    //回転角度
    glRotatef(mRotation, 0.f, 0.f, 1.f);

    //拡大縮小
    glScalef(mScale.x * 150, mScale.y * 150, 1.f);

    //テクスチャカラー
    glColor4fv(reinterpret_cast<GLfloat*>(&mColor));

    //四角形の描画
    glBegin(GL_QUADS);
    //法線ベクトル
    glNormal3f(0.f, 0.f, 1.f);
    glTexCoord2f(mTextureCoord.left, mTextureCoord.top);
    glVertex2f(mRect.left, mRect.top);
    glTexCoord2f(mTextureCoord.left, mTextureCoord.bottom);
    glVertex2f(mRect.left, mRect.bottom);
    glTexCoord2f(mTextureCoord.right, mTextureCoord.bottom);
    glVertex2f(mRect.right, mRect.bottom);
    glTexCoord2f(mTextureCoord.right, mTextureCoord.top);
    glVertex2f(mRect.right, mRect.top);
    glEnd();

    //モデルビュー変換行列を復帰
    glPopMatrix();

    //透視変換行列を復帰
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    //モデルビュー変換行列に設定
    glMatrixMode(GL_MODELVIEW);

    //レンダリングモードの復帰
    glPopAttrib();
}
