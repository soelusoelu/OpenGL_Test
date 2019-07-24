#pragma once

#include <gslib.h>

class Player;

class Octree {
public:
    Octree(unsigned int octreeID, const char* filename);
    Octree(
        unsigned int octreeID,
        const char* filename,
        const GSvector3& position);
    ~Octree();
    void intersectGround(Player* player);
    void intersectWall(Player* player);
    void draw() const;

private:
    unsigned int mOctreeID;
    const char* mFilename;
    GSvector3 mSpherePosition;
};

