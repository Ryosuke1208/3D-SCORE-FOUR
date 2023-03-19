//************************************************
// Šë‚È‚¢ƒ}ƒX‚ğ•Û‘¶‚·‚é
// ‚±‚ñ‚È‚É”z—ñ‚Ì”‚¢‚ç‚È‚©‚Á‚½
//************************************************
#include "define.h"

void arrayPush(int x, int y, int z, int array_list[20][3]) {
	int i;
	for (i = 0; i < 20; i++) {
		if (array_list[i][0] == -1) {
			array_list[i][0] = x;
			array_list[i][1] = y;
			array_list[i][2] = z;
			break;
		}
	}
}