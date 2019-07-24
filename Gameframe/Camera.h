#pragma once

#include <gslib.h>
#include <memory>

class Player;

class Camera {
public:
    void update(const Player& player) const;
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
};

