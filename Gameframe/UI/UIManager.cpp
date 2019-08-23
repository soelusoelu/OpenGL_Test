﻿#include "UIManager.h"
#include "UI.h"

void UIManager::pushUI(UI* ui) {
    mUIStack.emplace(ui);
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
    auto itr = mUIStack.begin();
    while (itr != mUIStack.end()) {
        delete* itr;
        itr = mUIStack.erase(itr);
    }
}

const std::unordered_set<UI*>& UIManager::getUIStack() const {
    return mUIStack;
}

void UIManager::removeClosingUI() {
    auto itr = mUIStack.begin();
    while (itr != mUIStack.end()) {
        if ((*itr)->getState() == UI::State::Closing) {
            delete* itr;
            itr = mUIStack.erase(itr);
        } else {
            ++itr;
        }
    }
}
