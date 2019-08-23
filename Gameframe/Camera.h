#pragma once

#include "Singleton.h"
#include "Utility/Math.h"
#include <gslib.h>

class PlayerActor;

class Camera {
    friend class Singleton<Camera>;
public:
    void update(PlayerActor* player);

private:
    Camera() {};
    ~Camera() {};

    Vector3 mCameraPosition;
    Vector3 mPlayerPosition;
};

