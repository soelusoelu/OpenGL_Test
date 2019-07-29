#pragma once

#include <set>

class IDManager {
public:
    enum Type {
        Mesh,
        Skeleton,
        Animation,
        Texture
    };

    void reset();
    void push(unsigned int id, Type type);
    unsigned int pop(Type type);

private:
    std::set<unsigned int> mMeshIDs;
    std::set<unsigned int> mSkeletonIDs;
    std::set<unsigned int> mAnimationIDs;
    std::set<unsigned int> mTextureIDs;
};

