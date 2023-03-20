//************************************************
// 15��܂ł̊�CPU���Q�l�ɂ���֐��B
// ���X�͎����ōl�����]���l�v�Z�������B
// ���������Ȃ��̂ŗ��p
//************************************************
#include "define.h"

boolean cpuCanPut(int[][4][4], int, int, int);
void evaluation(int[][4][4], int[][4][4], int);
int cntDangerLine(int[][4][4], int[][4][4], int, int[20][3]);

void chooseByValue(int puzzle[][4][4], int* x, int* y, int* z) {
    int i, j, k;
    int cnt;
    int max = -999;
    boolean flg = false;
    int arrayList[20][3];
    //�e�}�X�̕]���l �P���ɂ����ɒu�������̃r���S�ɂȂ蓾�鐔����ɂ��Ă���
    int value[4][4][4] =
    {
        {{30,4,4,30},{4,4,4,4},{4,4,4,4},{30,4,4,30}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    // 2�i�ڂ̕]���_�̕ύX
    for (j = 0; j < 4; j++) {
        if (puzzle[3][j][0] == P1) value[2][j][0] += 25;
        if (puzzle[3][j][3] == P1) value[2][j][3] += 25;
    }
    for (k = 0; k < 4; k++) {
        if (puzzle[3][0][k] == P1) value[2][0][k] += 25;
        if (puzzle[3][3][k] == P1) value[2][3][k] += 25;
    }
    // ���肪�j�̂Q�i�ڂɒu������R�i�ڂ͑��Ƃ�
    if (puzzle[2][1][1] == P1) value[1][1][1] += 50;
    if (puzzle[2][1][2] == P1) value[1][1][2] += 50;
    if (puzzle[2][2][1] == P1) value[1][2][1] += 50;
    if (puzzle[2][2][2] == P1) value[1][2][2] += 50;
    // ��i�ڎl���͓�ȏ�͎��
    cnt = 0;
    if (puzzle[3][0][0] == P2) cnt++;
    if (puzzle[3][0][3] == P2) cnt++;
    if (puzzle[3][3][0] == P2) cnt++;
    if (puzzle[3][3][3] == P2) cnt++;
    if (cnt <= 1) {
        value[3][0][0] += 100;
        value[3][0][3] += 100;
        value[3][3][0] += 100;
        value[3][3][3] += 100;
    }
    // �K�����h��
    for (j = 0; j < 4; j++) {
        cnt = 0;
        if (puzzle[3][j][0] == P1 && puzzle[3][j][3] == P1) cnt++;
        if (cnt) {
            if (puzzle[2][j][1] != P2 && puzzle[2][j][2] != P2 && puzzle[1][j][1] != P2 && puzzle[1][j][2] != P2) {
                value[2][j][1] += 25;
                value[2][j][2] += 25;
                value[1][j][1] += 25;
                value[1][j][2] += 25;
            }
        }
    }
    for (k = 0; k < 4; k++) {
        cnt = 0;
        if (puzzle[3][0][k] == P1 && puzzle[3][3][k] == P1) cnt++;
        if (cnt) {
            if (puzzle[2][1][k] != P2 && puzzle[2][2][k] != P2 && puzzle[1][1][k] != P2 && puzzle[1][2][k] != P2) {
                value[2][1][k] += 25;
                value[2][2][k] += 25;
                value[1][1][k] += 25;
                value[1][2][k] += 25;
            }
        }
    }
    cnt = 0;
    if (puzzle[3][0][0] == P1 && puzzle[3][3][3] == P1) cnt++;
    if (cnt) {
        if (puzzle[2][1][1] != P2 && puzzle[2][2][2] != P2 && puzzle[1][1][1] != P2 && puzzle[1][2][2] != P2) {
            value[2][1][1] += 25;
            value[2][2][2] += 25;
            value[1][1][1] += 25;
            value[1][2][2] += 25;
        }
    }
    cnt = 0;
    if (puzzle[3][3][0] == P1 && puzzle[3][0][3] == P1) cnt++;
    if (cnt) {
        if (puzzle[2][2][1] != P2 && puzzle[2][1][2] != P2 && puzzle[1][2][1] != P2 && puzzle[1][1][2] != P2) {
            value[2][2][1] += 25;
            value[2][1][2] += 25;
            value[1][2][1] += 25;
            value[1][1][2] += 25;
        }
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (puzzle[i][1][0] == P1) cnt++;
        if (puzzle[i][0][1] == P1) cnt++;
        if (puzzle[i][1][1] == P1) cnt++;
        if (puzzle[i][1][0] == P2) break;
        if (puzzle[i][0][1] == P2) break;
        if (puzzle[i][1][1] == P2) break;
        if (cnt >= 2) {
            value[i][1][0] += 100;
            value[i][0][1] += 100;
            value[i][1][1] += 100;
            value[i][0][0] += 100;
        }
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (puzzle[i][2][0] == P1) cnt++;
        if (puzzle[i][3][1] == P1) cnt++;
        if (puzzle[i][2][1] == P1) cnt++;
        if (puzzle[i][2][0] == P2) break;
        if (puzzle[i][3][1] == P2) break;
        if (puzzle[i][2][1] == P2) break;
        if (cnt >= 2) {
            value[i][2][0] += 100;
            value[i][3][1] += 100;
            value[i][2][1] += 100;
            value[i][3][0] += 100;
        }
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (puzzle[i][0][2] == P1) cnt++;
        if (puzzle[i][1][3] == P1) cnt++;
        if (puzzle[i][1][2] == P1) cnt++;
        if (puzzle[i][0][2] == P2) break;
        if (puzzle[i][1][3] == P2) break;
        if (puzzle[i][1][2] == P2) break;
        if (cnt >= 2) {
            value[i][0][2] += 100;
            value[i][1][3] += 100;
            value[i][1][2] += 100;
            value[i][0][3] += 100;
        }
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (puzzle[i][2][3] == P1) cnt++;
        if (puzzle[i][3][2] == P1) cnt++;
        if (puzzle[i][2][2] == P1) cnt++;
        if (puzzle[i][2][3] == P2) break;
        if (puzzle[i][3][2] == P2) break;
        if (puzzle[i][2][2] == P2) break;
        if (cnt >= 2) {
            value[i][2][3] += 100;
            value[i][3][2] += 100;
            value[i][2][2] += 100;
            value[i][3][3] += 100;
        }
    }

    // ��Ȃ����C��������΂����̕]���l���グ��
    if (cntDangerLine(puzzle, value, P2, arrayList)) {
        cnt = 0;
        while (arrayList[cnt][0] != -1) {
            value[arrayList[cnt][0]][arrayList[cnt][1]][arrayList[cnt][2]] += 25;
            cnt++;
        }
    }
    // �Ֆʂ̃��C�����ɂ��e�}�X�̕]���l����
    evaluation(puzzle, value, P2);
    value[1][0][0] = 1;
    value[1][0][3] = 1;
    value[1][3][0] = 1;
    value[1][3][3] = 1;

    /*******************************************************************************/
    // �]���l�̍����肪�����������͂�����Ԃ�
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (cpuCanPut(puzzle, i, j, k)) {
                        if (value[i][j][k] > max) {
                            max = value[i][j][k];
                            *x = i;
                            *y = j;
                            *z = k;
                            if (!flg) flg = true;
                        }
                    }
                }
            }
        }
    }
    // �����h�~�̂��߂̏���
    // ��{�ǂ��ɑł��Ă�������Ƃ��ɗ����͂�
    if (!flg) {
        for (i = 3; i >= 0; i--) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    if (puzzle[i][j][k] == OK) {
                        *x = i;
                        *y = j;
                        *z = k;
                    }
                }
            }
        }
    }
    return;
}