#include "input.h"
#include "DxLib.h"

static char key[256];
static char prev[256];

void InputUpdate() {
    for (int i = 0; i < 256; i++) prev[i] = key[i];
    GetHitKeyStateAll(key);
    GetJoypadInputState(DX_INPUT_PAD1);
}

bool InputPress(int k) {
    return key[k] != 0;
}

bool InputTrigger(int k) {
    return key[k] && !prev[k];
}