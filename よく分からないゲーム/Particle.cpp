#include "Particle.h"
#include"DxLib.h"

mParticle::mParticle()
{
}

void mParticle::DO()
{
	iP = lP.begin();
	while (iP != lP.end()) {
		if ((*iP)->DO() == 1) {
			iP = lP.erase(iP);
			return;
		};
		++iP;
	}
}

void mParticle::Sprash(int x,int y)
{
	for(int i=0;i<4;i++) lP.push_back(new Particle(x, y));
}

Particle::Particle(int x, int y)
{
	inx = x - (rand() % 20) + 10;
	iny = y - (rand() % 20) + 10;
	color = GetColor(150 + rand() % 90, 150 + rand() % 90, 150 + rand() % 90);
	vr = 1 + rand() % 2;
	limr = 10 + rand() % 40;
	r = 0;
}

int Particle::DO()
{
	DrawCircle(inx, iny, r, color, TRUE);
	r += vr;
	if (r > limr) return 1;
	return 0;
}
