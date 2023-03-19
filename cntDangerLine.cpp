//************************************************
// あるライン上で相手が２マスおいていて
// かつ自分のマスがない箇所を配列に入れて返す
//************************************************
#include "define.h"

void arrayPush(int, int, int, int[20][3]);

int cntDangerLine(int puzzle[][4][4], int value[][4][4], int playerNumber, int arrayList[20][3]) {
	int i, j, k;
	int x, y, z;
	int enemyNumber = 0;
	int cnt = 0;
	int returnCnt = 0;//　1列の中に相手のマスが２つあり、かつ自分のマスが１つもないマスの数を返す
	if (playerNumber == P2) enemyNumber = P1;
	if (playerNumber == P1) enemyNumber = P2;
	// 配列の初期化
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			arrayList[i][j] = -1;
		}
	}
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					// 立体での縦
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == enemyNumber) {
							cnt++;
						}
						if (puzzle[x][j][k] == playerNumber) {
							//if (puzzle[x][j][k] == playerNumber || puzzle[x][j][k] == NG) {
							cnt = 0;
							break;
						}
					}
					//　もし危険なラインなら座標を保存
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// 平面での縦
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == enemyNumber) {
							cnt++;
						}
						if (puzzle[i][y][k] == playerNumber) {
							//if (puzzle[i][y][k] == playerNumber || puzzle[i][y][k] == NG) {
							cnt = 0;
							break;
						}
					}
					//　もし危険なラインなら座標を保存
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// 平面での横
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == enemyNumber) {
							cnt++;
						}
						if (puzzle[i][j][z] == playerNumber) {
							//if (puzzle[i][j][z] == playerNumber || puzzle[i][j][z] == NG) {
							cnt = 0;
							break;
						}
					}
					//　もし危険なラインなら座標を保存
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// 左下から右上への平面での斜め
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == enemyNumber) {
								cnt++;
							}
							if (puzzle[i][z][z] == playerNumber) {
								//if (puzzle[i][z][z] == playerNumber || puzzle[i][z][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
						// 一番下の左下から一番上右上への対角線
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == enemyNumber) {
									cnt++;
								}
								if (puzzle[x][y][y] == playerNumber) {
									//if (puzzle[x][y][y] == playerNumber || puzzle[x][y][y] == NG) {
									cnt = 0;
									break;
								}
							}
							//　もし危険なラインなら座標を保存
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
						// 一番下の右上から一番上左下への対角線
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == enemyNumber) {
									cnt++;
								}
								if (puzzle[x][x][x] == playerNumber) {
									//if (puzzle[x][x][x] == playerNumber || puzzle[x][x][x] == NG) {
									cnt = 0;
									break;
								}
							}
							//　もし危険なラインなら座標を保存
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
					}
					// 左上から右下への平面での斜め
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == enemyNumber) {
								cnt++;
							}
							if (puzzle[i][y][z] == playerNumber) {
								//if (puzzle[i][y][z] == playerNumber || puzzle[i][y][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
						// 一番下の左上から一番上の右下への対角線
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == enemyNumber) {
									cnt++;
								}
								if (puzzle[x][x][z] == playerNumber) {
									//if (puzzle[x][x][z] == playerNumber || puzzle[x][x][z] == NG) {
									cnt = 0;
									break;
								}
							}
							//　もし危険なラインなら座標を保存
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
						// 一番下の右下から一番上の左上への対角線
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == enemyNumber) {
									cnt++;
								}
								if (puzzle[x][y][x] == playerNumber) {
									//if (puzzle[x][y][x] == playerNumber || puzzle[x][y][x] == NG) {
									cnt = 0;
									break;
								}
							}
							//　もし危険なラインなら座標を保存
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
					}
					// 縦平面（Ｙ軸）での斜め
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == enemyNumber) {
								cnt++;
							}
							if (puzzle[x][j][z] == playerNumber) {
								//if (puzzle[x][j][z] == playerNumber || puzzle[x][j][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// 縦平面での斜め反対
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == enemyNumber) {
								cnt++;
							}
							if (puzzle[x][j][x] == playerNumber) {
								//if (puzzle[x][j][x] == playerNumber || puzzle[x][j][x] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// 奥平面（Ｚ軸）での斜め
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == enemyNumber) {
								cnt++;
							}
							if (puzzle[x][y][k] == playerNumber) {
								//if (puzzle[x][y][k] == playerNumber || puzzle[x][y][k] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// 奥平面での斜め反対
					if (i == j) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][x][k] == enemyNumber) {
								cnt++;
							}
							if (puzzle[x][x][k] == playerNumber) {
								//if (puzzle[x][x][k] == playerNumber || puzzle[x][x][k] == NG) {
								cnt = 0;
								break;
							}
						}
						//　もし危険なラインなら座標を保存
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
				}
			}
		}
	}
	return returnCnt;
}