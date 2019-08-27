#include "Pause.h"
#include "../Scene/GamePlay.h"
#include "../System/GameSystem.h"
#include "../Utility/Input.h"
#include "../System/Renderer.h"

Pause::Pause(std::shared_ptr<GameSystem> system, GamePlay* game) :
    UI(system),
    mGame(game) {
    mGame->setState(GamePlay::GameState::Paused);
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
    mSystem->getRenderer()->printf(300.f, 200.f, "Pause");
}
