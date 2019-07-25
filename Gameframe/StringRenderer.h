#pragma once

class StringRenderer {
public:
    static void loadFontTexture(unsigned int textureID, const char* filename);
    static void drawChar(float x, float y, char c);
    static void drawString(float x, float y, const char str[]);
    static void printf(float x, float y, const char str[], ...);

private:
    static unsigned int mTextureID;
    static const int mWordCount = 16;
    static const int mWidth = 16;
    static const int mHeight = 16;
};
