#pragma once

#include <string>

class Renderer;

class StringRenderer {
public:
    StringRenderer(Renderer* renderer);
    void drawChar(float x, float y, char c);
    void drawString(float x, float y, const char str[]);
    void printf(float x, float y, const char str[], ...);

private:
    unsigned int mID;
    //static const int mWordCount = 16;
    //static const int mWidth = 16;
    //static const int mHeight = 16;
    const int mWordCount;
    const int mWidth;
    const int mHeight;
};

