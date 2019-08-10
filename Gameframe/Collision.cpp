#include "Collision.h"
#include <algorithm>
#include <array>

Ray::Ray(const Vector3& start, const Vector3& end) :
    mStart(start),
    mEnd(end) {
}

Vector3 Ray::pointOnSegment(float t) const {
    return mStart + (mEnd - mStart) * t;
}

float Ray::minDistanceSquare(const Vector3& point) const {
    //ベクトルの準備
    Vector3 ab = mEnd - mStart;
    Vector3 ba = -1.0f * ab;
    Vector3 ac = point - mStart;
    Vector3 bc = point - mEnd;

    // Case 1: Aの外側
    if (Vector3::dot(ab, ac) < 0.0f) {
        return ac.lengthSq();
    }
    // Case 2: Bの外側
    else if (Vector3::dot(ba, bc) < 0.0f) {
        return bc.lengthSq();
    }
    // Case 3:ABの間
    else {
        //pを計算
        float scalar = Vector3::dot(ac, ab) / Vector3::dot(ab, ab);
        Vector3 p = scalar * ab;
        //ac - pの長さの2乗を計算
        return (ac - p).lengthSq();
    }
}

float Ray::minDistanceSquare(const Ray& s1, const Ray& s2) {
    Vector3   u = s1.mEnd - s1.mStart;
    Vector3   v = s2.mEnd - s2.mStart;
    Vector3   w = s1.mStart - s2.mStart;
    float    a = Vector3::dot(u, u);         // always >= 0
    float    b = Vector3::dot(u, v);
    float    c = Vector3::dot(v, v);         // always >= 0
    float    d = Vector3::dot(u, w);
    float    e = Vector3::dot(v, w);
    float    D = a * c - b * b;        // always >= 0
    float    sc, sN, sD = D;       // sc = sN / sD, default sD = D >= 0
    float    tc, tN, tD = D;       // tc = tN / tD, default tD = D >= 0

                                   // compute the line parameters of the two closest points
    if (Math::nearZero(D)) { // the lines are almost parallel
        sN = 0.0;         // force using point P0 on segment S1
        sD = 1.0;         // to prevent possible division by 0.0 later
        tN = e;
        tD = c;
    } else {                 // get the closest points on the infinite lines
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0.0) {        // sc < 0 => the s=0 edge is visible
            sN = 0.0;
            tN = e;
            tD = c;
        } else if (sN > sD) {  // sc > 1  => the s=1 edge is visible
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0.0) {            // tc < 0 => the t=0 edge is visible
        tN = 0.0;
        // recompute sc for this edge
        if (-d < 0.0)
            sN = 0.0;
        else if (-d > a)
            sN = sD;
        else {
            sN = -d;
            sD = a;
        }
    } else if (tN > tD) {      // tc > 1  => the t=1 edge is visible
        tN = tD;
        // recompute sc for this edge
        if ((-d + b) < 0.0)
            sN = 0;
        else if ((-d + b) > a)
            sN = sD;
        else {
            sN = (-d + b);
            sD = a;
        }
    }
    // finally do the division to get sc and tc
    sc = (Math::nearZero(sN) ? 0.0f : sN / sD);
    tc = (Math::nearZero(tN) ? 0.0f : tN / tD);

    // get the difference of the two closest points
    Vector3   dP = w + (sc * u) - (tc * v);  // =  S1(sc) - S2(tc)

    return dP.lengthSq();   // return the closest distance squared
}



Plane::Plane(const Vector3& normal, float d) :
    mNormal(normal),
    mD(d) {
}

Plane::Plane(const Vector3& a, const Vector3& b, const Vector3& c) {
    //abとacのベクトルを計算
    Vector3 ab = b - a;
    Vector3 ac = c - a;
    //外積と正規化で法線を得る
    mNormal = Vector3::cross(ab, ac);
    mNormal.normalize();
    // d = -P dot n
    mD = -Vector3::dot(a, mNormal);
}

float Plane::signedDistance(const Vector3& point) const {
    return Vector3::dot(point, mNormal) - mD;
}



Sphere::Sphere(const Vector3& center, float radius) :
    mCenter(center),
    mRadius(radius) {
}

bool Sphere::contains(const Vector3& point) const {
    //中心と点との距離の2乗を求める
    float distSq = (mCenter - point).lengthSq();
    return distSq <= (mRadius * mRadius);
}



AABB::AABB(const Vector3& min, const Vector3& max) :
    mMin(min),
    mMax(max) {
}

void AABB::updateMinMax(const Vector3& point) {
    //各コンポーネントを個別に更新
    mMin.x = Math::min(mMin.x, point.x);
    mMin.y = Math::min(mMin.y, point.y);
    mMin.z = Math::min(mMin.z, point.z);

    mMax.x = Math::max(mMax.x, point.x);
    mMax.y = Math::max(mMax.y, point.y);
    mMax.z = Math::max(mMax.z, point.z);
}

