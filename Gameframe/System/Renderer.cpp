#include "Renderer.h"
#include "../System/IDManager.h"
#include <GSgraphics.h>

Renderer::Renderer() :
    mIDManager(std::make_unique<IDManager>()) {
}

Renderer::~Renderer() {
    for (const auto& mesh : mMeshes) {
        gsDeleteMesh(mesh.second);
        mIDManager->push(mesh.second, IDManager::Type::Mesh);
    }
    mMeshes.clear();
    for (const auto& skeleton : mSkeletons) {
        gsDeleteSkeleton(skeleton.second);
        mIDManager->push(skeleton.second, IDManager::Type::Skeleton);
    }
    mSkeletons.clear();
    for (const auto& animation : mAnimations) {
        gsDeleteAnimation(animation.second);
        mIDManager->push(animation.second, IDManager::Type::Animation);
    }
    mAnimations.clear();
    for (const auto& texture : mTextures) {
        gsDeleteTexture(texture.second);
        mIDManager->push(texture.second, IDManager::Type::Texture);
    }
    mTextures.clear();
}

unsigned Renderer::getMesh(const std::string& filename) {
    unsigned id;
    auto itr = mMeshes.find(filename);
    if (itr != mMeshes.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Mesh);
        gsLoadMesh(id, filename.c_str());
        mMeshes.emplace(filename, id);
    }
    return id;
}

unsigned Renderer::getSkeleton(const std::string& filename) {
    unsigned id;
    auto itr = mSkeletons.find(filename);
    if (itr != mSkeletons.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Skeleton);
        gsLoadSkeleton(id, filename.c_str());
        mSkeletons.emplace(filename, id);
    }
    return id;
}

unsigned Renderer::getAnimation(const std::string& filename) {
    unsigned id;
    auto itr = mAnimations.find(filename);
    if (itr != mAnimations.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Animation);
        gsLoadAnimation(id, filename.c_str());
        mAnimations.emplace(filename, id);
    }
    return id;
}

unsigned Renderer::getTexture(const std::string& filename) {
    unsigned id;
    auto itr = mTextures.find(filename);
    if (itr != mTextures.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Texture);
        gsLoadTexture(id, filename.c_str());
        mTextures.emplace(filename, id);
    }
    return id;
}

void Renderer::printf(float x, float y, const char* str, ...) {
    //可変引数リストの取得
    va_list args;
    va_start(args, str);

    //変換後の文字列を作成
    char buffer[256];
    vsprintf_s(buffer, str, args);

    //文字列の描画
    drawString(x, y, buffer);

    //可変引数リストの終了
    va_end(args);
}

void Renderer::drawChar(float x, float y, char c) {
    if (c < ' ' || c > '~') { //表示できる文字コードのチェック
        return;
    }

    //文字コードからテクスチャ内の座標に変換
    GSrect rSrcRect;
    rSrcRect.left = static_cast<float>((c - ' ') % mWordCount) * mWidth;
    rSrcRect.top = static_cast<float>((c - ' ') / mWordCount) * mWidth;
    rSrcRect.right = rSrcRect.left + mWidth;
    rSrcRect.bottom = rSrcRect.top + mHeight;

    //表示位置を設定する
    GSvector2 vTranslate(x, y);

    //文字を描画
    gsDrawSprite2D(
        getTexture("./res/font.bmp"),
        &vTranslate,
        &rSrcRect,
        &GSvector2(0.f, 0.f),
        &GScolor(1.f, 1.f, 1.f, 1.f),
        &GSvector2(1.f, 1.f),
        0.f);
}

void Renderer::drawString(float x, float y, const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        drawChar(x, y, str[i]);

        x += mWidth;
    }
}
