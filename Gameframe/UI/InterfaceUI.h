#pragma once

class UI;

class InterfaceUI {
public:
    virtual ~InterfaceUI() {};
    virtual void pushUI(UI* ui) = 0;
};

