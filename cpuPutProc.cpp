//************************************************
// CPU‚ªè‚ğ’u‚­ˆ—
//************************************************
#include "define.h"

void makeFigure(int[][4][4], int, int);
void findBestMove(int, int[][4][4], int*, int*, int*);
void montecalro(int[][4][4], int, int*, int*, int*, int);
void easyValue(int[][4][4], int*, int*, int*);
void chooseByValue(int[][4][4], int*, int*, int*);
int cntPutNum(int[][4][4]);

void cpuPutProc(int puzzle[][4][4], int d, int temp[][3]) {
    int x = 0, y = 0, z = 0;
    int depth = 1;
    while (1) {
        ClearDrawScreen();
        makeFigure(puzzle, 1, d);
        while (1) {
            findBestMove(depth, puzzle, &x, &y, &z);
            if (x != 4) break; // Å—Dæ‚·‚×‚«è‚ªŒ©‚Â‚©‚Á‚½ê‡‚Í‚»‚±‚Å”²‚¯‚é
            depth++;
            if (d == 0 && depth == 3) {
                easyValue(puzzle, &x, &y, &z);
                break;
            }
            if (d == 1 && depth == 5) {
                if (cntPutNum(puzzle) < 12) {
                    chooseByValue(puzzle, &x, &y, &z);
                    break;
                }
                else {
                    montecalro(puzzle, P2, &x, &y, &z, d);
                    break;
                }
            }
            if (d == 2 && depth == 7) {
                if (cntPutNum(puzzle) < 12) {
                    chooseByValue(puzzle, &x, &y, &z);
                    break;
                }
                else {
                    montecalro(puzzle, P2, &x, &y, &z, d);
                    break;
                }
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