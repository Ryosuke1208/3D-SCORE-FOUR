//************************************************
// ���郉�C����ő��肪�Q�}�X�����Ă���
// �������̃}�X���Ȃ��ӏ���z��ɓ���ĕԂ�
//************************************************
#include "define.h"

void arrayPush(int, int, int, int[20][3]);

int cntDangerLine(int puzzle[][4][4], int value[][4][4], int p_num, int array_list[20][3]) {
	int i, j, k;
	int x, y, z;
	int e_num = 0;
	int cnt = 0;
	int r_cnt = 0;//�@1��̒��ɑ���̃}�X���Q����A�������̃}�X���P���Ȃ��}�X�̐���Ԃ�
	if (p_num == P2) e_num = P1;
	if (p_num == P1) e_num = P2;
	// �z��̏�����
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			array_list[i][j] = -1;
		}
	}
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					// ���̂ł̏c
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == e_num) {
							cnt++;
						}
						if (puzzle[x][j][k] == p_num) {
							//if (puzzle[x][j][k] == p_num || puzzle[x][j][k] == NG) {
							cnt = 0;
							break;
						}
					}
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						r_cnt++;
						arrayPush(i, j, k, array_list);
					}
					cnt = 0;
					// ���ʂł̏c
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == e_num) {
							cnt++;
						}
						if (puzzle[i][y][k] == p_num) {
							//if (puzzle[i][y][k] == p_num || puzzle[i][y][k] == NG) {
							cnt = 0;
							break;
						}
					}
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						r_cnt++;
						arrayPush(i, j, k, array_list);
					}
					cnt = 0;
					// ���ʂł̉�
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == e_num) {
							cnt++;
						}
						if (puzzle[i][j][z] == p_num) {
							//if (puzzle[i][j][z] == p_num || puzzle[i][j][z] == NG) {
							cnt = 0;
							break;
						}
					}
					//�@�����댯�ȃ��C���Ȃ���W��ۑ�
					if (cnt >= 1) {
						r_cnt++;
						arrayPush(i, j, k, array_list);
					}
					cnt = 0;
					// ��������E��ւ̕��ʂł̎΂�
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == e_num) {
								cnt++;
							}
							if (puzzle[i][z][z] == p_num) {
								//if (puzzle[i][z][z] == p_num || puzzle[i][z][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
						// ��ԉ��̍��������ԏ�E��ւ̑Ίp��
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == e_num) {
									cnt++;
								}
								if (puzzle[x][y][y] == p_num) {
									//if (puzzle[x][y][y] == p_num || puzzle[x][y][y] == NG) {
									cnt = 0;
									break;
								}
							}
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								r_cnt++;
								arrayPush(i, j, k, array_list);
							}
							cnt = 0;
						}
						// ��ԉ��̉E�ォ���ԏ㍶���ւ̑Ίp��
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == e_num) {
									cnt++;
								}
								if (puzzle[x][x][x] == p_num) {
									//if (puzzle[x][x][x] == p_num || puzzle[x][x][x] == NG) {
									cnt = 0;
									break;
								}
							}
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								r_cnt++;
								arrayPush(i, j, k, array_list);
							}
							cnt = 0;
						}
					}
					// ���ォ��E���ւ̕��ʂł̎΂�
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == e_num) {
								cnt++;
							}
							if (puzzle[i][y][z] == p_num) {
								//if (puzzle[i][y][z] == p_num || puzzle[i][y][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
						// ��ԉ��̍��ォ���ԏ�̉E���ւ̑Ίp��
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == e_num) {
									cnt++;
								}
								if (puzzle[x][x][z] == p_num) {
									//if (puzzle[x][x][z] == p_num || puzzle[x][x][z] == NG) {
									cnt = 0;
									break;
								}
							}
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								r_cnt++;
								arrayPush(i, j, k, array_list);
							}
							cnt = 0;
						}
						// ��ԉ��̉E�������ԏ�̍���ւ̑Ίp��
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == e_num) {
									cnt++;
								}
								if (puzzle[x][y][x] == p_num) {
									//if (puzzle[x][y][x] == p_num || puzzle[x][y][x] == NG) {
									cnt = 0;
									break;
								}
							}
							//�@�����댯�ȃ��C���Ȃ���W��ۑ�
							if (cnt >= 1) {
								r_cnt++;
								arrayPush(i, j, k, array_list);
							}
							cnt = 0;
						}
					}
					// �c���ʁi�x���j�ł̎΂�
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == e_num) {
								cnt++;
							}
							if (puzzle[x][j][z] == p_num) {
								//if (puzzle[x][j][z] == p_num || puzzle[x][j][z] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
					}
					// �c���ʂł̎΂ߔ���
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == e_num) {
								cnt++;
							}
							if (puzzle[x][j][x] == p_num) {
								//if (puzzle[x][j][x] == p_num || puzzle[x][j][x] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
					}
					// �����ʁi�y���j�ł̎΂�
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == e_num) {
								cnt++;
							}
							if (puzzle[x][y][k] == p_num) {
								//if (puzzle[x][y][k] == p_num || puzzle[x][y][k] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
					}
					// �����ʂł̎΂ߔ���
					if (i == j) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][x][k] == e_num) {
								cnt++;
							}
							if (puzzle[x][x][k] == p_num) {
								//if (puzzle[x][x][k] == p_num || puzzle[x][x][k] == NG) {
								cnt = 0;
								break;
							}
						}
						//�@�����댯�ȃ��C���Ȃ���W��ۑ�
						if (cnt >= 1) {
							r_cnt++;
							arrayPush(i, j, k, array_list);
						}
						cnt = 0;
					}
				}
			}
		}
	}
	return r_cnt;
}