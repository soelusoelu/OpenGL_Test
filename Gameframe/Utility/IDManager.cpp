#include "IDManager.h"

IDManager::IDManager() {
    mMeshIDs.emplace_back(0);
    mSkeletonIDs.emplace_back(0);
    mAnimationIDs.emplace_back(0);
    mTextureIDs.emplace_back(0);
}

IDManager::~IDManager() {
    mMeshIDs.clear();
    mSkeletonIDs.clear();
    mAnimationIDs.clear();
    mTextureIDs.clear();
}

void IDManager::push(unsigned int id, IDManager::Type type) {
    if (type == IDManager::Type::Mesh) {
        mMeshIDs.emplace_back(id);
    } else if (type == IDManager::Type::Skeleton) {
        mSkeletonIDs.emplace_back(id);
    } else if (type == IDManager::Type::Animation) {
        mAnimationIDs.emplace_back(id);
    } else if (type == IDManager::Type::Texture) {
        mTextureIDs.emplace_back(id);
    }
}

unsigned int IDManager::pop(IDManager::Type type) {
    unsigned int id = 0;

    if (type == IDManager::Type::Mesh) {
        id = mMeshIDs.back();
    } else if (type == IDManager::Type::Skeleton) {
        id = mSkeletonIDs.back();
    } else if (type == IDManager::Type::Animation) {
        id = mAnimationIDs.back();
    } else if (type == IDManager::Type::Texture) {
        id = mTextureIDs.back();
    }

    return id;
}
