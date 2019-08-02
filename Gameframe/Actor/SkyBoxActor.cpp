#include "SkyBoxActor.h"
#include "Actor.h"
#include <gslib.h>

SkyBoxActor::SkyBoxActor(GamePlay* game, unsigned int meshID) :
    Actor(game),
    mMeshID(meshID),
    mViewRoll(0.f),
    mViewPitch(0.f),
    mViewYow(0.f) {
    gsLoadMesh(mMeshID, "./res/skybox.msh");
}

SkyBoxActor::~SkyBoxActor() {
    gsDeleteMesh(mMeshID);
}

void SkyBoxActor::updateActor(float deltaTime) {
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        mViewYow -= 1.f * deltaTime;
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        mViewYow += 1.f * deltaTime;
    }
}

void SkyBoxActor::drawActor() const {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(mViewRoll, 0.f, 0.f, 1.f); //z軸回転
    glRotatef(mViewPitch, 1.f, 0.f, 0.f); //x
    glRotatef(mViewYow, 0.f, 1.f, 0.f); //y

    //各種レンダリングモードの退避
    glPushAttrib(GL_ENABLE_BIT);

    //ライティングを無効
    glDisable(GL_LIGHTING);

    //zバッファを無効
    glDisable(GL_DEPTH_TEST);

    //面カリングを無効
    glDisable(GL_CULL_FACE);

    //フォグを無効
    glDisable(GL_FOG);

    //視野変換行列を退避
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //スカイボックス用の変換行列
    GLfloat matView[4][4];
    glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<GLfloat*>(matView));
    matView[3][0] = 0.f; //x 平行移動成分を無しに
    matView[3][1] = 0.f; //y
    matView[3][2] = 0.f; //z
    glLoadMatrixf(reinterpret_cast<GLfloat*>(matView));

    //スカイボックスを描画する
    gsDrawMesh(mMeshID);

    //視野変換行列を復帰
    glPopMatrix();

    //各種レンダリングモードの復帰
    glPopAttrib();
}
