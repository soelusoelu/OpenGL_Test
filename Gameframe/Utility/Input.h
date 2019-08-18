#pragma once

class Input {
public:
    enum KeyCode {
        A = 0x1E,
        B = 0x30,
        C = 0x2E,
        D = 0x20,
        E = 0x12,
        F = 0x21,
        G = 0x22,
        H = 0x23,
        I = 0x17,
        J = 0x24,
        K = 0x25,
        L = 0x26,
        M = 0x32,
        N = 0x31,
        O = 0x18,
        P = 0x19,
        Q = 0x10,
        R = 0x13,
        S = 0x1F,
        T = 0x14,
        U = 0x16,
        V = 0x2F,
        W = 0x11,
        X = 0x2D,
        Y = 0x15,
        Z = 0x2C,
        Space = 0x39,
        LeftShift = 0x2A,
        LeftControl = 0x1D,
        LeftAlt = 0x38,
        Tab = 0x0F,
        Escape = 0x01,
        UpArrow = 0xC8,
        DownArrow = 0xD0,
        LeftArrow = 0xCB,
        RightArrow = 0xCD,
        Alpha1 = 0x02,
        Alpha2 = 0x03,
        Alpha3 = 0x04,
        Alpha4 = 0x05,
        Alpha5 = 0x06,
        Alpha6 = 0x07,
        Alpha7 = 0x08,
        Alpha8 = 0x09,
        Alpha9 = 0x0A,
        Alpha0 = 0x0B,
        F1 = 0x3B,
        F2 = 0x3C,
        F3 = 0x3D,
        F4 = 0x3E,
        F5 = 0x3F,
        F6 = 0x40,
        F7 = 0x41,
        F8 = 0x42,
        F9 = 0x43,
        F10 = 0X44,
        F11 = 0X57,
        F12 = 0X58,

        None = 512
    };

    static void update();
    //キーが押された瞬間
    static bool getKeyDown(KeyCode key);
    //キーが押され続けているか
    static bool getKey(KeyCode key);
    //キーが離れた瞬間
    static bool getKeyUp(KeyCode key);
    //縦横
    static int horizontal();
    static int vertical();

private:
    static KeyCode mCurrentKey; //現在のキーの状態
    static KeyCode mPreviousKey; //1フレーム前のキーの状態
};

