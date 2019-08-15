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
    static const int mWordCount;
    static const int mWidth;
    static const int mHeight;
};

