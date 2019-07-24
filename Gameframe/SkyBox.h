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
    float mViewRoll; //z����]
    float mViewPitch; //x����]
    float mViewYow; //y����]
};

