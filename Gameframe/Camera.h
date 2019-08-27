#pragma once

#include "Singleton.h"
#include "Utility/Math.h"
#include <memory>

class PlayerActor;

class Camera {
    friend class Singleton<Camera>;
public:
    void update(std::shared_ptr<PlayerActor> player);

private:
    Camera() {};
    ~Camera() {};

    Vector3 mCameraPosition;
    Vector3 mPlayerPosition;
};

