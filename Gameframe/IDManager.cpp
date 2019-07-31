#include "IDManager.h"
#include <set>

void IDManager::reset() {
    mMeshIDs.clear();
    mSkeletonIDs.clear();
    mAnimationIDs.clear();
    mTextureIDs.clear();
}

void IDManager::push(unsigned int id, IDManager::Type type) {
    switch (type) {
    case IDManager::Mesh: mMeshIDs.emplace(id); break;
    case IDManager::Skeleton: mSkeletonIDs.emplace(id); break;
    case IDManager::Animation: mAnimationIDs.emplace(id); break;
    case IDManager::Texture: mTextureIDs.emplace(id); break;
    }
}

unsigned int IDManager::pop(IDManager::Type type) {
    if (mMeshIDs.size() == 0) {
        for (unsigned int i = 0; i < 100; i++) {
            mMeshIDs.emplace(i);
            mSkeletonIDs.emplace(i);
            mAnimationIDs.emplace(i);
            mTextureIDs.emplace(i);
        }
    }

    unsigned int id = 0;
    switch (type) {
    case IDManager::Mesh: id = *mMeshIDs.begin(); mMeshIDs.erase(id); break;
    case IDManager::Skeleton: id = *mSkeletonIDs.begin(); mSkeletonIDs.erase(id); break;
    case IDManager::Animation: id = *mAnimationIDs.begin(); mAnimationIDs.erase(id);  break;
    case IDManager::Texture: id = *mTextureIDs.begin(); mTextureIDs.erase(id); break;
    }

    return id;
}
