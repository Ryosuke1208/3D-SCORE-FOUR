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
    int x4 = 0, y4 = 0, z4 = 0;
    // CPU側のビンゴが出来るときはそこで決定
    if (depth == 1) {
        puzzle[x][y][z] = P2;
        if (isDone(puzzle, P2)) flg = true;
        puzzle[x][y][z] = OK;
    }
    // プレイヤー側のビンゴになるときは阻止する手で決定
    else if (depth == 2) {
        puzzle[x][y][z] = P1;
        if (isDone(puzzle, P1)) flg = true;
        puzzle[x][y][z] = OK;
    }
    // CPUが置く→CPUのダブルリーチができて
    // かつプレイヤー側にリーチができないとき
    else if (depth == 3) {
        puzzle[x][y][z] = P2;
        if(x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P2) >= 2 && isReach(puzzle, P1) == 0) flg = true;
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // プレイヤーが置く→プレイヤーのダブルリーチができる、
    // かつそれを防ぐ手を置いたとして、プレイヤー側のリーチができないとき
    else if (depth == 4) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P1) >= 2 && isReach(puzzle, P2) == 0) {
            puzzle[x][y][z] = P2;
            if (isReach(puzzle, P1) == 0) flg = true;
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
            if (x3 != 4) flg = true;
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
    // CPUが置く(1手目)→リーチができるのでそれを防ぐ(2手目)
    // →その上でリーチができてしまう時
    else if (depth == 6) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        if (isReach(puzzle, P2) >= 1 && isReach(puzzle, P1) == 0) {
            findBestMove(1, puzzle, &x2, &y2, &z2);
            puzzle[x2][y2][z2] = P1;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = OK;
            if (isReach(puzzle, P2) >= 1 && isReach(puzzle, P1) == 0) flg = true;
            puzzle[x2][y2][z2] = OK;
            if (x2 > 0) puzzle[x2 - 1][y2][z2] = NG;
        }
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }
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

