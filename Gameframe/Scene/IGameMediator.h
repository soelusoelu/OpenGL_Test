#pragma once

class GameSystem;

class IGameMediator {
public:
    virtual ~IGameMediator() {};
    virtual GameSystem* getSystem() const = 0;
};

