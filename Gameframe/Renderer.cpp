#include "Renderer.h"
#include "Scene/GamePlay.h"
#include "Utility/IDManager.h"
#include <gslib.h>
#include <unordered_map>
#include <memory>

Renderer::Renderer(GamePlay* game) :
    mIDManager(std::make_unique<IDManager>()),
    mGame(game) {
}

Renderer::~Renderer() {
    for (const auto& mesh : mMeshes) {
        gsDeleteMesh(mesh.second);
        mIDManager->push(mesh.second, IDManager::Type::Mesh);
    }
    mMeshes.clear();
    for (const auto& skeleton : mSkeletons) {
        gsDeleteSkeleton(skeleton.second);
        mIDManager->push(skeleton.second, IDManager::Type::Skeleton);
    }
    mSkeletons.clear();
    for (const auto& animation : mAnimations) {
        gsDeleteAnimation(animation.second);
        mIDManager->push(animation.second, IDManager::Type::Animation);
    }
    mAnimations.clear();
    for (const auto& texture : mTextures) {
        gsDeleteTexture(texture.second);
        mIDManager->push(texture.second, IDManager::Type::Texture);
    }
    mTextures.clear();
}

unsigned int Renderer::getMesh(const std::string& filename) {
    unsigned int id;
    auto itr = mMeshes.find(filename);
    if (itr != mMeshes.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Mesh);
        gsLoadMesh(id, filename.c_str());
        mMeshes.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getSkeleton(const std::string& filename) {
    unsigned int id;
    auto itr = mSkeletons.find(filename);
    if (itr != mSkeletons.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Skeleton);
        gsLoadSkeleton(id, filename.c_str());
        mSkeletons.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getAnimation(const std::string& filename) {
    unsigned int id;
    auto itr = mAnimations.find(filename);
    if (itr != mAnimations.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Animation);
        gsLoadAnimation(id, filename.c_str());
        mAnimations.emplace(filename, id);
    }
    return id;
}

unsigned int Renderer::getTexture(const std::string& filename) {
    unsigned int id;
    auto itr = mTextures.find(filename);
    if (itr != mTextures.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Texture);
        gsLoadTexture(id, filename.c_str());
        mTextures.emplace(filename, id);
    }
    return id;
}
