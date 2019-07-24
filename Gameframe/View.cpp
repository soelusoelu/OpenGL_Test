#include "View.h"

void View::myLookAt(
    GSmatrix4* pM,
    float eyeX, float eyeY, float eyeZ,
    float atX, float atY, float atZ,
    float upX, float upY, float upZ) {
    GSvector3 eye(eyeX, eyeY, eyeZ);
    GSvector3 at(atX, atY, atZ);
    GSvector3 up(upX, upY, upZ);

    //z方向のベクトルを求める
    GSvector3 e = eye - at;
    e.normalize();

    //x方向のベクトルを求める
    GSvector3 v = up.cross(e);
    v.normalize();

    //y方向のベクトルを求める
    GSvector3 u = e.cross(v);

    //行列にベクトルを設定する
    pM->m[0][0] = v.x;
    pM->m[0][1] = u.x;
    pM->m[0][2] = e.x;
    pM->m[0][3] = 0.f;

    pM->m[1][0] = v.y;
    pM->m[1][1] = u.y;
    pM->m[1][2] = e.y;
    pM->m[1][3] = 0.f;

    pM->m[2][0] = v.z;
    pM->m[2][1] = u.z;
    pM->m[2][2] = e.z;
    pM->m[2][3] = 0.f;

    //視点の位置を設定する
    pM->m[3][0] = -eye.dot(v);
    pM->m[3][1] = -eye.dot(u);
    pM->m[3][2] = -eye.dot(e);
    pM->m[3][3] = 1.f;
}

void View::myPerspective(GSmatrix4* pM, float fov, float aspect, float zNear, float zFar) {
    GSfloat f = 1.f / gsTan(fov / 2.f);

    pM->m[0][0] = f / aspect;
    pM->m[0][1] = 0.f;
    pM->m[0][2] = 0.f;
    pM->m[0][3] = 0.f;

    pM->m[1][0] = 0.f;
    pM->m[1][1] = f;
    pM->m[1][2] = 0.f;
    pM->m[1][3] = 0.f;

    pM->m[2][0] = 0.f;
    pM->m[2][1] = 0.f;
    pM->m[2][2] = (zFar + zNear) / (zNear - zFar);
    pM->m[2][3] = -1.f;

    pM->m[3][0] = 0.f;
    pM->m[3][1] = 0.f;
    pM->m[3][2] = (2.f * zFar * zNear) / (zNear - zFar);
    pM->m[3][3] = 0.f;
}
