//************************************************
// �}�`�̐F�h�菈��
//************************************************
#include "define.h"

void fill(int x, int y, int z, int status) {
	static int triangle_x = 0, triangle_y = 0;
	static unsigned int color = 0;
	switch (status) {
	case OK:
		color = LIGHT_GRAY; // �u�����Ƃ��o����ӏ��̐F
		break;
	case P1:
		color = LIGHT_RED; // PLAYER1�̐F
		break;
	case P2:
		color = LIGHT_BLUE; // PLAYER2 or COMPUTER�̐F
		break;
	case BINGO_P1:
		color = RED; // PLAYER1���r���S�̎��̕\���F
		break;
	case BINGO_P2:
		color = BLUE; // PLAYER2 or COMPUTER���r���S�̎��̕\���F
		break;
	default:
		break;
	}

	//************************************************
	// �F�h�������ӏ��̐}�`�̍�����XY���W���擾���A
	// �O�p�`��2�g���ĐF�h���\������
	//************************************************
	triangle_x = LINE_START_X + (LINE_COL_W * z) + ((LINE_COL_W - LINE_ROW_H) * y);
	triangle_y = LINE_START_Y + (-LINE_ROW_H * y) + FIGURE_INTERVAL * x;
	// �����̎O�p�`�̍����A��A�E���̍��W
	DrawTriangleAA((float)(triangle_x + TRIANGLE_GAP_X), (float)(triangle_y - TRIANGLE_GAP_Y),
		(float)(triangle_x + (LINE_COL_W - LINE_ROW_H)), (float)(triangle_y - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangle_x + LINE_COL_W), (float)(triangle_y - TRIANGLE_GAP_Y), color, TRUE);
	// �E���̎O�p�`�̉E��A����A���̍��W
	DrawTriangleAA((float)(triangle_x + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - TRIANGLE_GAP_X), (float)(triangle_y - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangle_x + (LINE_COL_W - LINE_ROW_H)), (float)(triangle_y - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangle_x + LINE_COL_W), (float)(triangle_y - TRIANGLE_GAP_Y), color, TRUE);
}