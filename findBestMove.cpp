//************************************************
// CPU���œK������������@�̑�g
// search�ɍ��v������W��������������
// *x��4�ȊO�̒l�������ă��^�[������Ă���͂�
// �t�Ɍ�����4�������Ă���Ƃ��͍��W��
// ������Ȃ������Ƃ�������
//************************************************
#include "define.h"

boolean search(int, int[][4][4], int, int, int);

void findBestMove(int depth, int puzzle[][4][4], int* x, int* y, int* z) {
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (search(depth, puzzle, i, j, k)) break; // �ŗD�悷�ׂ����T��
                }
            }
            if (k != 4) break;
        }
        if (j != 4) break;
    }

    *x = i;
    *y = j;
    *z = k;
}