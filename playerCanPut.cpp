//************************************************
// �}�E�X��XYZ���W���擾���A
// �����ɒu�����Ԃ����擾
// ��ԏ�̐}�`�̍����̐}�`�̍��W��{0,0,0}�Ƃ��āA
// �c����X���W�A���s���̎���Y���W�A�E�����̎���Z���W
// �Ƃ���(�����܂Ő}�`���XYZ���W�ł���
// �}�E�X��XY���W�̊T�O�Ƃ͈Ⴄ)
//************************************************
#include "define.h"

boolean playerCanPut(int puzzle[][4][4], int* x, int* y, int* z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouse_x, mouse_y;

    GetMousePoint(&mouse_x, &mouse_y);
    // ���������}�E�X��Y���W���}�`�͈͓̔��ɂ��邩�ǂ����̔���(�}�W�b�N�i���o�[����)
    if (mouse_y < LINE_START_Y - (LINE_ROW_H * 4) || // ��ԏ�̐}�`�̏�
        (mouse_y > LINE_START_Y && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // 1�Ԗڂ�2�Ԗڂ̐}�`�̊�
        (mouse_y > LINE_START_Y + FIGURE_INTERVAL * 1 && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // 2�Ԗڂ�3�Ԗڂ̐}�`�̊�
        (mouse_y > LINE_START_Y + FIGURE_INTERVAL * 2 && mouse_y < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // 3�Ԗڂƈ�ԉ��̐}�`�̊�
        mouse_y > LINE_START_Y + FIGURE_INTERVAL * 3) return false; // ��ԉ��̐}�`�̉�

    for (i = 0; i < 4; i++) { // �}�`���X���W�̌���
        if (mouse_y < LINE_START_Y + i * FIGURE_INTERVAL && mouse_y > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) X = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * X - mouse_y) / LINE_ROW_H; // �}�`���Y���W�̌���
    // ���������}�E�X��X���W���}�`�͈͓̔��ɂ��邩�ǂ����̔���
    if (mouse_x < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouse_x > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return false;
    }
    Z = (mouse_x - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W; // �}�`���X���W�̌���
    // �}�`��̂Ђ��`�̈��̐}�`�̎΂߂ɂȂ��Ă��镔����Z���W�̒���
    // �ڐ�̌X�������߂āAZ���W���{�|���Ă���
    if (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H) <= mouse_x && mouse_x <= LINE_START_X + LINE_COL_W * Z + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H)
        && (float)(mouse_x - (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H))
        <= (float)(LINE_START_Y + FIGURE_INTERVAL * X - (Y * LINE_ROW_H)) - mouse_y) Z--;
    // XYZ���K���l�Ȃ�ԋp
    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3 && puzzle[X][Y][Z] == OK) {
        *x = X;
        *y = Y;
        *z = Z;
        return true; // �u�����Ƃ��o����Ƃ���XYZ���W���Z�b�g����true��ԋp����
    }
    else return false;
}
