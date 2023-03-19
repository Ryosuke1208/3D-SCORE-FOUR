//************************************************
// �R���s���[�^�[�Ƃ̑ΐ�
//************************************************
#include "define.h"

boolean playerPutProc(int[][4][4], int, int, int, int[][3]);
void cpuPutProc(int[][4][4], int, int[][3]);
boolean isDone(int[][4][4], int);
void getBingoLine(int[][4][4], int, int[][3]);
boolean showFinishedStatus(int[][4][4], int, int, int, int[][3]);
void showWinPvC(int);
boolean isDraw(int[][4][4]);
void showDraw();

void PvC(int d, int o) {
    // �v���C���[���A0�Ő�s�E1�Ō�U
    int p_num;
    if (o == 0) p_num = 0;
    else p_num = 1;
    int puzzle[4][4][4] = // �ŏ��͈�ԉ������u������
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    int bingo[4][3] = { 0 };// �r���S�ɂȂ����}�X�̊i�[�p �Ƃ肠����0�ŏ�����
    int temp[2][3] = { {-1,-1,-1}, {-1,-1,-1} };// ���߂��p�̔z�� -1�ŏ�����
    // �Q�[������
    while (1) {
        if (p_num % 2 == 0) {
            while (1) {
                if (playerPutProc(puzzle, (p_num % 2) + 1, 1, d, temp)) break;
                else {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                        temp[0][0] = -1;
                    }
                }
            }
        }
        else cpuPutProc(puzzle, d, temp);
        // �r���S�ɂȂ������ǂ����̃`�F�b�N
        if (isDone(puzzle, (p_num % 2) + 1)) {
            getBingoLine(puzzle, (p_num % 2) + 1, bingo);
            // BACK�L�[�ň��߂�
            if (!showFinishedStatus(puzzle, 1, d, (p_num % 2) + 1, bingo)) {
                // �v���C���[������������CPU�����������Ŗ߂������Ⴄ
                if (p_num % 2 == 0) {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        temp[0][0] = -1;
                        continue;
                    }
                }
                else {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                        temp[0][0] = -1;
                        p_num--;
                        continue;
                    }
                }
            }
            showWinPvC((p_num % 2) + 1);
            break;
        }
        // �h���[�ɂȂ������ǂ����̃`�F�b�N
        if (isDraw(puzzle)) {
            bingo[0][0] = -1;
            showFinishedStatus(puzzle, 1, d, (p_num % 2) + 1, bingo);
            showDraw();
            break;
        }
        p_num++;
    }
}



