#pragma once

#include "../Utility/Math.h"
#include <string>
#include <memory>

class Texture {
public:
    Texture();
    void setTexture(const std::string& filename);
    void setPosition(const Vector2& position);
    void setScale(const Vector2& scale);
    void setRotate(float rotation);
    void setRect(const Rect& rect);
    void setColor(float r, float g, float b, float a);
    void setColor(const Vector3& color, float alpha);
    void setImageRect(const Rect& rect);
    void drawTexture();

private:
    unsigned mTextureID;
    Vector2 mPosition;
    Vector2 mScale;
    float mRotation;
    Color mColor;
    Rect mRect;
    Rect mTextureCoord;
};

