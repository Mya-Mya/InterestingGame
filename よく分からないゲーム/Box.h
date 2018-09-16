#pragma once
#include"Keyboard.h"
#include<vector>
#include"Particle.h"

class Box {
private:
	int inx1, iny1,inx2,iny2;
	char *inkeycode;
	int inkeynum;
	
public:
	Box(int keycode, int width, int height);
	void DO();
	int Ask(int x, int y);
};

class mBox {
private:
	std::vector<Box*> lB;
	std::vector<Box*>::iterator iB;
public:
	void DO();
	mBox(int width, int height);
	int Ask(int x, int y);
};