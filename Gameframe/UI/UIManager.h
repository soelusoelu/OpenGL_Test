#pragma once

#include "InterfaceUI.h"
#include <unordered_set>

class UI;

class UIManager : public InterfaceUI {
public:
    ~UIManager();
    virtual void pushUI(UI* ui) override;
    void update(float deltaTime);
    void draw() const;
    const std::unordered_set<UI*>& getUIStack() const;

private:
    void removeClosingUI();

    std::unordered_set<UI*> mUIStack;
};

