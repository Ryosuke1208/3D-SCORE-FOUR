//************************************************
// その時点でリーチになっている本数を数える
// また、その座標の格納とチェックまで
// 殴り書き ひどい
//************************************************
#include "define.h"

void reachArrayPush(int, int, int, int[10][3]);

int isReach(int puzzle[][4][4], int p_num) {
	int x, y, z;
	int i, j;
	int cnt1, cnt2;
	int reach = 0; // リーチの数

	int reach_array[10][3]; // リーチになり得るマスを保存する配列 多めにしている
	// 配列の初期化
	for (i = 0; i < 10; i++) {
		reach_array[i][0] = -1;
		reach_array[i][1] = -1;
		reach_array[i][2] = -1;
	}
	// リーチのチェック
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {// 一面ごとを平面に見たときの横線のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[x][y][i] == p_num) cnt1++;
				if (puzzle[x][y][i] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[x][y][i] == OK) reachArrayPush(x, y, i, reach_array);
				}
				reach++;
			}
		}
		for (z = 0; z < 4; z++) {// 一面ごとを平面に見たときの縦線のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[x][i][z] == p_num) cnt1++;
				if (puzzle[x][i][z] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[x][i][z] == OK) reachArrayPush(x, i, z, reach_array);
				}
				reach++;
			}
		}
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[x][i][i] == p_num) cnt1++;
			if (puzzle[x][i][i] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[x][i][i] == OK) reachArrayPush(x, i, i, reach_array);
			}
			reach++;
		}
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[x][3 - i][i] == p_num) cnt1++;
			if (puzzle[x][3 - i][i] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[x][3 - i][i] == OK) reachArrayPush(x, 3 - i, i, reach_array);
			}
			reach++;
		}
	}
	for (y = 0; y < 4; y++) {// 四面を立体に見たときの横軸の左上から右下へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][y][i] == p_num) cnt1++;
			if (puzzle[i][y][i] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][y][i] == OK) reachArrayPush(i, y, i, reach_array);
			}
			reach++;
		}
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][y][3 - i] == p_num) cnt1++;
			if (puzzle[i][y][3 - i] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][y][3 - i] == OK) reachArrayPush(i, y, 3 - i, reach_array);
			}
			reach++;
		}
	}
	for (z = 0; z < 4; z++) {// 四面を立体に見たときの縦軸の手前から奥へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][i][z] == p_num) cnt1++;
			if (puzzle[i][i][z] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][i][z] == OK) reachArrayPush(i, i, z, reach_array);
			}
			reach++;
		}
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][3 - i][z] == p_num) cnt1++;
			if (puzzle[i][3 - i][z] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][3 - i][z] == OK) reachArrayPush(i, 3 - i, z, reach_array);
			}
			reach++;
		}
	}
	for (y = 0; y < 4; y++) {
		for (z = 0; z < 4; z++) {// 四面を立体に見たときの高さの縦のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[i][y][z] == p_num) cnt1++;
				if (puzzle[i][y][z] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[i][y][z] == OK) reachArrayPush(i, y, z, reach_array);
				}
				reach++;
			}
		}
	}
	// 立体的な視点での斜めのチェック
	cnt1 = 0;
	cnt2 = 0;
	for (i = 0; i < 4; i++) {
		if (puzzle[i][i][i] == p_num) cnt1++;
		if (puzzle[i][i][i] == OK) cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 1) {
		for (i = 0; i < 4; i++) {
			if (puzzle[i][i][i] == OK) reachArrayPush(i, i, i, reach_array);
		}
		reach++;
	}
	cnt1 = 0;
	cnt2 = 0;
	for (i = 0; i < 4; i++) {
		if (puzzle[i][3 - i][3 - i] == p_num) cnt1++;
		if (puzzle[i][3 - i][3 - i] == OK) cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 1) {
		for (i = 0; i < 4; i++) {
			if (puzzle[i][3 - i][3 - i] == OK) reachArrayPush(i, 3 - i, 3 - i, reach_array);
		}
		reach++;
	}
	cnt1 = 0;
	cnt2 = 0;
	for (i = 0; i < 4; i++) {
		if (puzzle[i][3 - i][i] == p_num) cnt1++;
		if (puzzle[i][3 - i][i] == OK) cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 1) {
		for (i = 0; i < 4; i++) {
			if (puzzle[i][3 - i][i] == OK) reachArrayPush(i, 3 - i, i, reach_array);
		}
		reach++;
	}
	cnt1 = 0;
	cnt2 = 0;
	for (i = 0; i < 4; i++) {
		if (puzzle[i][i][3 - i] == p_num) cnt1++;
		if (puzzle[i][i][3 - i] == OK) cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 1) {
		for (i = 0; i < 4; i++) {
			if (puzzle[i][i][3 - i] == OK) reachArrayPush(i, i, 3 - i, reach_array);
		}
		reach++;
	}
	// 実質複数リーチでない複数リーチ（1マス防げばどっちのラインも防げる）の判別
	// 理論上セブンリーチまではあり得るが、ダブルリーチ以上はめったに起こらないとおもう
	for (i = 0; i < 10; i++) {
		if (reach_array[i][0] != -1) {
			for (j = i + 1; j < 10; j++) {
				if (reach_array[j][0] != -1) {
					if (reach_array[i][0] == reach_array[j][0] &&
						reach_array[i][1] == reach_array[j][1] &&
						reach_array[i][2] == reach_array[j][2]) {
						reach--;
						reach_array[j][0] = -1;
						reach_array[j][1] = -1;
						reach_array[j][2] = -1;
					}
				}
			}
		}
	}
	return reach;
}