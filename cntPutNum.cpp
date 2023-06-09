//************************************************
// 現時点でP1とP2の駒が何個盤面に置かれているか数える
//************************************************
#include "define.h"

int cntPutNum(int puzzle[][4][4]) {
    int i, j, k;
    int cnt = 0;
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == P1 || puzzle[i][j][k] == P2) cnt++;
            }
        }
    }
    return cnt;
}