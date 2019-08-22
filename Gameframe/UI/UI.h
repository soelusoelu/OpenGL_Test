#pragma once

class GameSystem;
class InterfaceUI;

class UI {
public:
    enum State {
        Active,
        Closing
    };
    UI(GameSystem* system, InterfaceUI* interfaceUI);
    virtual ~UI() {};
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
    void close();
    State getState() const;

protected:
    GameSystem* mSystem;
    State mState;
};

