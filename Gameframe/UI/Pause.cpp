#include "Pause.h"
#include "../Scene/GamePlay.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include "../Utility/Input.h"
#include "Texture.h"

Pause::Pause(GamePlay* game) :
    UI(),
    mGame(game),
    mTexture(std::make_unique<Texture>()) {
    mGame->setState(GamePlay::GameState::Paused);
    mTexture->setTexture("./res/kuppa.png");
    mTexture->setPosition(Vector2(100.f, 100.f));
}

Pause::~Pause() {
    mGame->setState(GamePlay::GameState::Play);
}

void Pause::update(float deltaTime) {
    if (Input::getKeyDown(Input::KeyCode::P)) {
        close();
    }
}

void Pause::draw() const {
    Singleton<GameSystem>::instance().getRenderer()->printf(300.f, 200.f, "Pause");
    mTexture->drawTexture();
}
