//************************************************
// Šë‚È‚¢ƒ}ƒX‚ğ•Û‘¶‚·‚é
// ‚±‚ñ‚È‚É”z—ñ‚Ì”‚¢‚ç‚È‚©‚Á‚½
//************************************************
#include "define.h"

void arrayPush(int x, int y, int z, int arrayList[20][3]) {
	int i;
	for (i = 0; i < 20; i++) {
		if (arrayList[i][0] == -1) {
			arrayList[i][0] = x;
			arrayList[i][1] = y;
			arrayList[i][2] = z;
			break;
		}
	}
}