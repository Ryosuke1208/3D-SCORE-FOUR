//************************************************
// 4×4×4の図形の作成＋ビンゴラインの作成
// makeFigureとほとんど変わらないが、
// 設計をミスったため作成
//************************************************
#include "define.h"

void fill(int, int, int, int);

void showFinishedLine(int puzzle[][4][4], int m, int p_num, int bingo[][3]) {
    static int i, j, k;
    SetFontSize(80);
    // 図形の表示
    for (i = 0; i < 4; i++) {// 4つの図形
        for (j = 0; j < LINE_NUM; j++) {// 横のライン
            DrawLineAA((float)(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
        for (j = 0; j < LINE_NUM; j++) {// 縦のライン
            DrawLineAA((float)(LINE_START_X + j * LINE_COL_W), (float)(LINE_START_Y + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W), (float)(LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
    }
    // 色塗り
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] != NG) {
                    fill(i, j, k, puzzle[i][j][k]);
                }
            }
        }
    }
    // DRAWのときは-1が入っているので表示しない
    if (bingo[0][0] != -1) {
        // ビンゴのラインの色を変える
        for (i = 0; i < 4; i++) {
            if (p_num == P1) fill(bingo[i][0], bingo[i][1], bingo[i][2], BINGO_P1);
            else fill(bingo[i][0], bingo[i][1], bingo[i][2], BINGO_P2);
        }
    }
    if (m == 1) {
        DrawString(50, 700, "VS CPU", BLACK);
    }
    else {
        DrawString(50, 700, "VS ﾌﾟﾚｲﾔｰ", BLACK);
    }
}