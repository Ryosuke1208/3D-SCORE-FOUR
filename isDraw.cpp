//************************************************
// ドローかどうかのチェック
//************************************************
#include "define.h"

boolean isDraw(int puzzle[][4][4]) {
    int i, j, k;
    // おける箇所がない時はtrueを返す
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    return false;
                }
            }
        }
    }
    return true;
}