void AABB::rotate(const Quaternion& q) {
    //ボックスの角の8点を構築
    std::array<Vector3, 8> points;
    //最小の点は常に角にある
    points[0] = mMin;
    //2個のminと1個のmaxによる順列組み合わせ
    points[1] = Vector3(mMax.x, mMin.y, mMin.z);
    points[2] = Vector3(mMin.x, mMax.y, mMin.z);
    points[3] = Vector3(mMin.x, mMin.y, mMax.z);
    //1個のminと2個のmaxによる順列組み合わせ
    points[4] = Vector3(mMin.x, mMax.y, mMax.z);
    points[5] = Vector3(mMax.x, mMin.y, mMax.z);
    points[6] = Vector3(mMax.x, mMax.y, mMin.z);
    //最大の点は角にある
    points[7] = Vector3(mMax);

    //最初の点を回転する
    Vector3 p = Vector3::transform(points[0], q);
    //回転した第一の点で、min/maxをリセットする
    mMin = p;
    mMax = p;
    //残りの(回転後の)点によってmin/maxを更新
    for (size_t i = 1; i < points.size(); i++) {
        p = Vector3::transform(points[i], q);
        updateMinMax(p);
    }
}

bool AABB::contains(const Vector3& point) const {
    bool outside = point.x < mMin.x ||
        point.y < mMin.y ||
        point.z < mMin.z ||
        point.x > mMax.x ||
        point.y > mMax.y ||
        point.z > mMax.z;
    //いずれも当てはまらない場合、点はボックス内
    return !outside;
}

float AABB::minDistanceSquare(const Vector3& point) const {
    //各軸の差を計算
    float dx = Math::max(mMin.x - point.x, 0.0f);
    dx = Math::max(dx, point.x - mMax.x);
    float dy = Math::max(mMin.y - point.y, 0.0f);
    dy = Math::max(dy, point.y - mMax.y);
    float dz = Math::max(mMin.z - point.z, 0.0f);
    dz = Math::max(dy, point.z - mMax.z);
    //距離の2乗
    return dx * dx + dy * dy + dz * dz;
}



Capsule::Capsule(const Vector3& start, const Vector3& end, float radius) :
    mSegment(start, end),
    mRadius(radius) {
}

Vector3 Capsule::pointOnSegment(float t) const {
    return mSegment.pointOnSegment(t);
}

bool Capsule::contains(const Vector3& point) const {
    //点と線分との最短距離の2乗を求める
    float distSq = mSegment.minDistanceSquare(point);
    return distSq <= (mRadius * mRadius);
}



bool ConvexPolygon::contains(const Vector2& point) const {
    float sum = 0.0f;
    Vector2 a, b;
    for (size_t i = 0; i < mVertices.size() - 1; i++) {
        //点から第1の頂点へのベクトル
        a = mVertices[i] - point;
        a.Normalize();
        //点から第2の頂点へのベクトル
        b = mVertices[i + 1] - point;
        b.Normalize();
        //2つのベクトルが成す角度を合計に加算
        sum += Math::acos(Vector2::Dot(a, b));
    }
    //最後と最初の頂点の間で角度を計算
    a = mVertices.back() - point;
    a.Normalize();
    b = mVertices.front() - point;
    b.Normalize();
    sum += Math::acos(Vector2::Dot(a, b));
    //合計が約2πであればtrue
    return Math::nearZero(sum - Math::TwoPi);
}



bool intersect(const Sphere& a, const Sphere& b) {
    float distSq = (a.mCenter - b.mCenter).lengthSq();
    float sumRadii = a.mRadius + b.mRadius;
    return distSq <= (sumRadii * sumRadii);
}

bool intersect(const AABB& a, const AABB& b) {
    bool no = a.mMax.x < b.mMin.x ||
        a.mMax.y < b.mMin.y ||
        a.mMax.z < b.mMin.z ||
        b.mMax.x < a.mMin.x ||
        b.mMax.y < a.mMin.y ||
        b.mMax.z < a.mMin.z;
    //いずれも当てはまらない場合、交差している
    return !no;
}

bool intersect(const Capsule& a, const Capsule& b) {
    float distSq = Ray::minDistanceSquare(a.mSegment, b.mSegment);
    float sumRadii = a.mRadius + b.mRadius;
    return distSq <= (sumRadii * sumRadii);
}

bool intersect(const Sphere& s, const AABB& box) {
    float distSq = box.minDistanceSquare(s.mCenter);
    return distSq <= (s.mRadius * s.mRadius);
}

