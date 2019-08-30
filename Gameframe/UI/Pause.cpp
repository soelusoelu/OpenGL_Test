#include "Pause.h"
#include "../Scene/GamePlay.h"
#include "../System/Renderer.h"
#include "../Utility/Input.h"
#include "Texture.h"

Pause::Pause(std::shared_ptr<Renderer> renderer, GamePlay* game) :
    UI(renderer),
    mGame(game),
    mTexture(std::make_unique<Texture>(renderer)) {
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
    mRenderer->printf(300.f, 200.f, "Pause");
    mTexture->drawTexture();
}
