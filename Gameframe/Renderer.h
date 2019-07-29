#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class IDManager;

class Renderer {
public:
    Renderer();
    ~Renderer();
    unsigned int getMesh(const std::string& filename);
    unsigned int getSkeleton(const std::string& filename);
    unsigned int getAnimation(const std::string& filename);
    unsigned int getTexture(const std::string& filename);

private:
    std::unordered_map<std::string, unsigned int> mMeshes;
    std::unordered_map<std::string, unsigned int> mSkeletons;
    std::unordered_map<std::string, unsigned int> mAnimations;
    std::unordered_map<std::string, unsigned int> mTextures;
    std::unique_ptr<IDManager> mIDManager;
};

