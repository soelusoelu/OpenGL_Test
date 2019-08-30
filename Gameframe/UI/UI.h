#pragma once

#include "../Utility/Math.h"
#include <memory>

class Renderer;

class UI {
public:
    enum State {
        Active,
        Closing
    };
    UI(std::shared_ptr<Renderer> renderer);
    virtual ~UI() {};
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    void close();
    State getState() const;

protected:
    std::shared_ptr<Renderer> mRenderer;
    State mState;
};

