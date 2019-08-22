#pragma once

#include "IUIMediator.h"
#include <unordered_set>

class UI;

class UIManager : public IUIMediator {
public:
    ~UIManager();
    virtual void pushUI(UI* ui) override;
    void update(float deltaTime);
    void draw() const;
    const std::unordered_set<UI*>& getUIStack() const;

private:
    //Closing状態のUIを削除
    void removeClosingUI();

    std::unordered_set<UI*> mUIStack;
};

