#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class IDManager;
class GamePlay;

class Renderer {
public:
    Renderer();
    ~Renderer();

    unsigned int getMesh(const std::string& filename);
    unsigned int getSkeleton(const std::string& filename);
    unsigned int getAnimation(const std::string& filename);
    unsigned int getTexture(const std::string& filename);

    void printf(float x, float y, const char* str, ...);

private:
    void drawChar(float x, float y, char c);
    void drawString(float x, float y, const char str[]);

    std::unordered_map<std::string, unsigned int> mMeshes;
    std::unordered_map<std::string, unsigned int> mSkeletons;
    std::unordered_map<std::string, unsigned int> mAnimations;
    std::unordered_map<std::string, unsigned int> mTextures;
    std::unique_ptr<IDManager> mIDManager;
    const int mWordCount = 16;
    const int mWidth = 16;
    const int mHeight = 16;
};

