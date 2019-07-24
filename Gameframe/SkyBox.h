#pragma once

class SkyBox {
public:
    SkyBox(unsigned int meshID, const char* filename);
    ~SkyBox();
    void update(float deltaTime);
    void draw();

private:
    unsigned int mMeshID;
    const char* mFilename;
    float mViewRoll; //zŽ²‰ñ“]
    float mViewPitch; //xŽ²‰ñ“]
    float mViewYow; //yŽ²‰ñ“]
};

