#pragma once

#include "Utility/Math.h"
#include <gslib.h>

class PlayerActor;

class Camera {
public:
    void update(PlayerActor* player);
    static void create();
    static void destroy();
    static Camera* instance();

private:
    Camera() = default;
    ~Camera() = default;
    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    Camera(Camera&&) = delete;
    Camera& operator=(Camera&&) = delete;

    static Camera* mInstance;
    static Vector3 mCameraPosition;
    static Vector3 mPlayerPosition;
};

