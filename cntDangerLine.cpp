//************************************************
// ���郉�C����ő��肪�Q�}�X�����Ă���
// �������̃}�X���Ȃ��ӏ���z��ɓ���ĕԂ�
//************************************************
#include "define.h"

void arrayPush(int, int, int, int[20][3]);

int cntDangerLine(int puzzle[][4][4], int value[][4][4], int playerNumber, int arrayList[20][3]) {
	int i, j, k;
	int x, y, z;
	int enemyNumber = 0;
	int cnt = 0;
	int returnCnt = 0;//�@1��̒��ɑ���̃}�X���Q����A�������̃}�X���P���Ȃ��}�X�̐���Ԃ�
	if (playerNumber == P2) enemyNumber = P1;
	if (playerNumber == P1) enemyNumber = P2;
	// �z��̏�����
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			arrayList[i][j] = -1;
		}
	}
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					// ���̂ł̏c
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
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// ���ʂł̏c
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
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// ���ʂł̉�
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
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						returnCnt++;
						arrayPush(i, j, k, arrayList);
					}
					cnt = 0;
					// ��������E��ւ̕��ʂł̎΂�
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
						// ��ԉ��̍��������ԏ�E��ւ̑Ίp��
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
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
						// ��ԉ��̉E�ォ���ԏ㍶���ւ̑Ίp��
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
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
					}
					// ���ォ��E���ւ̕��ʂł̎΂�
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
						// ��ԉ��̍��ォ���ԏ�̉E���ւ̑Ίp��
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
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
						// ��ԉ��̉E�������ԏ�̍���ւ̑Ίp��
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
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								returnCnt++;
								arrayPush(i, j, k, arrayList);
							}
							cnt = 0;
						}
					}
					// �c���ʁi�x���j�ł̎΂�
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// �c���ʂł̎΂ߔ���
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// �����ʁi�y���j�ł̎΂�
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							returnCnt++;
							arrayPush(i, j, k, arrayList);
						}
						cnt = 0;
					}
					// �����ʂł̎΂ߔ���
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
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
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