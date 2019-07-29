#include "Renderer.h"
#include "IDManager.h"
#include <gslib.h>
#include <unordered_map>

Renderer::~Renderer() {
    for (auto mesh : mMeshes) {
        gsDeleteMesh(mesh.second);
        IDManager::push(mesh.second, IDManager::Type::Mesh);
    }
    mMeshes.clear();
    for (auto skeleton : mSkeletons) {
        gsDeleteSkeleton(skeleton.second);
        IDManager::push(skeleton.second, IDManager::Type::Skeleton);
    }
    mSkeletons.clear();
    for (auto animation : mAnimations) {
        gsDeleteAnimation(animation.second);
        IDManager::push(animation.second, IDManager::Type::Animation);
    }
    mAnimations.clear();
    for (auto texture : mTextures) {
        gsDeleteTexture(texture.second);
        IDManager::push(texture.second, IDManager::Type::Texture);
    }
    mTextures.clear();
}

unsigned int Renderer::getMesh(const std::string& filename) {
    unsigned int id;
    auto itr = mMeshes.find(filename);
    if (itr != mMeshes.end()) { //Šù‚É“Ç‚İ‚Ü‚ê‚Ä‚¢‚é
        id = itr->second;
    } else { //‰“Ç‚İ‚İ
        id = IDManager::pop(IDManager::Type::Mesh);
        gsLoadMesh(id, filename.c_str());
        mMeshes.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getSkeleton(const std::string& filename) {
    unsigned int id;
    auto itr = mSkeletons.find(filename);
    if (itr != mSkeletons.end()) { //Šù‚É“Ç‚İ‚Ü‚ê‚Ä‚¢‚é
        id = itr->second;
    } else { //‰“Ç‚İ‚İ
        id = IDManager::pop(IDManager::Type::Skeleton);
        gsLoadSkeleton(id, filename.c_str());
        mSkeletons.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getAnimation(const std::string& filename) {
    unsigned int id;
    auto itr = mAnimations.find(filename);
    if (itr != mAnimations.end()) { //Šù‚É“Ç‚İ‚Ü‚ê‚Ä‚¢‚é
        id = itr->second;
    } else { //‰“Ç‚İ‚İ
        id = IDManager::pop(IDManager::Type::Animation);
        gsLoadAnimation(id, filename.c_str());
        mAnimations.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getTexture(const std::string& filename) {
    unsigned int id;
    auto itr = mTextures.find(filename);
    if (itr != mTextures.end()) { //Šù‚É“Ç‚İ‚Ü‚ê‚Ä‚¢‚é
        id = itr->second;
    } else { //‰“Ç‚İ‚İ
        id = IDManager::pop(IDManager::Type::Texture);
        gsLoadTexture(id, filename.c_str());
        mTextures.emplace(filename, id);
    }
    return id;
}
