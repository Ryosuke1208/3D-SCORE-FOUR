//************************************************
// ���҂̕\��
//************************************************
#include "define.h"

void showWinPvP(int p_num) {
    WaitTimer(1000);// �O�̃G���^�[���͂Ɠ����ɓǂݎ��\��������̂ŏ����~�߂�
    unsigned int color;
    ClearDrawScreen();
    SetFontSize(100);
    if (p_num == P1) {
        color = LIGHT_RED;
        DrawString(103, 300, "PLAYER1�@WIN", color);
    }
    else {
        color = LIGHT_BLUE;
        DrawString(103, 300, "PLAYER2 WIN", color);
    }
    SetFontSize(50);
    DrawString(260, 500, "press enter", color);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}

void showWinPvC(int p_num) {
    WaitTimer(1000);// �O�̃G���^�[���͂Ɠ����ɓǂݎ��\��������̂ŏ����~�߂�
    unsigned int color;
    ClearDrawScreen();
    SetFontSize(100);
    if (p_num == P1) {
        color = LIGHT_RED;
        DrawString(103, 300, "PLAYER1�@WIN", color);
    }
    else {
        color = LIGHT_BLUE;
        DrawString(103, 300, "  CPU  WIN  ", color);
    }
    SetFontSize(50);
    DrawString(260, 500, "press enter", color);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}

void showDraw() {
    WaitTimer(1000);// �O�̃G���^�[���͂Ɠ����ɓǂݎ��\��������̂ŏ����~�߂�
    ClearDrawScreen();
    SetFontSize(100);
    DrawString(103, 300, "    DRAW    ", BLACK);
    SetFontSize(50);
    DrawString(260, 500, "press enter", BLACK);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}