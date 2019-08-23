#pragma once

#include "../Singleton.h"
#include <unordered_set>

class UI;

class UIManager {
    friend Singleton<UIManager>;
public:
    void pushUI(UI* ui);
    void update(float deltaTime);
    void draw() const;
    void clear();
    const std::unordered_set<UI*>& getUIStack() const;

private:
    UIManager() {};
    ~UIManager() {};
    //Closing状態のUIを削除
    void removeClosingUI();

    std::unordered_set<UI*> mUIStack;
};

