//************************************************
// �^�C�g���\��
// �摜�g�������Ȃ��̂ŊȒP��
//************************************************
#include "define.h"

void showTitle(int* m, int* d, int* o) {
	int font_100, font_30, font_50;// �t�H���g�ݒ� 
	int mode = 1, difficulty = 1, order = 0;// ���[�h�A��Փx�A����
	int mouse_x, mouse_y;// �}�E�X�ʒu�̓ǂݎ��
	font_100 = CreateFontToHandle(NULL, 100, 1, DX_FONTTYPE_ANTIALIASING);
	font_50 = CreateFontToHandle(NULL, 50, 1, DX_FONTTYPE_ANTIALIASING);
	font_30 = CreateFontToHandle(NULL, 30, 2, DX_FONTTYPE_ANTIALIASING);
	while (1) {
		ClearDrawScreen();

		GetMousePoint(&mouse_x, &mouse_y);
		DrawStringToHandle(55, 50, "3D SCORE FOUR", BLACK, font_100);
		DrawLineAA(0.0f, 200.0f, 800.0f, 200.0f, BLACK);
		DrawStringToHandle(55, 220, "���[������", BLACK, font_30);
		DrawStringToHandle(55, 250, "�E�c�A���A�΂߂�4�}�X�������Ώ���", BLACK, font_30);
		DrawStringToHandle(55, 280, "�E���߂͈�ԉ������u���Ȃ�", BLACK, font_30);
		DrawStringToHandle(55, 310, "�E�}�X�𖄂߂�Ə�̃}�X���u����悤�ɂȂ�", BLACK, font_30);
		DrawLineAA(0.0f, 360.0f, 800.0f, 360.0f, BLACK);

		if (mode == 0) DrawBoxAA(5.0f, 365.0f, 395.0f, 445.0f, LIGHT_YELLOW, TRUE);
		else if (mode == 1) DrawBoxAA(405.0f, 365.0f, 795.0f, 445.0f, LIGHT_YELLOW, TRUE);

		DrawStringToHandle(35, 380, "VS �v���C���[", BLACK, font_50);
		DrawStringToHandle(485, 380, "VS �b�o�t", BLACK, font_50);
		DrawLineAA(400.0f, 360.0f, 400.0f, 450.0f, BLACK);
		DrawLineAA(0.0f, 450.0f, 800.0f, 450.0f, BLACK);
		DrawStringToHandle(50, 470, "��Փx", BLACK, font_50);
		DrawLineAA(260.0f, 450.0f, 260.0f, 540.0f, BLACK);

		if (mode == 1) {
			if (difficulty == 0) DrawBoxAA(265.0f, 455.0f, 435.0f, 535.0f, LIGHT_YELLOW, TRUE);
			else if (difficulty == 1) DrawBoxAA(445.0f, 455.0f, 615.0f, 535.0f, LIGHT_YELLOW, TRUE);
			else if (difficulty == 2) DrawBoxAA(625.0f, 455.0f, 795.0f, 535.0f, LIGHT_YELLOW, TRUE);
		}

		DrawStringToHandle(300, 470, "�ア", BLACK, font_50);
		DrawLineAA(440.0f, 450.0f, 440.0f, 540.0f, BLACK);
		DrawStringToHandle(480, 470, "����", BLACK, font_50);
		DrawLineAA(620.0f, 450.0f, 620.0f, 540.0f, BLACK);
		DrawStringToHandle(660, 470, "����", BLACK, font_50);
		DrawLineAA(0.0f, 540.0f, 800.0f, 540.0f, BLACK);

		if (mode == 1) {
			if (order == 0) DrawBoxAA(5.0f, 545.0f, 395.0f, 625.0f, LIGHT_YELLOW, TRUE);
			else if (order == 1) DrawBoxAA(405.0f, 545.0f, 795.0f, 625.0f, LIGHT_YELLOW, TRUE);
		}

		DrawStringToHandle(50, 560, "��ڲ԰����s", BLACK, font_50);
		DrawLineAA(400.0f, 540.0f, 400.0f, 630.0f, BLACK);
		DrawStringToHandle(450, 560, "��ڲ԰����s", BLACK, font_50);
		DrawLineAA(0.0f, 630.0f, 800.0f, 630.0f, BLACK);

		if (mouse_x > 0 && mouse_x < 800 && mouse_y > 630 && mouse_y < 710) {
			DrawBoxAA(5.0f, 635.0f, 795.0f, 705.0f, LIGHT_BLUE, TRUE);
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				*m = mode;
				*d = difficulty;
				*o = order;
				break;
			}
		}

		DrawStringToHandle(275, 645, "�r�s�`�q�s", BLACK, font_50);
		DrawLineAA(0.0f, 710.0f, 800.0f, 710.0f, BLACK);

		if (mouse_x > 0 && mouse_x < 800 && mouse_y > 710 && mouse_y < 800) {
			DrawBoxAA(5.0f, 715.0f, 795.0f, 795.0f, LIGHT_RED, TRUE);
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				*m = -1;
				break;
			}
		}

		DrawStringToHandle(220, 730, "�Q�[������߂�", BLACK, font_50);

		if (mouse_x > 0 && mouse_x < 400 && mouse_y > 360 && mouse_y < 450 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) mode = 0;
		if (mouse_x > 400 && mouse_x < 800 && mouse_y > 360 && mouse_y < 450 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) mode = 1;

		if (mode == 1) {
			if (mouse_x > 260 && mouse_x < 440 && mouse_y > 450 && mouse_y < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 0;
			if (mouse_x > 440 && mouse_x < 620 && mouse_y > 450 && mouse_y < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 1;
			if (mouse_x > 620 && mouse_x < 800 && mouse_y > 450 && mouse_y < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 2;

			if (mouse_x > 0 && mouse_x < 400 && mouse_y > 540 && mouse_y < 630 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) order = 0;
			if (mouse_x > 400 && mouse_x < 800 && mouse_y > 540 && mouse_y < 630 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) order = 1;
		}

		ScreenFlip();
	}
}