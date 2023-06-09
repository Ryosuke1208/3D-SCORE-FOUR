//************************************************
// 期待値計算のプログラム
//************************************************
#include "define.h"

void evaluation(int puzzle[][4][4], int value[][4][4], int p_num) {
	int i, j, k;
	int x, y, z;
	int temp_score = 0;
	int e_num = 0;
	if (p_num == P2) e_num = P1;
	if (p_num == P1) e_num = P2;

	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					temp_score = value[i][j][k];
					// 立体での縦
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// 平面での縦
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// 平面での横
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == e_num) {
							temp_score--;
							break;
						}
					}
					// 左下から右上への平面での斜め
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// 一番下の左下から一番上右上への対角線
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// 一番下の右上から一番上左下への対角線
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// 左上から右下への平面での斜め
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// 一番下の左上から一番上の右下への対角線
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// 一番下の右下から一番上の左上への対角線
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// 縦平面（Ｙ軸）での斜め
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// 縦平面での斜め反対
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// 奥平面（Ｚ軸）での斜め
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// 奥平面での斜め反対
					if (i == j) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][x][k] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					value[i][j][k] = temp_score;
				}
			}
		}
	}
}
