//************************************************
// ä˙ë“ílåvéZÇÃÉvÉçÉOÉâÉÄ
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
					// óßëÃÇ≈ÇÃèc
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// ïΩñ Ç≈ÇÃèc
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == e_num) {
							temp_score--;
							break;
						}
					}
					// ïΩñ Ç≈ÇÃâ°
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == e_num) {
							temp_score--;
							break;
						}
					}
					// ç∂â∫Ç©ÇÁâEè„Ç÷ÇÃïΩñ Ç≈ÇÃéŒÇﬂ
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// àÍî‘â∫ÇÃç∂â∫Ç©ÇÁàÍî‘è„âEè„Ç÷ÇÃëŒäpê¸
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// àÍî‘â∫ÇÃâEè„Ç©ÇÁàÍî‘è„ç∂â∫Ç÷ÇÃëŒäpê¸
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// ç∂è„Ç©ÇÁâEâ∫Ç÷ÇÃïΩñ Ç≈ÇÃéŒÇﬂ
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == e_num) {
								temp_score--;
								break;
							}
						}
						// àÍî‘â∫ÇÃç∂è„Ç©ÇÁàÍî‘è„ÇÃâEâ∫Ç÷ÇÃëŒäpê¸
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == e_num) {
									temp_score--;
									break;
								}
							}
						}
						// àÍî‘â∫ÇÃâEâ∫Ç©ÇÁàÍî‘è„ÇÃç∂è„Ç÷ÇÃëŒäpê¸
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == e_num) {
									temp_score--;
									break;
								}
							}
						}
					}
					// ècïΩñ ÅiÇxé≤ÅjÇ≈ÇÃéŒÇﬂ
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// ècïΩñ Ç≈ÇÃéŒÇﬂîΩëŒ
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// âúïΩñ ÅiÇyé≤ÅjÇ≈ÇÃéŒÇﬂ
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == e_num) {
								temp_score--;
								break;
							}
						}
					}
					// âúïΩñ Ç≈ÇÃéŒÇﬂîΩëŒ
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
