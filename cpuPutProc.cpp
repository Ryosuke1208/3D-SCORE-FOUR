//************************************************
// CPU‚ªŽè‚ð’u‚­ˆ—
//************************************************
#include "define.h"

void makeFigure(int[][4][4], int, int);
void findBestMove(int, int[][4][4], int*, int*, int*);
void difficultValue(int[][4][4], int*, int*, int*);

void cpuPutProc(int puzzle[][4][4], int d, int temp[][3]) {
    int x = 0, y = 0, z = 0;
    int depth = 1;
    while (1) {
        ClearDrawScreen();
        makeFigure(puzzle, 1, d);
        while (1) {
            findBestMove(depth, puzzle, &x, &y, &z);
            if (x != 4) break; // Å—Dæ‚·‚×‚«Žè‚ªŒ©‚Â‚©‚Á‚½ê‡‚Í‚»‚±‚Å”²‚¯‚é
            depth++;
            if (depth == 9) {
                //if (d == 0) easyValue(puzzle, &x, &y, &z);
                //else if (d == 1) normalValue(puzzle, &x, &y, &z);
                if (d == 2) difficultValue(puzzle, &x, &y, &z);
                break;
            }
        }
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        temp[1][0] = x;
        temp[1][1] = y;
        temp[1][2] = z;
        ScreenFlip();
        break;
    }
}