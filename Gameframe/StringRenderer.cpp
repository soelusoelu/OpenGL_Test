#include "StringRenderer.h"
#include "Sprite3D.h"
#include "IDManager.h"
#include <gslib.h>

void StringRenderer::loadFontTexture(std::string filename) {
    mTextureID = IDManager::pop(IDManager::Type::Texture);
    gsLoadTexture(mTextureID, filename.c_str());
}

void StringRenderer::unloadFontTexture() {
    gsDeleteTexture(mTextureID);
    IDManager::push(mTextureID, IDManager::Type::Texture);
}

void StringRenderer::drawChar(float x, float y, char c) {
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
        mTextureID,
        &vTranslate,
        &rSrcRect,
        &GSvector2(0.f, 0.f),
        &GScolor(1.f, 1.f, 1.f, 1.f),
        &GSvector2(1.f, 1.f),
        0.f);
}

void StringRenderer::drawString(float x, float y, const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        drawChar(x, y, str[i]);

        x += mWidth;
    }
}

void StringRenderer::printf(float x, float y, const char str[], ...) {
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

unsigned int StringRenderer::mTextureID;
