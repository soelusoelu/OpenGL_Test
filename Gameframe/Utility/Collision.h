#pragma once

#include "Math.h"
#include <vector>

struct Ray {
    Ray(const Vector3& start, const Vector3& end);
    //線分上の点を返す 0 <= t <= 1
    Vector3 pointOnSegment(float t) const;
    //最短距離の2乗
    float minDistanceSquare(const Vector3& point) const;
    //2本の線分から最短距離の2乗を取得
    static float minDistanceSquare(const Ray& s1, const Ray& s2);

    Vector3 mStart;
    Vector3 mEnd;
};

struct Plane {
    Plane(const Vector3& normal, float d);
    //3点から平面を構築
    Plane(const Vector3& a, const Vector3& b, const Vector3& c);
    //点と平面の符号付き距離の取得(+:点は法線より上, -:点は法線より下)
    float signedDistance(const Vector3& point) const;

    Vector3 mNormal;
    float mD;
};

struct Sphere {
    Sphere(const Vector3& center, float radius);
    bool contains(const Vector3& point) const;

    Vector3 mCenter;
    float mRadius;
};

//axis-aligned bounding box つまり回転しない直方体
struct AABB {
    AABB(const Vector3& min, const Vector3& max);
    //Update min and max accounting for this point
    //(モデルのロード時に使用)
    void updateMinMax(const Vector3& point);
    void rotate(const Quaternion& q);
    bool contains(const Vector3& point) const;
    float minDistanceSquare(const Vector3& point) const;

    Vector3 mMin;
    Vector3 mMax;
};

//oriented bounding box つまり回転する直方体
//AABBよりはるかに計算コストが高い
struct OBB {
    Vector3 mCenter;
    Quaternion mRotation;
    Vector3 mExtents;
};

struct Capsule {
    Capsule(const Vector3& start, const Vector3& end, float radius);
    //線分上の点を返す 0 <= t <= 1
    Vector3 pointOnSegment(float t) const;
    bool contains(const Vector3& point) const;

    Ray mSegment;
    float mRadius;
};

struct ConvexPolygon {
    bool contains(const Vector2& point) const;
    //頂点を時計回りに格納
    std::vector<Vector2> mVertices;
};

//交差判定
bool intersect(const Sphere& a, const Sphere& b);
bool intersect(const AABB& a, const AABB& b);
bool intersect(const Capsule& a, const Capsule& b);
bool intersect(const Sphere& s, const AABB& box);

bool intersect(const Ray& r, const Sphere& s, float* outT);
bool intersect(const Ray& r, const Plane& p, float* outT);
bool intersect(const Ray& r, const AABB& b, float* outT, Vector3* outNorm);

bool SweptSphere(const Sphere& P0, const Sphere& P1, const Sphere& Q0, const Sphere& Q1, float* t);
