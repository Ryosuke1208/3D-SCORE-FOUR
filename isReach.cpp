//************************************************
// ���̎��_�Ń��[�`�ɂȂ��Ă���{���𐔂���
// �܂��A���̍��W�̊i�[�ƃ`�F�b�N�܂�
// ���菑�� �Ђǂ�
//************************************************
#include "define.h"

void reachArrayPush(int, int, int, int[10][3]);

int isReach(int puzzle[][4][4], int p_num) {
	int x, y, z;
	int i, j;
	int cnt1, cnt2;
	int reach = 0; // ���[�`�̐�

	int reachArray[10][3]; // ���[�`�ɂȂ蓾��}�X��ۑ�����z�� ���߂ɂ��Ă���
	// �z��̏�����
	for (i = 0; i < 10; i++) {
		reachArray[i][0] = -1;
		reachArray[i][1] = -1;
		reachArray[i][2] = -1;
	}
	// ���[�`�̃`�F�b�N
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̉����̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[x][y][i] == p_num) cnt1++;
				if (puzzle[x][y][i] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[x][y][i] == OK) reachArrayPush(x, y, i, reachArray);
				}
				reach++;
			}
		}
		for (z = 0; z < 4; z++) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̏c���̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[x][i][z] == p_num) cnt1++;
				if (puzzle[x][i][z] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[x][i][z] == OK) reachArrayPush(x, i, z, reachArray);
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
				if (puzzle[x][i][i] == OK) reachArrayPush(x, i, i, reachArray);
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
				if (puzzle[x][3 - i][i] == OK) reachArrayPush(x, 3 - i, i, reachArray);
			}
			reach++;
		}
	}
	for (y = 0; y < 4; y++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̉����̍��ォ��E���ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][y][i] == p_num) cnt1++;
			if (puzzle[i][y][i] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][y][i] == OK) reachArrayPush(i, y, i, reachArray);
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
				if (puzzle[i][y][3 - i] == OK) reachArrayPush(i, y, 3 - i, reachArray);
			}
			reach++;
		}
	}
	for (z = 0; z < 4; z++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̏c���̎�O���牜�ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		for (i = 0; i < 4; i++) {
			if (puzzle[i][i][z] == p_num) cnt1++;
			if (puzzle[i][i][z] == OK) cnt2++;
		}
		if (cnt1 == 3 && cnt2 == 1) {
			for (i = 0; i < 4; i++) {
				if (puzzle[i][i][z] == OK) reachArrayPush(i, i, z, reachArray);
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
				if (puzzle[i][3 - i][z] == OK) reachArrayPush(i, 3 - i, z, reachArray);
			}
			reach++;
		}
	}
	for (y = 0; y < 4; y++) {
		for (z = 0; z < 4; z++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̍����̏c�̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			for (i = 0; i < 4; i++) {
				if (puzzle[i][y][z] == p_num) cnt1++;
				if (puzzle[i][y][z] == OK) cnt2++;
			}
			if (cnt1 == 3 && cnt2 == 1) {
				for (i = 0; i < 4; i++) {
					if (puzzle[i][y][z] == OK) reachArrayPush(i, y, z, reachArray);
				}
				reach++;
			}
		}
	}
	// ���̓I�Ȏ��_�ł̎΂߂̃`�F�b�N
	cnt1 = 0;
	cnt2 = 0;
	for (i = 0; i < 4; i++) {
		if (puzzle[i][i][i] == p_num) cnt1++;
		if (puzzle[i][i][i] == OK) cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 1) {
		for (i = 0; i < 4; i++) {
			if (puzzle[i][i][i] == OK) reachArrayPush(i, i, i, reachArray);
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
			if (puzzle[i][3 - i][3 - i] == OK) reachArrayPush(i, 3 - i, 3 - i, reachArray);
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
			if (puzzle[i][3 - i][i] == OK) reachArrayPush(i, 3 - i, i, reachArray);
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
			if (puzzle[i][i][3 - i] == OK) reachArrayPush(i, i, 3 - i, reachArray);
		}
		reach++;
	}
	// �����������[�`�łȂ��������[�`�i1�}�X�h���΂ǂ����̃��C�����h����j�̔���
	// ���_��Z�u�����[�`�܂ł͂��蓾�邪�A�_�u�����[�`�ȏ�͂߂����ɋN����Ȃ��Ƃ�����
	for (i = 0; i < 10; i++) {
		if (reachArray[i][0] != -1) {
			for (j = i + 1; j < 10; j++) {
				if (reachArray[j][0] != -1) {
					if (reachArray[i][0] == reachArray[j][0] &&
						reachArray[i][1] == reachArray[j][1] &&
						reachArray[i][2] == reachArray[j][2]) {
						reach--;
						reachArray[j][0] = -1;
						reachArray[j][1] = -1;
						reachArray[j][2] = -1;
					}
				}
			}
		}
	}
	return reach;
}