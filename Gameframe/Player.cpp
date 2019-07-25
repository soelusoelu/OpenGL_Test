#include "Player.h"
#include "Octree.h"
#include "StringRenderer.h"
#include <gslib.h>
#include <string>
#include <iostream>

Player::Player(unsigned int id, const std::string& filename) :
    mID(id),
    mFilename(filename),
    animationTimer(0.f),
    mPosition(0.f, 0.f, 0.f),
    mAngle(0.f),
    mSpeed(0.f),
    mRadius(2.f) {
    gsLoadMesh(mID, (mFilename + ".msh").c_str());
    gsLoadSkeleton(mID, (mFilename + ".skl").c_str());
    gsLoadAnimation(mID, (mFilename + ".anm").c_str());
}

Player::~Player() {
    gsDeleteMesh(mID);
    gsDeleteSkeleton(mID);
    gsDeleteAnimation(mID);
    std::cout << "Player destructor;" << std::endl;
}

void Player::update(float deltaTime) {
    animationTimer += 2.f * deltaTime;
    if (gsGetKeyState(GKEY_LEFT) || gsGetKeyState(GKEY_A)) {
        mAngle += 2.f * deltaTime;
        if (mAngle > 180.f) {
            mAngle -= 360.f;
        }
    }
    if (gsGetKeyState(GKEY_RIGHT) || gsGetKeyState(GKEY_D)) {
        mAngle -= 2.f * deltaTime;
        if (mAngle < -180.f) {
            mAngle += 360.f;
        }
    }

    mSpeed = 0.f;
    if (gsGetKeyState(GKEY_UP) || gsGetKeyState(GKEY_W)) {
        mSpeed = 1.5f;
    }
    if (gsGetKeyState(GKEY_DOWN) || gsGetKeyState(GKEY_S)) {
        mSpeed = -1.5f;
    }
    if (gsGetKeyState(GKEY_LSHIFT)) {
        mSpeed += 2.f;
    }
    mPosition.x += gsSin(mAngle) * mSpeed * deltaTime;
    mPosition.z += gsCos(mAngle) * mSpeed * deltaTime;
}

void Player::draw(unsigned int animationNo) const {
    gsBindAnimation(mID, animationNo, animationTimer);
    gsBindSkeleton(mID);

    glPushMatrix();
    glTranslatef(mPosition.x, mPosition.y, mPosition.z);
    glRotatef(mAngle, 0.f, 1.f, 0.f);
    gsDrawMesh(mID);
    glPopMatrix();

    //StringRenderer::printf(0.f, 0.f, "Angle:%6.1f", mAngle);
}

void Player::vector3FromHorizontalDir(GSvector3* out) const {
    gsVector3FromEleDir(out, 0.f, mAngle);
}

const GSvector3& Player::getPosition() const {
    return mPosition;
}

GSvector3& Player::getPosition() {
    return mPosition;
}

const float Player::getRadius() const {
    return mRadius;
}
