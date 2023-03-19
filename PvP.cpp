//************************************************
// プレイヤー同士での対戦
//************************************************
#include "define.h"

boolean playerPutProc(int[][4][4], int, int, int, int[][3]);
boolean isDone(int[][4][4], int);
void getBingoLine(int[][4][4], int, int[][3]);
boolean showFinishedStatus(int[][4][4], int, int, int, int[][3]);
void showWinPvP(int);
boolean isDraw(int[][4][4]);
void showDraw();

void PvP() {
    int p_num = 0;
    int puzzle[4][4][4] = // 最初は一番下だけ置ける状態
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    int bingo[4][3];// ビンゴになったマスの格納用
    int temp[2][3];// 置いたマスの情報の格納用（PvPでは使わない）
    // ゲーム処理
    while (1) {
        // プレイヤーが出す手を決める処理
        // VSプレイヤーの時は難易度は適当に-1を入れている
        if (p_num % 2 == 0) playerPutProc(puzzle, (p_num % 2) + 1, 0, -1, temp);
        else playerPutProc(puzzle, (p_num % 2) + 1, 0, -1, temp);
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (p_num % 2) + 1)) {
            getBingoLine(puzzle, (p_num % 2) + 1, bingo);
            showFinishedStatus(puzzle, 0, -1, (p_num % 2) + 1, bingo);
            showWinPvP((p_num % 2) + 1);
            break;
        }
        if (isDraw(puzzle)) {
            bingo[0][0] = -1;
            showFinishedStatus(puzzle, 0, -1, (p_num % 2) + 1, bingo);
            showDraw();
            break;
        }
        p_num++;
    }
}