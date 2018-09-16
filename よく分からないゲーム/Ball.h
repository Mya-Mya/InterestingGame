#pragma once
#include"Box.h"
#include<vector>
#include"Particle.h"

class Ball {
private:
	int inwidth, inheight;
	int x = 30, y = 30;
	int vx, vy;
public:
	Ball(int width, int height);
	int GetX();
	int GetY();
	void DO();
};

class mBall {
private:
	std::vector<Ball*>lB;
	std::vector<Ball*>::iterator iB;
	mBox *pmB;
	mParticle *pmP;
	int inwidth, inheight;
	int ballnum;
	int Font00;
public:
	mBall(int width, int height);
	void DO();
	void END();
};