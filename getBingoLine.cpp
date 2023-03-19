//************************************************
// ビンゴになっているラインを返す
// 後付けでめんどいのでisDoneを流用
//************************************************
#include "define.h"

void getBingoLine(int puzzle[][4][4], int p_num, int bingo[][3]) {
	int x, y, z;
	int i;
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			if (puzzle[x][y][0] == p_num && puzzle[x][y][1] == p_num &&
				puzzle[x][y][2] == p_num && puzzle[x][y][3] == p_num) {
				for (i = 0; i < 4; i++) {
					bingo[i][0] = x;
					bingo[i][1] = y;
					bingo[i][2] = i;
				}
				return;
			}
		}
		for (z = 0; z < 4; z++) {
			if (puzzle[x][0][z] == p_num && puzzle[x][1][z] == p_num &&
				puzzle[x][2][z] == p_num && puzzle[x][3][z] == p_num) {
				for (i = 0; i < 4; i++) {
					bingo[i][0] = x;
					bingo[i][1] = i;
					bingo[i][2] = z;
				}
				return;
			}
		}
		if (puzzle[x][0][0] == p_num && puzzle[x][1][1] == p_num &&
			puzzle[x][2][2] == p_num && puzzle[x][3][3] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = x;
				bingo[i][1] = i;
				bingo[i][2] = i;
			}
			return;
		}
		if (puzzle[x][3][0] == p_num && puzzle[x][2][1] == p_num &&
			puzzle[x][1][2] == p_num && puzzle[x][0][3] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = x;
				bingo[i][1] = 3 - i;
				bingo[i][2] = i;
			}
			return;
		}
	}
	for (y = 0; y < 4; y++) {
		if (puzzle[0][y][0] == p_num && puzzle[1][y][1] == p_num &&
			puzzle[2][y][2] == p_num && puzzle[3][y][3] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = i;
				bingo[i][1] = y;
				bingo[i][2] = i;
			}
			return;
		}
		if (puzzle[0][y][3] == p_num && puzzle[1][y][2] == p_num &&
			puzzle[2][y][1] == p_num && puzzle[3][y][0] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = i;
				bingo[i][1] = y;
				bingo[i][2] = 3 - i;
			}
			return;
		}
	}
	for (z = 0; z < 4; z++) {
		if (puzzle[0][0][z] == p_num && puzzle[1][1][z] == p_num &&
			puzzle[2][2][z] == p_num && puzzle[3][3][z] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = i;
				bingo[i][1] = i;
				bingo[i][2] = z;
			}
			return;
		}
		if (puzzle[0][3][z] == p_num && puzzle[1][2][z] == p_num &&
			puzzle[2][1][z] == p_num && puzzle[3][0][z] == p_num) {
			for (i = 0; i < 4; i++) {
				bingo[i][0] = i;
				bingo[i][1] = 3 - i;
				bingo[i][2] = z;
			}
			return;
		}
	}
	for (y = 0; y < 4; y++) {
		for (z = 0; z < 4; z++) {
			if (puzzle[0][y][z] == p_num && puzzle[1][y][z] == p_num &&
				puzzle[2][y][z] == p_num && puzzle[3][y][z] == p_num) {
				for (i = 0; i < 4; i++) {
					bingo[i][0] = i;
					bingo[i][1] = y;
					bingo[i][2] = z;
				}
				return;
			}
		}
	}
	// 立体的な視点での斜めのチェック
	if (puzzle[0][0][0] == p_num && puzzle[1][1][1] == p_num &&
		puzzle[2][2][2] == p_num && puzzle[3][3][3] == p_num) {
		for (i = 0; i < 4; i++) {
			bingo[i][0] = i;
			bingo[i][1] = i;
			bingo[i][2] = i;
		}
		return;
	}
	if (puzzle[0][3][3] == p_num && puzzle[1][2][2] == p_num &&
		puzzle[2][1][1] == p_num && puzzle[3][0][0] == p_num) {
		for (i = 0; i < 4; i++) {
			bingo[i][0] = i;
			bingo[i][1] = 3 - i;
			bingo[i][2] = 3 - i;
		}
		return;
	}
	if (puzzle[0][3][0] == p_num && puzzle[1][2][1] == p_num &&
		puzzle[2][1][2] == p_num && puzzle[3][0][3] == p_num) {
		for (i = 0; i < 4; i++) {
			bingo[i][0] = i;
			bingo[i][1] = 3 - i;
			bingo[i][2] = i;
		}
		return;
	}
	if (puzzle[0][0][3] == p_num && puzzle[1][1][2] == p_num &&
		puzzle[2][2][1] == p_num && puzzle[3][3][0] == p_num) {
		for (i = 0; i < 4; i++) {
			bingo[i][0] = i;
			bingo[i][1] = i;
			bingo[i][2] = 3 - i;
		}
		return;
	}
	return;
}