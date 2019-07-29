#include "Sprite2D.h"
#include "Light.h"
#include "StringRenderer.h"
#include "Scene/SceneBase.h"
#include "Scene/GamePlay.h"
#include "IDManager.h"
#include <GSgame.h>
#include <memory>

//���������[�N���o�p
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define new DEBUG_NEW
#endif // _DEBUG

// �X�L�j���O���b�V���V�F�[�_�[�e�X�g
class MyGame : public gslib::Game {
public:
    enum Scene {
        Title,
        Game,
        Ending
    };

private:
    void start() {
        float bgColor[] = { 0.6f, 0.6f, 1.f, 1.f }; //�w�i�F
        glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //��ʃN���A���̃J���[�̐ݒ�

        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogf(GL_FOG_START, 400.f - 50.f);
        glFogf(GL_FOG_END, 400.f);
        glFogfv(GL_FOG_COLOR, bgColor);

        mGame = std::make_unique<GamePlay>();

        Light::update();
    }

    void update(float deltaTime) {
        mGame->update(deltaTime);
    }

    void draw() {
        mGame->draw();
    }

    void end() {
        //���������[�N���o�֐�
        _CrtDumpMemoryLeaks();
    }

    //��΃X�}�[�g�|�C���^
    std::unique_ptr<GamePlay> mGame;
};

int main() {
    return MyGame().run();
}
