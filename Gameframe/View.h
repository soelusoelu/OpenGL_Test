#pragma once

#include <gslib.h>

class View {
public:
    static void myLookAt(GSmatrix4* pM, //視野変換行列
        float eyeX, //視点のx座標
        float eyeY, //視点のy座標
        float eyeZ, //視点のz座標
        float atX, //注視点のx座標
        float atY, //注視点のy座標
        float atZ, //注視点のz座標
        float upX, //視点の上側のベクトルx成分
        float upY, //視点の上側のベクトルy成分
        float upZ  //視点の上側のベクトルz成分
    );
    static void myPerspective(
        GSmatrix4* pM, //透視変換行列
        float fov, //視野角
        float aspect, //アスペクト比
        float zNear, //近クリップ面までの距離
        float zFar //遠クリップ面までの距離
    );
};

