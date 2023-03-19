//************************************************
// マウスのXYZ座標を取得し、
// そこに置ける状態かを取得
// 一番上の図形の左下の図形の座標を{0,0,0}として、
// 縦軸がX座標、奥行きの軸がY座標、右向きの軸がZ座標
// とする(あくまで図形上のXYZ座標であり
// マウスのXY座標の概念とは違う)
//************************************************
#include "define.h"

boolean playerCanPut(int puzzle[][4][4], int* x, int* y, int* z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouse_x, mouse_y;

    GetMousePoint(&mouse_x, &mouse_y);
    // そもそもマウスのY座標が図形の範囲内にあるかどうかの判定(マジックナンバーあり)
    if (mouse_y < LINE_START_Y - (LINE_ROW_H * 4) || // 一番上の図形の上
        (mouse_y > LINE_START_Y && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // 1番目と2番目の図形の間
        (mouse_y > LINE_START_Y + FIGURE_INTERVAL * 1 && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // 2番目と3番目の図形の間
        (mouse_y > LINE_START_Y + FIGURE_INTERVAL * 2 && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // 3番目と一番下の図形の間
        mouse_y > LINE_START_Y + FIGURE_INTERVAL * 3) return false; // 一番下の図形の下

    for (i = 0; i < 4; i++) { // 図形上のX座標の決定
        if (mouse_y < LINE_START_Y + i * FIGURE_INTERVAL && mouse_y > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) X = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * X - mouse_y) / LINE_ROW_H; // 図形上のY座標の決定
    // そもそもマウスのX座標が図形の範囲内にあるかどうかの判定
    if (mouse_x < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouse_x > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return false;
    }
    Z = (mouse_x - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W; // 図形上のX座標の決定
    // 図形上のひし形の一つ一つの図形の斜めになっている部分のZ座標の調整
    // 接戦の傾きを求めて、Z座標を＋－している
    if (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H) <= mouse_x && mouse_x <= LINE_START_X + LINE_COL_W * Z + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H)
        && (float)(mouse_x - (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H))
        <= (float)(LINE_START_Y + FIGURE_INTERVAL * X - (Y * LINE_ROW_H)) - mouse_y) Z--;
    // XYZが適正値なら返却
    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3 && puzzle[X][Y][Z] == OK) {
        *x = X;
        *y = Y;
        *z = Z;
        return true; // 置くことが出来るときはXYZ座標をセットしてtrueを返却する
    }
    else return false;
}
