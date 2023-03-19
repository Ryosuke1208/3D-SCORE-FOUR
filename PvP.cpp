//************************************************
// �v���C���[���m�ł̑ΐ�
//************************************************
#include "define.h"

boolean playerPutProc(int[][4][4], int, int, int, int[][3]);
boolean isDone(int[][4][4], int);
void getBingoLine(int[][4][4], int, int[][3]);
boolean showFinishedStatus(int[][4][4], int, int, int, int[][3]);
void showWinPvP(int);
boolean isDraw(int[][4][4]);
void showDraw();

void PvP() {
    int p_num = 0;
    int puzzle[4][4][4] = // �ŏ��͈�ԉ������u������
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    int bingo[4][3];// �r���S�ɂȂ����}�X�̊i�[�p
    int temp[2][3];// �u�����}�X�̏��̊i�[�p�iPvP�ł͎g��Ȃ��j
    // �Q�[������
    while (1) {
        // �v���C���[���o��������߂鏈��
        // VS�v���C���[�̎��͓�Փx�͓K����-1�����Ă���
        if (p_num % 2 == 0) playerPutProc(puzzle, (p_num % 2) + 1, 0, -1, temp);
        else playerPutProc(puzzle, (p_num % 2) + 1, 0, -1, temp);
        // �r���S�ɂȂ������ǂ����̃`�F�b�N
        if (isDone(puzzle, (p_num % 2) + 1)) {
            getBingoLine(puzzle, (p_num % 2) + 1, bingo);
            showFinishedStatus(puzzle, 0, -1, (p_num % 2) + 1, bingo);
            showWinPvP((p_num % 2) + 1);
            break;
        }
        if (isDraw(puzzle)) {
            bingo[0][0] = -1;
            showFinishedStatus(puzzle, 0, -1, (p_num % 2) + 1, bingo);
            showDraw();
            break;
        }
        p_num++;
    }
}