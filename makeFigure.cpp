//************************************************
// 4�~4�~4�̐}�`�̍쐬
//************************************************
#include "define.h"

void fill(int, int, int, int);

void makeFigure(int puzzle[][4][4], int m, int d) {
    static int i, j, k;
    SetFontSize(80);
    // �}�`�̕\��
    for (i = 0; i < 4; i++) {// 4�̐}�`
        for (j = 0; j < LINE_NUM; j++) {// ���̃��C��
            DrawLineAA((float)(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
        for (j = 0; j < LINE_NUM; j++) {// �c�̃��C��
            DrawLineAA((float)(LINE_START_X + j * LINE_COL_W), (float)(LINE_START_Y + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W), (float)(LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
    }
    // �F�h��
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] != NG) {
                    fill(i, j, k, puzzle[i][j][k]);
                }
            }
        }
    }
    // �v���C���[�h�̕\��
    if (m == 1) {
        DrawString(50, 700, "VS CPU", BLACK);
        // ��Փx�̕\��
        if (d == 0) {
            DrawString(400, 700, "EASY", BLACK);
        }
        else if (d == 1) {
            DrawString(400, 700, "NORMAL", BLACK);
        }
        else if (d == 2) {
            DrawString(400, 700, "DIFFICULT", BLACK);
        }
    }
    else {
        DrawString(50, 700, "VS ��ڲ԰", BLACK);
    }
}