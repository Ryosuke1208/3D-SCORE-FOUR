#include "DxLib.h"
#include "define.h"

void showTitle(int*, int*, int*);
void PvP();
void PvC(int, int);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    if (DxLib_Init() == -1)	return -1;
    // DxLibの初期設定
    SetBackgroundColor(241, 237, 238);
    SetGraphMode(800, 800, 32);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);
    int m, d, o;// モード、難易度、順番
    //************************************************
    // ゲームの処理
    //************************************************
    while (1) {
        showTitle(&m, &d, &o);
        if (m == 0) PvP();
        else if (m == 1) PvC(d, o);
        else break;
    }

    DxLib_End();

    return 0;
}

