//************************************************
// ���̎��_�Ńp�Y�����r���S�ɂȂ��Ă��鐔�𒲂ׂ�
// ���g�������Ȃ������̂ŁA�S�~�݂����Ȃׂ�������
// �Ȃ��Ă邯�ǂ�邵��
//************************************************
#include "define.h"

boolean isDone(int puzzle[][4][4], int p_num) {
	int i, j, k;
	// �c�E���E�΂߂̃`�F�b�N
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			if (puzzle[i][j][0] == p_num && puzzle[i][j][1] == p_num &&
				puzzle[i][j][2] == p_num && puzzle[i][j][3] == p_num) return true;
		}
		for (k = 0; k < 4; k++) {
			if (puzzle[i][0][k] == p_num && puzzle[i][1][k] == p_num &&
				puzzle[i][2][k] == p_num && puzzle[i][3][k] == p_num) return true;
		}
		if (puzzle[i][0][0] == p_num && puzzle[i][1][1] == p_num &&
			puzzle[i][2][2] == p_num && puzzle[i][3][3] == p_num) return true;
		if (puzzle[i][3][0] == p_num && puzzle[i][2][1] == p_num &&
			puzzle[i][1][2] == p_num && puzzle[i][0][3] == p_num) return true;
	}
	for (j = 0; j < 4; j++) {
		if (puzzle[0][j][0] == p_num && puzzle[1][j][1] == p_num &&
			puzzle[2][j][2] == p_num && puzzle[3][j][3] == p_num) return true;
		if (puzzle[0][j][3] == p_num && puzzle[1][j][2] == p_num &&
			puzzle[2][j][1] == p_num && puzzle[3][j][0] == p_num) return true;
	}
	for (k = 0; k < 4; k++) {
		if (puzzle[0][0][k] == p_num && puzzle[1][1][k] == p_num &&
			puzzle[2][2][k] == p_num && puzzle[3][3][k] == p_num) return true;
		if (puzzle[0][3][k] == p_num && puzzle[1][2][k] == p_num &&
			puzzle[2][1][k] == p_num && puzzle[3][0][k] == p_num) return true;
	}
	for (j = 0; j < 4; j++) {
		for (k = 0; k < 4; k++) {
			if (puzzle[0][j][k] == p_num && puzzle[1][j][k] == p_num &&
				puzzle[2][j][k] == p_num && puzzle[3][j][k] == p_num) return true;
		}
	}
	// ���̓I�Ȏ��_�ł̎΂߂̃`�F�b�N
	if (puzzle[0][0][0] == p_num && puzzle[1][1][1] == p_num &&
		puzzle[2][2][2] == p_num && puzzle[3][3][3] == p_num) return true;
	if (puzzle[0][3][3] == p_num && puzzle[1][2][2] == p_num &&
		puzzle[2][1][1] == p_num && puzzle[3][0][0] == p_num) return true;
	if (puzzle[0][3][0] == p_num && puzzle[1][2][1] == p_num &&
		puzzle[2][1][2] == p_num && puzzle[3][0][3] == p_num) return true;
	if (puzzle[0][0][3] == p_num && puzzle[1][1][2] == p_num &&
		puzzle[2][2][1] == p_num && puzzle[3][3][0] == p_num) return true;
	// �r���S�ɂȂ��ĂȂ��Ƃ���false��Ԃ�
	return false;
}