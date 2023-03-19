//************************************************
// コンピューターとの対戦
//************************************************
#include "define.h"

boolean playerPutProc(int[][4][4], int, int, int, int[][3]);
void cpuPutProc(int[][4][4], int, int[][3]);
boolean isDone(int[][4][4], int);
void getBingoLine(int[][4][4], int, int[][3]);
boolean showFinishedStatus(int[][4][4], int, int, int, int[][3]);
void showWinPvC(int);
boolean isDraw(int[][4][4]);
void showDraw();

void PvC(int d, int o) {
    // プレイヤーが、0で先行・1で後攻
    int p_num;
    if (o == 0) p_num = 0;
    else p_num = 1;
    int puzzle[4][4][4] = // 最初は一番下だけ置ける状態
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    int bingo[4][3] = { 0 };// ビンゴになったマスの格納用 とりあえず0で初期化
    int temp[2][3] = { {-1,-1,-1}, {-1,-1,-1} };// 手を戻す用の配列 -1で初期化
    // ゲーム処理
    while (1) {
        if (p_num % 2 == 0) {
            while (1) {
                if (playerPutProc(puzzle, (p_num % 2) + 1, 1, d, temp)) break;
                else {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                        temp[0][0] = -1;
                    }
                }
            }
        }
        else cpuPutProc(puzzle, d, temp);
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (p_num % 2) + 1)) {
            getBingoLine(puzzle, (p_num % 2) + 1, bingo);
            // BACKキーで一手戻す
            if (!showFinishedStatus(puzzle, 1, d, (p_num % 2) + 1, bingo)) {
                // プレイヤーが勝った時とCPUが勝った時で戻し方が違う
                if (p_num % 2 == 0) {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        temp[0][0] = -1;
                        continue;
                    }
                }
                else {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                        temp[0][0] = -1;
                        p_num--;
                        continue;
                    }
                }
            }
            showWinPvC((p_num % 2) + 1);
            break;
        }
        // ドローになったかどうかのチェック
        if (isDraw(puzzle)) {
            bingo[0][0] = -1;
            showFinishedStatus(puzzle, 1, d, (p_num % 2) + 1, bingo);
            showDraw();
            break;
        }
        p_num++;
    }
}



