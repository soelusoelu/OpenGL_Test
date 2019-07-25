#pragma once

#include <gslib.h>
#include <string>

class Player {
public:
    Player(unsigned int id, const std::string& filename);
    ~Player();
    void update(float deltaTime);
    void draw(unsigned int animationNo = 0) const;
    void vector3FromHorizontalDir(GSvector3* out) const;

    const GSvector3& getPosition() const;
    GSvector3& getPosition();
    const float getRadius() const;

private:
    unsigned int mID;
    float animationTimer;
    GSvector3 mPosition;
    float mAngle;
    float mSpeed;
    float mRadius;
    std::string mFilename;
};

