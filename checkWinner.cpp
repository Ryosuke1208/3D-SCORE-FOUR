//************************************************
// モンテカルロ用
// ﾌﾟﾚｲﾔｰとCPUどっちが勝ったのか
// 又はドローなのかを確認
//************************************************
#include "define.h"

boolean isDone(int[][4][4], int);
boolean isDraw(int[][4][4]);

boolean checkWinner(int puzzle[][4][4], int* winner) {
	if (isDone(puzzle, P1)) {
		*winner = P1;
		return true;
	}
	else if (isDone(puzzle, P2)) {
		*winner = P2;
		return true;
	}
	else if (isDraw(puzzle)) {
		*winner = DRAW;
		return true;
	}
	else return false;
}