bool intersect(const Ray& r, const Sphere& s, float* outT) {
    //方程式のX, Y, a, b, cを計算
    Vector3 X = r.mStart - s.mCenter;
    Vector3 Y = r.mEnd - r.mStart;
    float a = Vector3::dot(Y, Y);
    float b = 2.0f * Vector3::dot(X, Y);
    float c = Vector3::dot(X, X) - s.mRadius * s.mRadius;
    //判別式を計算
    float disc = b * b - 4.0f * a * c;
    if (disc < 0.0f) {
        return false;
    } else {
        disc = Math::sqrt(disc);
        //tの解(minとmax)を求める
        float tMin = (-b - disc) / (2.0f * a);
        float tMax = (-b + disc) / (2.0f * a);
        //tが線分の領域にあるのかチェック
        if (0.f <= tMin && tMin <= 1.0f) {
            *outT = tMin;
            return true;
        } else if (0.f <= tMax && tMax <= 1.0f) {
            *outT = tMax;
            return true;
        } else {
            return false;
        }
    }
}

bool intersect(const Ray& r, const Plane& p, float* outT) {
    //最初にtの解が存在するのかテスト
    float denom = Vector3::dot(r.mEnd - r.mStart, p.mNormal);
    if (Math::nearZero(denom)) {
        //交差の可能性があるのは、唯一 start/end が平面上の点であるとき
        //すなわち、(P dot N) == d の場合のみ
        if (Math::nearZero(Vector3::dot(r.mStart, p.mNormal) - p.mD)) {
            *outT = 0.f;
            return true;
        } else {
            return false;
        }
    } else {
        float numer = -Vector3::dot(r.mStart, p.mNormal) - p.mD;
        *outT = numer / denom;
        //tが線分の境界内にあるか
        if (0.f <= *outT && *outT <= 1.0f) {
            return true;
        } else {
            return false;
        }
    }
}

bool testSidePlane(float start, float end, float negd, const Vector3& norm, std::vector<std::pair<float, Vector3>>* out) {
    float denom = end - start;
    if (Math::nearZero(denom)) {
        return false;
    } else {
        float numer = -start + negd;
        float t = numer / denom;
        //tが範囲内にあることをテスト
        if (0.f <= t && t <= 1.0f) {
            out->emplace_back(t, norm);
            return true;
        } else {
            return false;
        }
    }
}

bool intersect(const Ray& r, const AABB& b, float* outT, Vector3* outNorm) {
    //可能性のあるtの値をすべて保存する配列
    std::vector<std::pair<float, Vector3>> tValues;
    //x平面をテスト
    testSidePlane(r.mStart.x, r.mEnd.x, b.mMin.x, Vector3::right, &tValues);
    testSidePlane(r.mStart.x, r.mEnd.x, b.mMax.x, Vector3::left, &tValues);
    //y平面をテスト
    testSidePlane(r.mStart.y, r.mEnd.y, b.mMin.y, Vector3::up, &tValues);
    testSidePlane(r.mStart.y, r.mEnd.y, b.mMax.y, Vector3::down, &tValues);
    //z平面をテスト
    testSidePlane(r.mStart.z, r.mEnd.z, b.mMin.z, Vector3::forward, &tValues);
    testSidePlane(r.mStart.z, r.mEnd.z, b.mMax.z, Vector3::back, &tValues);

    //tの値を小さい順にソート
    std::sort(tValues.begin(), tValues.end(), [](
        const std::pair<float, Vector3>& a,
        const std::pair<float, Vector3>& b) {
            return a.first < b.first;
        });
    //ボックスに交点が含まれるかテスト
    Vector3 point;
    for (const auto& t : tValues) {
        point = r.pointOnSegment(t.first);
        if (b.contains(point)) {
            *outT = t.first;
            *outNorm = t.second;
            return true;
        }
    }

    //ボックス内部に交点が一つもない
    return false;
}

bool SweptSphere(const Sphere& P0, const Sphere& P1, const Sphere& Q0, const Sphere& Q1, float* outT) {
    //X, Y, a, b, cを計算
    Vector3 X = P0.mCenter - Q0.mCenter;
    Vector3 Y = P1.mCenter - P0.mCenter - (Q1.mCenter - Q0.mCenter);
    float a = Vector3::dot(Y, Y);
    float b = 2.0f * Vector3::dot(X, Y);
    float sumRadii = P0.mRadius + Q0.mRadius;
    float c = Vector3::dot(X, X) - sumRadii * sumRadii;
    //判別式を解く
    float disc = b * b - 4.0f * a * c;
    if (disc < 0.0f) {
        return false;
    } else {
        disc = Math::sqrt(disc);
        //小さい方の解だけが重要
        *outT = (-b - disc) / (2.0f * a);
        if (0.f <= *outT && *outT <= 0.0f) {
            return true;
        } else {
            return false;
        }
    }
}
