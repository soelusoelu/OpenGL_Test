#include "UI.h"
#include "../System/Renderer.h"
#include "UIManager.h"

UI::UI(std::shared_ptr<Renderer> renderer) :
    mRenderer(renderer),
    mState(State::Active) {
    Singleton<UIManager>::instance().pushUI(this);
}

void UI::close() {
    mState = State::Closing;
}

UI::State UI::getState() const {
    return mState;
}
