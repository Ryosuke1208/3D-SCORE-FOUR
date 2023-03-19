//************************************************
// CPUが最適解を見つける方法の詳細
//************************************************
#include "define.h"

boolean isDone(int[][4][4], int);
void findBestMove(int, int[][4][4], int*, int*, int*);
int isReach(int[][4][4], int);

boolean search(int depth, int puzzle[][4][4], int x, int y, int z) {
    int cnt1 = 0;
    int cnt2 = 0;
    boolean flg = false;
    int x2 = 0, y2 = 0, z2 = 0;
    int x3 = 0, y3 = 0, z3 = 0;
    // CPU側のビンゴ出来るときはそこで決定
    if (depth == 1) {
        puzzle[x][y][z] = P2;
        if (isDone(puzzle, P2)) {
            //printfDx("depth 1 発生\n");
            flg = true;
        }
        puzzle[x][y][z] = OK;
    }
    // プレイヤー側のビンゴになるときは阻止する手で決定
    else if (depth == 2) {
        puzzle[x][y][z] = P1;
        if (isDone(puzzle, P1)) {
            //printfDx("depth 2 発生\n");
            flg = true;
        }
        puzzle[x][y][z] = OK;
    }
    // CPUがおいてCPUのダブルリーチができ
    // かつプレイヤー側のリーチができないとき
    else if (depth == 3) {
        puzzle[x][y][z] = P2;
        if(x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P2) >= 2 && isReach(puzzle, P1) == 0) {
            //printfDx("depth 3 発生\n");
            flg = true;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // プレイヤーがおいてプレイヤーのダブルリーチを作れて、
    // かつそれを防ぐ手を置いたとして、プレイヤー側のリーチができないとき
    else if (depth == 4) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P1) >= 2 && isReach(puzzle, P2) == 0) {
            puzzle[x][y][z] = P2;
            if (isReach(puzzle, P1) == 0) {
                //printfDx("depth 4 発生\n"); 
                flg = true;
            }
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // CPUがおいてCPUのリーチを作れて、
    // それを防ぐ手をプレイヤーが置いたとして、
    // それでも、CPUのダブルリーチができるとき
    else if (depth == 5) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P2) >= 1 && isReach(puzzle, P1) == 0) {
            findBestMove(1, puzzle, &x2, &y2, &z2);
            puzzle[x2][y2][z2] = P1;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = OK;
            findBestMove(3, puzzle, &x3, &y3, &z3);
            if (x3 != 4) {
                //printfDx("depth 5 発生\n");
                flg = true;
            }
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // プレイヤーがおいて(一手目)プレイヤーのリーチを作れて、
    // CPUがそれを防ぐ手(二手目)を置いたとして
    // プレイヤーがおくと(三手目)ダブルリーチが出来てしまうとき
    // 一手目を防ぐ
    else if (depth == 6) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P1) >= 1 && isReach(puzzle, P2) == 0) {
            findBestMove(2, puzzle, &x2, &y2, &z2);
            puzzle[x2][y2][z2] = P2;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = OK;
            findBestMove(10, puzzle, &x3, &y3, &z3);
            if (x3 != 4) {
                //printfDx("depth 6 発生\n");
                flg = true;
            }
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // CPUが置く(一手目)→リーチができるのでそれを防ぐ(2手目)
    // →その上でリーチができてしまう時
    else if (depth == 7) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P2) >= 1 && isReach(puzzle, P1) == 0) {
            findBestMove(1, puzzle, &x2, &y2, &z2);
            puzzle[x2][y2][z2] = P1;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = OK;
            if (isReach(puzzle, P2)) {
                //printfDx("depth 7 発生\n");
                flg = true;
            }
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // プレイヤーが置く(一手目)→リーチができるのでそれを防ぐ(2手目)
    // →その上でリーチができてしまう時
    else if (depth ==  8) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P1) >= 1 && isReach(puzzle, P2) == 0) {
            findBestMove(2, puzzle, &x2, &y2, &z2);
            puzzle[x2][y2][z2] = P2;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = OK;
            if (isReach(puzzle, P1)) {
                //printfDx("depth 7 発生\n");
                flg = true;
            }
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // プレイヤーが置いた時にダブルリーチができる手
    // depth = 3とほぼ同じ　設計ミスにより作った
    else if (depth == 10) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P1) >= 2 && isReach(puzzle, P2) == 0)  flg = true;
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    
    if (flg) return true;
    else return false;
}

