//************************************************
// CPUが最適解を見つける方法の大枠
// searchに合致する座標が見つかった時は
// *xに4以外の値が入ってリターンされているはず
// 逆に言えば4が入っているときは座標が
// 見つからなかったということ
//************************************************
#include "define.h"

boolean search(int, int[][4][4], int, int, int);

void findBestMove(int depth, int puzzle[][4][4], int* x, int* y, int* z) {
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (search(depth, puzzle, i, j, k)) break; // 最優先すべき手を探す
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