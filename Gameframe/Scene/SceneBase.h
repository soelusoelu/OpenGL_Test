#pragma once

class SceneBase {
public:
    virtual void update(float deltaTime) = 0;
    virtual ~SceneBase();
};
