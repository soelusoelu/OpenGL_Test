#include "UIManager.h"

void UIManager::pushUI(UI* ui) {
    mUIStack.emplace_back(ui);
}

void UIManager::update(float deltaTime) {
    for (auto&& ui : mUIStack) {
        if (ui->getState() == UI::State::Active) {
            ui->update(deltaTime);
        }
    }

    removeClosingUI();
}

void UIManager::draw() const {
    for (const auto& ui : mUIStack) {
        ui->draw();
    }
}

void UIManager::clear() {
    mUIStack.clear();
}

const std::list<std::unique_ptr<UI>>& UIManager::getUIStack() const {
    return mUIStack;
}

void UIManager::removeClosingUI() {
    auto itr = mUIStack.begin();
    while (itr != mUIStack.end()) {
        if ((*itr)->getState() == UI::State::Closing) {
            itr = mUIStack.erase(itr);
        } else {
            ++itr;
        }
    }
}
