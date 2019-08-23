#include "UI.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "UIManager.h"
#include <gslib.h>

UI::UI(GameSystem* system) :
    mSystem(system),
    mState(State::Active),
    mPosition(Vector2::zero),
    mRotation(0.f),
    mScale(Vector2::one),
    mColor(Color::white),
    mID(0) {
    Singleton<UIManager>::instance().pushUI(this);
}

void UI::setTexture(const std::string& filename) {
    mID = mSystem->getRenderer()->getTexture(filename);
    gsBindTexture(mID);
}

void UI::drawTexture() {
    //各種レンダリングモードの退避
    //glPushAttrib(GL_ENABLE_BIT);

    ////ライティングを無効
    //glDisable(GL_LIGHTING);

    ////zバッファを無効
    //glDisable(GL_DEPTH_TEST);

    ////面カリングを無効
    //glDisable(GL_CULL_FACE);

    ////テクスチャをバインド
    //gsBindTexture(mID);

    ////透視変換行列の退避
    //glMatrixMode(GL_PROJECTION);
    //glPushMatrix();

    ////透視変換行列の設定
    //glLoadIdentity();
    //gluOrtho2D(0, 1280, 720, 0);

    ////モデルビュー変換行列の退避
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();

    ////変換行列の初期化
    //glLoadIdentity();

    ////平行移動量
    //glTranslatef(mPosition.x, mPosition.y, 0);

    ////回転角度
    //glRotatef(mRotation, 0.f, 0.f, 1.f);

    ////拡大縮小
    //glScalef(mScale.x * 100, mScale.y * 100, 1.f);

    ////テクスチャカラー
    //glColor4fv(reinterpret_cast<GLfloat*>(&mColor));

    ////四角形の描画
    //glBegin(GL_QUADS);
    ////法線ベクトル
    //glNormal3f(0.f, 0.f, 1.f);
    //glTexCoord2f(mTexCoord.left, mTexCoord.top);
    //glVertex2f(mRect.left, mRect.top);
    //glTexCoord2f(mTexCoord.left, mTexCoord.bottom);
    //glVertex2f(mRect.left, mRect.bottom);
    //glTexCoord2f(mTexCoord.right, mTexCoord.bottom);
    //glVertex2f(mRect.right, mRect.bottom);
    //glTexCoord2f(mTexCoord.right, mTexCoord.top);
    //glVertex2f(mRect.right, mRect.top);
    //glEnd();

    ////モデルビュー変換行列を復帰
    //glPopMatrix();

    ////透視変換行列を復帰
    //glMatrixMode(GL_PROJECTION);
    //glPopMatrix();

    ////モデルビュー変換行列に設定
    //glMatrixMode(GL_MODELVIEW);

    ////レンダリングモードの復帰
    //glPopAttrib();
}

void UI::close() {
    mState = State::Closing;
}

UI::State UI::getState() const {
    return mState;
}
