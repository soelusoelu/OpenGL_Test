#include "Input.h"
#include <GSinput.h>

void Input::update() {
    mPreviousKey = mCurrentKey;
    mCurrentKey = static_cast<KeyCode>(gsGetKey());
}

bool Input::getKeyDown(KeyCode key) {
    return (mCurrentKey == key && mPreviousKey != key);
}

bool Input::getKey(KeyCode key) {
    return mCurrentKey == key;
}

bool Input::getKeyUp(KeyCode key) {
    return (mCurrentKey != key && mPreviousKey == key);
}

int Input::horizontal() {
    if (getKey(KeyCode::A) || getKey(KeyCode::LeftArrow)) {
        return 1;
    } else if (getKey(KeyCode::D) || getKey(KeyCode::RightArrow)) {
        return -1;
    } else {
        return 0;
    }
}

int Input::vertical() {
    if (getKey(KeyCode::W) || getKey(KeyCode::UpArrow)) {
        return 1;
    } else if (getKey(KeyCode::S) || getKey(KeyCode::DownArrow)) {
        return -1;
    } else {
        return 0;
    }
}

Input::KeyCode Input::mCurrentKey = Input::KeyCode::None;
Input::KeyCode Input::mPreviousKey = Input::KeyCode::None;
