#pragma once
class Light {
public:
    static void update();

private:
    static const float mLightAmbient[];
    static const float mLightDiffuse[];
    static const float mLightSpeclar[];
    static const float mLightPosition[];
};

