#pragma once

class UI;

class IUIMediator {
public:
    virtual ~IUIMediator() {};
    virtual void pushUI(UI* ui) = 0;
};

