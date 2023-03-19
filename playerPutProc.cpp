//************************************************
// プレイヤーが手を置く際の処理
// ほんとはVSプレイヤーとVSCPUで分けるべきだが、
// めんどくさいので一緒にしている
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
        // 図形の作成と描画
        makeFigure(puzzle, m, d);
        // マスに置けるなら色を変える
        if (playerCanPut(puzzle, &x, &y, &z)) fill(x, y, z, p_num);
        // マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
        if (!GetMouseInputLog2(&button, &click_x, &click_y, &log_type, TRUE)) {
            if ((button & MOUSE_INPUT_LEFT))
            {
                // 左クリックが押されていて、離れた瞬間に情報を確定する
                if (log_type == MOUSE_INPUT_LOG_UP) {
                    if (playerCanPut(puzzle, &x, &y, &z)) {
                        puzzle[x][y][z] = p_num;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        // VS CPUの時は置いたマスの情報を格納
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
        // VS CPUの時は一手戻せる
        if (m == 1) {
            if (CheckHitKey(KEY_INPUT_BACK)) return false;
        }
        ScreenFlip();
    }
}