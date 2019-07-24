#pragma once

#include <gslib.h>

class Sprite2D {
public:
    Sprite2D(unsigned int textureID, const char* filename);
    ~Sprite2D();
    void setPosition(const GSvector2& position);
    void setScale(const GSvector2& scale);
    void setRotate(float rotate);
    void setRect(const GSrect& rect);
    void setColor(const GScolor4& color);
    void setImageRect(const GSrect& rect);
    void draw();

private:
    unsigned int mTextureID;
    const char* mFilename;
    GSvector2 mPosition;
    GSvector2 mScale;
    float mRotate;
    GScolor mColor;
    GSrect mRect;
    GSrect mTexCoord;
};

