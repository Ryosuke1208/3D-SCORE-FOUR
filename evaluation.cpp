//************************************************
// ���Ғl�v�Z�̃v���O����
//************************************************
#include "define.h"

void evaluation(int puzzle[][4][4], int value[][4][4], int p_num) {
	int i, j, k;
	int x, y, z;
	int temp_score = 0;
	int e_num = 0;
	if (p_num == P2) e_num = P1;
	if (p_num == P1) e_num = P2;

	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					temp_score = value[i][j][k];
					// ���̂ł̏c
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// ���ʂł̏c
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// ���ʂł̉�
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == e_num) {
							temp_score--;
							break;
						}
					}
					// ��������E��ւ̕��ʂł̎΂�
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// ��ԉ��̍��������ԏ�E��ւ̑Ίp��
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// ��ԉ��̉E�ォ���ԏ㍶���ւ̑Ίp��
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// ���ォ��E���ւ̕��ʂł̎΂�
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// ��ԉ��̍��ォ���ԏ�̉E���ւ̑Ίp��
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// ��ԉ��̉E�������ԏ�̍���ւ̑Ίp��
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// �c���ʁi�x���j�ł̎΂�
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// �c���ʂł̎΂ߔ���
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// �����ʁi�y���j�ł̎΂�
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// �����ʂł̎΂ߔ���
					if (i == j) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][x][k] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					value[i][j][k] = temp_score;
				}
			}
		}
	}
}
