#pragma once
#include"Ball.h"
#include"Keyboard.h"
class Game {
private:
	mBall *pmB;
	int inwidth, inheight;
public:
	Game(int width, int height);
	void DO();
};