﻿#include "UI.h"
#include "../System/GameSystem.h"
#include "UIManager.h"
#include "IUIMediator.h"

UI::UI(GameSystem* system, IUIMediator* interfaceUI) :
    mSystem(system),
    mState(State::Active) {
    interfaceUI->pushUI(this);
}

void UI::close() {
    mState = State::Closing;
}

UI::State UI::getState() const {
    return mState;
}
