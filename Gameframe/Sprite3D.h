#ifndef _SPRITE3D_H_
#define _SPRITE3D_H_

#include <gslib.h>

class Sprite3D {
public:
    Sprite3D(unsigned int textureID, const char* filename);
    ~Sprite3D();
    void setPosition(const GSvector3& position);
    void setScale(const GSvector2& scale);
    void setRotate(float rotate);
    void setRect(const GSrect& rect);
    void setColor(const GScolor4& color);
    void setImageRect(const GSrect& rect);
    void draw();

private:
    unsigned int mTextureID;
    const char* mFilename;
    GSvector3 mPosition;
    GSvector2 mScale;
    float mRotate;
    GScolor mColor;
    GSrect mRect;
    GSrect mTexCoord;
};

#endif // !_SPRITE3D_H_
