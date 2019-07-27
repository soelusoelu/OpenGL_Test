#pragma once

class SceneBase {
public:
    virtual ~SceneBase();
    virtual void update(float deltaTime) = 0;
};
