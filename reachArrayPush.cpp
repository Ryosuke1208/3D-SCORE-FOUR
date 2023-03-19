//************************************************
// リーチになるマスを保存する
//************************************************
#include "define.h"

void reachArrayPush(int x, int y, int z, int reachArray[10][3]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (reachArray[i][0] == -1) {
			reachArray[i][0] = x;
			reachArray[i][1] = y;
			reachArray[i][2] = z;
			break;
		}
	}
}