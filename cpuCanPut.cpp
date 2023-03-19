//************************************************
// CPU‚ª’u‚­Žè‚ª–â‘è‚È‚¢‚©’²‚×‚é
//************************************************
#include "define.h"

int isReach(int[][4][4], int);
void findBestMove(int, int[][4][4], int*, int*, int*);

boolean cpuCanPut(int puzzle[][4][4], int x, int y, int z) {
	boolean flg = true;
	int x2, y2, z2;
	puzzle[x][y][z] = P2;
	if (x > 0) puzzle[x - 1][y][z] = OK;
	if (isReach(puzzle, P1)) flg = false;
	else {
		findBestMove(10, puzzle, &x2, &y2, &z2);
		if (x2 != 4) flg = false;
	}
	puzzle[x][y][z] = OK;
	if (x > 0) puzzle[x - 1][y][z] = NG;
	return flg;
}