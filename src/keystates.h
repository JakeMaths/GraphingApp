#pragma once

#include "header.h"

struct KeyStates {
    bool keyA = false;
    bool keyB = false;
    bool keyC = false;
    bool keyD = false;
    bool keyE = false;
    bool keyF = false;
    bool keyG = false;
    bool keyH = false;
    bool keyI = false;
    bool keyJ = false;
    bool keyK = false;
    bool keyL = false;
    bool keyM = false;
    bool keyN = false;
    bool keyO = false;
    bool keyP = false;
    bool keyQ = false;
    bool keyR = false;
    bool keyS = false;
    bool keyT = false;
    bool keyU = false;
    bool keyV = false;
    bool keyW = false;
    bool keyX = false;
    bool keyY = false;
    bool keyZ = false;
    bool key1 = false;
    bool key2 = false;
    bool key3 = false;
    bool key4 = false;
    bool key5 = false;
    bool key6 = false;
    bool key7 = false;
    bool key8 = false;
    bool key9 = false;
    bool key0 = false;
    bool keyPeriod = false;
    bool keySlash = false;
    bool keyComma = false;
    bool keyBackSpace = false;
    bool keySpace = false;
    bool keyUp = false;
    bool keyDown = false;
    bool keyRight = false;
    bool keyLeft = false;
    bool keyEqual = false;
    bool keyHyphen = false;
    bool keyShift = false;
    bool mouse1press = false;
    bool mouse2press = false;
    bool mouse3press = false;
    float clickposx = 0;
    float clickposy = 0;
    float mousescrolldelta = 0;
};

void addKeyToText(KeyStates keyStates, sf::Text& inputText);