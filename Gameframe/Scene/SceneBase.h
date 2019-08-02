#pragma once

class SceneBase {
public:
    virtual ~SceneBase();
    virtual void update(float deltaTime) = 0;
    virtual void draw() const = 0;
};
