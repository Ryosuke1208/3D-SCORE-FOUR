//************************************************
// �I��������Ԃ�\������
//************************************************
#include "define.h"

void showFinishedLine(int[][4][4], int, int, int[][3]);

boolean showFinishedStatus(int puzzle[][4][4], int m, int d, int p_num, int bingo[][3]) {
    while (1) {
        ClearDrawScreen();
        showFinishedLine(puzzle, m, p_num, bingo);
        SetFontSize(80);
        DrawString(450, 680, "FINISHED", BLACK);
        SetFontSize(40);
        DrawString(450, 750, "press enter", BLACK);
        if (m == 1) {// VS CPU�̎��͎��߂���悤�ɂ��Ă���
            if (CheckHitKey(KEY_INPUT_BACK)) return false;// BACK�L�[�Ŗ߂�
            else if (CheckHitKey(KEY_INPUT_RETURN)) return true;// ENTER�L�[�ŏI��
        }
        else {// VS�v���C���[�͂��̂܂܂����
            if (CheckHitKey(KEY_INPUT_RETURN)) return true;// ENTER�L�[�ŏI��
        }
        ScreenFlip();
    }
}