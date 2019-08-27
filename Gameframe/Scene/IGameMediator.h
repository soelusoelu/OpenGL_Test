#pragma once

#include <memory>

class GameSystem;

class IGameMediator {
public:
    virtual ~IGameMediator() {};
    virtual std::shared_ptr<GameSystem> getSystem() const = 0;
};

