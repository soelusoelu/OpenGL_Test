#include "Player.h"
#include "Sprite2D.h"
#include "SkyBox.h"
#include "Octree.h"
#include "Camera.h"
#include "Light.h"
#include "StringRenderer.h"
#include "BGM.h"
#include "SE.h"
#include <GSgame.h>
#include <memory>

// スキニングメッシュシェーダーテスト
class MyGame : public gslib::Game {
private:
	void start() {
        mSprite = std::make_unique<Sprite2D>(0, "./res/kuppa.png");
        mSprite->setPosition(GSvector2(1200.f, 60.f));
        mPlayer = std::make_unique<Player>(0, "./res/character");
        mSkyBox = std::make_unique<SkyBox>(1, "./res/skybox.msh");
        mMap = std::make_unique<Octree>(0, "./res/map.oct");
        mWall = std::make_unique<Octree>(1, "./res/wall.oct");
        Camera::create();

        Light::update();
        StringRenderer::loadFontTexture(1, "./res/font.bmp");
        mBGM = std::make_unique<BGM>(0, "./res/bgm.mds");
        mSE = std::make_unique<SE>(0, "./res/se.wav", 5);
        mBGM->play();
        //mSE->play();
	}

	void update(float deltaTime) {
        mSkyBox->update(deltaTime);
        mPlayer->update(deltaTime);
        mWall->intersectWall(mPlayer.get());
        mMap->intersectGround(mPlayer.get());
	}

	void draw() {
        mSkyBox->draw();
        Camera::instance().update(*mPlayer);
        mMap->draw();
        mWall->draw();
        mPlayer->draw();
        mSprite->draw();
	}

	void end() {
        Camera::destroy();
	}

    std::unique_ptr<Player> mPlayer;
    std::unique_ptr<Sprite2D> mSprite;
    std::unique_ptr<SkyBox> mSkyBox;
    std::unique_ptr<Octree> mMap;
    std::unique_ptr<Octree> mWall;
    std::unique_ptr<BGM> mBGM;
    std::unique_ptr<SE> mSE;
};

int main() {
	return MyGame().run();
}
