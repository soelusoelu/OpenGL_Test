#include "Sprite2D.h"
#include "SkyBox.h"
#include "Octree.h"
#include "Light.h"
#include "StringRenderer.h"
#include "BGM.h"
#include "SE.h"
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
        //mMap = std::make_unique<Octree>(0, "./res/map.oct");
        //mWall = std::make_unique<Octree>(1, "./res/wall.oct");

        Light::update();
        StringRenderer::loadFontTexture(1, "./res/font.bmp");
	}

	void update(float deltaTime) {
        mGame->update(deltaTime);

        //mSkyBox->update(deltaTime);
        //mWall->intersectWall(mPlayer.get());
        //mMap->intersectGround(mPlayer.get());
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
    //std::unique_ptr<Octree> mMap;
    //std::unique_ptr<Octree> mWall;

    Scene mScene;
    std::unique_ptr<GamePlay> mGame;
};

int main() {
	return MyGame().run();
}
