#pragma once
#include<vector>
class Particle {
private:
	int inx, iny;
	int r;
	int vr;
	int limr;
	int color;
public:
	Particle(int x, int y);
	int DO();
};

class mParticle {
private:
	std::vector<Particle*> lP;
	std::vector<Particle*>::iterator iP;
public:
	mParticle();
	void DO();
	void Sprash(int x,int y);
};