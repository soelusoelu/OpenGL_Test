#pragma once

#include <list>

class IDManager {
public:
    enum Type {
        Mesh,
        Skeleton,
        Animation,
        Texture
    };

    IDManager();
    ~IDManager();
    void push(unsigned int id, Type type);
    unsigned int pop(Type type);

private:
    std::list<unsigned int> mMeshIDs;
    std::list<unsigned int> mSkeletonIDs;
    std::list<unsigned int> mAnimationIDs;
    std::list<unsigned int> mTextureIDs;
};
