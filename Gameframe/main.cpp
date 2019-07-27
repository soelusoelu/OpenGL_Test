#include "Sprite2D.h"
#include "SkyBox.h"
#include "Light.h"
#include "StringRenderer.h"
#include "Scene/SceneBase.h"
#include "Scene/GamePlay.h"
#include <GSgame.h>
#include <memory>

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
        mScene = Scene::Game;
        mGame = std::make_unique<GamePlay>();

        //mSprite = std::make_unique<Sprite2D>(0, "./res/kuppa.png");
        //mSprite->setPosition(GSvector2(1200.f, 60.f));
        //mSkyBox = std::make_unique<SkyBox>(1, "./res/skybox.msh");

        Light::update();
        StringRenderer::loadFontTexture(1, "./res/font.bmp");
	}

	void update(float deltaTime) {
        mGame->update(deltaTime);

        //mSkyBox->update(deltaTime);
	}

	void draw() {
        mGame->draw();

        //mSkyBox->draw();
        //mMap->draw();
        //mWall->draw();
        //mSprite->draw();
	}

	void end() {
	}

    //std::unique_ptr<Sprite2D> mSprite;
    //std::unique_ptr<SkyBox> mSkyBox;

    Scene mScene;
    std::unique_ptr<GamePlay> mGame;
};

int main() {
	return MyGame().run();
}
