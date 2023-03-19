//************************************************
// リーチになるマスを保存する
//************************************************
#include "define.h"

void reachArrayPush(int x, int y, int z, int reach_array[10][3]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (reach_array[i][0] == -1) {
			reach_array[i][0] = x;
			reach_array[i][1] = y;
			reach_array[i][2] = z;
			break;
		}
	}
}