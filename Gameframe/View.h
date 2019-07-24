#pragma once

#include <gslib.h>

class View {
public:
    static void myLookAt(GSmatrix4* pM, //����ϊ��s��
        float eyeX, //���_��x���W
        float eyeY, //���_��y���W
        float eyeZ, //���_��z���W
        float atX, //�����_��x���W
        float atY, //�����_��y���W
        float atZ, //�����_��z���W
        float upX, //���_�̏㑤�̃x�N�g��x����
        float upY, //���_�̏㑤�̃x�N�g��y����
        float upZ  //���_�̏㑤�̃x�N�g��z����
    );
    static void myPerspective(
        GSmatrix4* pM, //�����ϊ��s��
        float fov, //����p
        float aspect, //�A�X�y�N�g��
        float zNear, //�߃N���b�v�ʂ܂ł̋���
        float zFar //���N���b�v�ʂ܂ł̋���
    );
};

