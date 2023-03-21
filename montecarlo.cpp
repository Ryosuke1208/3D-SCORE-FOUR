//************************************************
// モンテカルロ法を用いて勝率のいい手を探す
//************************************************
#include "define.h"

void arrayPush(int, int, int, int[20][3]);
boolean checkWinner(int[][4][4], int*);
int isReach(int[][4][4], int);

#define REVERSE(P_NUM) (P_NUM == P1 ? P2 : P1)

// check p_num can put or not
boolean putCheck(int puzzle[][4][4], int x, int y, int z, int p_num) {
	boolean flg = true;
	puzzle[x][y][z] = p_num;
	if (x > 0) puzzle[x - 1][y][z] = OK;
	if (isReach(puzzle, REVERSE(p_num))) flg = false;
	puzzle[x][y][z] = OK;
	if (x > 0) puzzle[x - 1][y][z] = NG;
	return flg;
}
// init array with all -1
void initArray(int array_list[20][3]) {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			array_list[i][j] = -1;
		}
	}
}
// copy original array to temp array
void copyArray(int puzzle[][4][4], int temp[][4][4]) {
	int x, y, z;
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			for (z = 0; z < 4; z++) {
				temp[x][y][z] = puzzle[x][y][z];
			}
		}
	}
}
// get finished result
double playOut(int winner) {
	if (winner == P2) return 1.;
	else if (winner == P1) return 0.;
	else return 0.5;
}
// two players play game until finish
boolean simulate_game(int temp_array[][4][4], int p_num, int *winner) {
	int x, y, z;
	int put_place = 0;
	int canPutCnt = 0; // 何個置ける場所があるのか
	int array_list[20][3];
	initArray(array_list);
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			for (z = 0; z < 4; z++) {
				if (temp_array[x][y][z] == OK) {
					if (putCheck(temp_array, x, y, z, p_num)) {
						// 空いてるマスの座標を何個置けるかを保存する
						arrayPush(x, y, z, array_list);
						canPutCnt++;
					}
				}
			}
		}
	}
	if (!canPutCnt) {// もう置けないとき→p_num側の負け
		*winner = REVERSE(p_num);
		return true;
	}
	put_place = GetRand(canPutCnt - 1); // 置く手をランダムに決定する
	temp_array[array_list[put_place][0]][array_list[put_place][1]][array_list[put_place][2]] = p_num;
	if(array_list[put_place][0] > 0)
		temp_array[array_list[put_place][0] - 1][array_list[put_place][1]][array_list[put_place][2]] = OK;
	if (checkWinner(temp_array, winner)) return true;
	else simulate_game(temp_array, REVERSE(p_num), winner);
}
// montecalro proc
void montecalro(int puzzle[][4][4], int p_num, int* i, int* j, int* k, int d) {
	int x, y, z;
	int m, n;
	int winner;
	double best_score = -999.;
	int best_score_cnt;
	int canPutCnt = 0; // 何個置ける場所があるのか
	int can_put_array[20][3];
	double values[20] = { 0 };
	double temp_score;
	int temp_array[4][4][4];
	int playout_num = 0;
	// 難易度の調整
	if (d == 0) playout_num = 100;
	else if (d == 1) playout_num = 1000;
	else if (d == 2) playout_num = 2500;
	initArray(can_put_array);
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			for (z = 0; z < 4; z++) {
				if (puzzle[x][y][z] == OK) {
					if (putCheck(puzzle, x, y, z, p_num)) {
						// 空いてるマスの座標を何個置けるかを保存する
						arrayPush(x, y, z, can_put_array);
						canPutCnt++;
					}
				}
			}
		}
	}
	if (!canPutCnt) {// 負け確処理
		for (x = 0; x < 4; x++) {
			for (y = 0; y < 4; y++) {
				for (z = 0; z < 4; z++) {
					if (puzzle[x][y][z] == OK) {
						*i = x;
						*j = y;
						*k = z;
						return;
					}
				}
			}
		}
	}
	for (m = 0; m < canPutCnt; m++) {
		temp_score = 0.;
		for (n = 0; n < playout_num; n++) {
			copyArray(puzzle, temp_array);
			temp_array[can_put_array[m][0]][can_put_array[m][1]][can_put_array[m][2]] = p_num;
			if (can_put_array[m][0] > 0)
				temp_array[can_put_array[m][0] - 1][can_put_array[m][1]][can_put_array[m][2]] = OK;
			while (1) {
				if (simulate_game(temp_array, p_num, &winner)) break;
			}
			temp_score += playOut(winner);
		}
		values[m] = temp_score / playout_num;
	}
	for (m = 0; m < canPutCnt; m++) {
		if (values[m] > best_score) {
			best_score = values[m];
			best_score_cnt = m;
		}
	}
	*i = can_put_array[best_score_cnt][0];
	*j = can_put_array[best_score_cnt][1];
	*k = can_put_array[best_score_cnt][2];
	printfDx("%f ", best_score);
}