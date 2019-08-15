#include "Scene/SceneBase.h"
#include "Scene/GamePlay.h"
#include "System/GameSystem.h"
#include "Utility/Input.h"
#include <GSgame.h>
#include <memory>

//メモリリーク検出用
//#ifdef _DEBUG
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
//#define new DEBUG_NEW
//#endif // _DEBUG

// スキニングメッシュシェーダーテスト
class MyGame : public gslib::Game {
public:
    enum Scene {
        Title,
        Game,
        Ending
    };

private:
    void start() {
        float bgColor[] = { 0.6f, 0.6f, 1.f, 1.f }; //背景色
        glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //画面クリア時のカラーの設定

        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogf(GL_FOG_START, 400.f - 50.f);
        glFogf(GL_FOG_END, 400.f);
        glFogfv(GL_FOG_COLOR, bgColor);

        mSystem = new GameSystem();
        mScene = new GamePlay(mSystem);
    }

    void update(float deltaTime) {
        Input::update();
        mScene->update(deltaTime);
    }

    void draw() {
        mScene->draw();
    }

    void end() {
        delete mScene;
        delete mSystem;
        //メモリリーク検出関数
        //_CrtDumpMemoryLeaks();
    }

    GameSystem* mSystem;
    SceneBase* mScene;
};

int main() {
    return MyGame().run();
}
