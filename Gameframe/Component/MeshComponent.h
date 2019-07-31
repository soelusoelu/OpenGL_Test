#pragma once

#include "Component.h"
#include <string>

class Actor;

class MeshComponent : public Component {
public:
    MeshComponent(Actor& owner, const std::string& filename, int updateOrder = 200);
    ~MeshComponent();
    virtual void start() override;
    virtual void update(float deltaTime) override;
    void draw() const;

    void setEnable(bool set);
    bool getEnable() const;

private:
    unsigned int mID;
    bool mEnabled;

};

