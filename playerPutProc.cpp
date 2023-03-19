//************************************************
// �v���C���[�����u���ۂ̏���
// �ق�Ƃ�VS�v���C���[��VSCPU�ŕ�����ׂ������A
// �߂�ǂ������̂ňꏏ�ɂ��Ă���
//************************************************
#include "define.h"

void makeFigure(int[][4][4], int, int);
boolean playerCanPut(int[][4][4], int*, int*, int*);
void fill(int, int, int, int);

boolean playerPutProc(int puzzle[][4][4], int p_num, int m, int d, int temp[][3]) {
    int click_x, click_y, button, log_type;
    int x = -1, y = -1, z = -1;
    while (1) {
        ClearDrawScreen();
        // �}�`�̍쐬�ƕ`��
        makeFigure(puzzle, m, d);
        // �}�X�ɒu����Ȃ�F��ς���
        if (playerCanPut(puzzle, &x, &y, &z)) fill(x, y, z, p_num);
        // �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
        if (!GetMouseInputLog2(&button, &click_x, &click_y, &log_type, TRUE)) {
            if ((button & MOUSE_INPUT_LEFT))
            {
                // ���N���b�N��������Ă��āA���ꂽ�u�Ԃɏ����m�肷��
                if (log_type == MOUSE_INPUT_LOG_UP) {
                    if (playerCanPut(puzzle, &x, &y, &z)) {
                        puzzle[x][y][z] = p_num;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        // VS CPU�̎��͒u�����}�X�̏����i�[
                        if (m == 1) {
                            temp[0][0] = x;
                            temp[0][1] = y;
                            temp[0][2] = z;
                        }
                        return true;
                    }
                }
            }
        }
        // VS CPU�̎��͈��߂���
        if (m == 1) {
            if (CheckHitKey(KEY_INPUT_BACK)) return false;
        }
        ScreenFlip();
    }
}