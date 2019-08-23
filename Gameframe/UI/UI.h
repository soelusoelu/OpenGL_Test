#pragma once

#include "../Utility/Math.h"
#include <string>

class GameSystem;

class UI {
public:
    enum State {
        Active,
        Closing
    };
    UI(GameSystem* system);
    virtual ~UI() {};
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    void setTexture(const std::string& filename);
    void drawTexture();
    void close();
    State getState() const;

protected:
    GameSystem* mSystem;
    State mState;
    Vector2 mPosition;
    float mRotation;
    Vector2 mScale;
    Vector3 mColor;
    unsigned mID;
};

