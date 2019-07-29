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

    static void reset();
    static void push(unsigned int id, Type type);
    static unsigned int pop(Type type);

private:
    static std::set<unsigned int> mMeshIDs;
    static std::set<unsigned int> mSkeletonIDs;
    static std::set<unsigned int> mAnimationIDs;
    static std::set<unsigned int> mTextureIDs;
};

