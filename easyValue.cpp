//************************************************
// CPUの強さ「弱い」の評価関数
// 弱いよ
//************************************************
#include "define.h"

boolean cpuCanPut(int[][4][4], int, int, int);
void evaluation(int[][4][4], int[][4][4], int);

void easyValue(int puzzle[][4][4], int* x, int* y, int* z) {
    int i, j, k;
    int cnt;
    int max = -999;
    boolean flg = false;
    //各マスの評価値 単純にそこに置いた時のビンゴになり得る数を基にしている
    int value[4][4][4] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    
    // 一段目四隅は二つ以上は取る
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

    // 盤面のライン数による各マスの評価値増減
    evaluation(puzzle, value, P2);
    value[1][0][0] = 1;
    value[1][0][3] = 1;
    value[1][3][0] = 1;
    value[1][3][3] = 1;

    /*******************************************************************************/
    // 評価値の高い手が見つかった時はそこを返す
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
    // 抜け防止のための処理
    // 基本どこに打っても負けるときに流れるはず
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