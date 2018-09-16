#include "Game.h"
#include"DxLib.h"
Game::Game(int width, int height)
{
	pmB = new mBall(width, height);
	inwidth = width;
	inheight = height;
}

void Game::DO()
{
	Keyboard::Instance()->Update();
	DrawBox(0, 0, inwidth, inheight, GetColor(240, 240, 240), TRUE);
	pmB->DO();
}
