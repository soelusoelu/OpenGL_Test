#include "IDManager.h"

IDManager::IDManager() {
    mMeshIDs.emplace_back(0);
    mSkeletonIDs.emplace_back(0);
    mAnimationIDs.emplace_back(0);
    mTextureIDs.emplace_back(0);
}

void IDManager::push(unsigned id, IDManager::Type type) {
    if (type == IDManager::Type::Mesh) {
        mMeshIDs.emplace_front(id);
    } else if (type == IDManager::Type::Skeleton) {
        mSkeletonIDs.emplace_front(id);
    } else if (type == IDManager::Type::Animation) {
        mAnimationIDs.emplace_front(id);
    } else if (type == IDManager::Type::Texture) {
        mTextureIDs.emplace_front(id);
    }
}

unsigned int IDManager::pop(IDManager::Type type) {
    unsigned id = 0;

    if (type == IDManager::Type::Mesh) {
        if (mMeshIDs.front() != 0) {
            id = mMeshIDs.front();
            mMeshIDs.erase(mMeshIDs.begin());
        } else {
            id = mMeshIDs.back();
            mMeshIDs.emplace_back(id + 1);
        }
    } else if (type == IDManager::Type::Skeleton) {
        if (mSkeletonIDs.front() != 0) {
            id = mSkeletonIDs.front();
            mSkeletonIDs.erase(mSkeletonIDs.begin());
        } else {
            id = mSkeletonIDs.back();
            mSkeletonIDs.emplace_back(id + 1);
        }
    } else if (type == IDManager::Type::Animation) {
        if (mAnimationIDs.front() != 0) {
            id = mAnimationIDs.front();
            mAnimationIDs.erase(mAnimationIDs.begin());
        } else {
            id = mAnimationIDs.back();
            mAnimationIDs.emplace_back(id + 1);
        }
    } else if (type == IDManager::Type::Texture) {
        if (mTextureIDs.front() != 0) {
            id = mTextureIDs.front();
            mTextureIDs.erase(mTextureIDs.begin());
        } else {
            id = mTextureIDs.back();
            mTextureIDs.emplace_back(id + 1);
        }
    }

    return id;
}

void IDManager::clear() {
    mMeshIDs.clear();
    mSkeletonIDs.clear();
    mAnimationIDs.clear();
    mTextureIDs.clear();
}
