#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class IDManager;

class Renderer {
public:
    Renderer();
    ~Renderer();

    unsigned getMesh(const std::string& filename);
    unsigned getSkeleton(const std::string& filename);
    unsigned getAnimation(const std::string& filename);
    unsigned getTexture(const std::string& filename);

    void drawMesh(unsigned id);

    void printf(float x, float y, const char* str, ...);

private:
    void drawChar(float x, float y, char c);
    void drawString(float x, float y, const char str[]);

    std::unordered_map<std::string, unsigned> mMeshes;
    std::unordered_map<std::string, unsigned> mSkeletons;
    std::unordered_map<std::string, unsigned> mAnimations;
    std::unordered_map<std::string, unsigned> mTextures;
    std::unique_ptr<IDManager> mIDManager;
    const int mWordCount = 16;
    const int mWidth = 16;
    const int mHeight = 16;
};

