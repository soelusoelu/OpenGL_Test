#pragma once

#include <gslib.h>

class PlayerActor;

class Camera {
public:
    void update(PlayerActor* player);
    static void create();
    static void destroy();
    static Camera& instance();

private:
    Camera() = default;
    ~Camera() = default;
    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    Camera(Camera&&) = delete;
    Camera& operator=(Camera&&) = delete;

    static Camera* mInstance;
    static GSvector3 mCameraPosition;
    static GSvector3 mPlayerPosition;
};

