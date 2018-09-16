// よく分からないゲーム.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include"DxLib.h"
#include <stdlib.h> // rand, srand関数
#include <time.h>
#include"Game.h"
#include"MyaSpaceVI.h"

#define WIDTH 1000
#define HEIGHT 600

int main()
{
	SetGraphMode(WIDTH, HEIGHT, 16);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	Mya::SpaceVI(WIDTH,HEIGHT,"Game",
		"TypingCatcher",
		"タイピング能力が求められる玉消しゲームです。");

	Game *pGame = new Game(WIDTH, HEIGHT);
	unsigned int    now = (unsigned int)time(0);
	srand(now);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		pGame->DO();
	}
	DxLib_End();
	return 0;
}

