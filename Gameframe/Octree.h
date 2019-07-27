#pragma once

#include <gslib.h>

class PlayerActor;

class Octree {
public:
    Octree(unsigned int octreeID, const char* filename);
    Octree(
        unsigned int octreeID,
        const char* filename,
        const GSvector3& position);
    ~Octree();
    void intersectGround(PlayerActor* player);
    void intersectWall(PlayerActor* player);
    void draw() const;

private:
    unsigned int mOctreeID;
    const char* mFilename;
    GSvector3 mSpherePosition;
};

