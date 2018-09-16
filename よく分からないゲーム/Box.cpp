#include "Box.h"
#include"DxLib.h"
#define KINDofKEYCODE 5
#define NUMBERSofBOX 10
#define BOXsize 100

Box::Box(int keycode, int width, int height)
{
	inx1 = (rand() % width) -(BOXsize/2);
	iny1 = (rand() % height)-(BOXsize/2);
	inx2 = inx1 + BOXsize;
	iny2 = iny1 + BOXsize;
	switch (keycode) {
	case 0:
		inkeycode = "A";
		break;
	case 1:
		inkeycode = "B";
		break;
	case 2:
		inkeycode = "C";
		break;
	case 3:
		inkeycode = "D";
		break;
	case 4:
		inkeycode = "E";
		break;
	}
	inkeynum = keycode;
}

#define BOXthick 6
void Box::DO()
{
	DrawBox(inx1, iny1, inx2, iny2, GetColor(170, 170, 170), FALSE);
	DrawBox(inx1+ BOXthick, iny1+ BOXthick, inx2- BOXthick, iny2- BOXthick, GetColor(170, 170, 170), FALSE);
	DrawFormatString((inx1 + inx2) / 2, (iny1 + iny2) / 2, GetColor(40, 40, 40), "%s", inkeycode);
}

int Box::Ask(int x, int y)
{
	switch (inkeynum) {
	case 0:
		if (Keyboard::Instance()->Get(KEY_INPUT_A) != 1) return 0;
		break;
	case 1:
		if (Keyboard::Instance()->Get(KEY_INPUT_B) != 1) return 0;
		break;
	case 2:
		if (Keyboard::Instance()->Get(KEY_INPUT_C) != 1) return 0;
		break;
	case 3:
		if (Keyboard::Instance()->Get(KEY_INPUT_D) != 1) return 0;
		break;
	case 4:
		if (Keyboard::Instance()->Get(KEY_INPUT_E) != 1) return 0;
		break;
	}

	if (inx1 < x && x < inx2) {
		if (iny1 < y && y < iny2) {
			return 1;
		}
	}
	return 0;
}

void mBox::DO()
{
	iB = lB.begin();
	while (iB != lB.end()) {
		(*iB)->DO();
		++iB;
	}
}

mBox::mBox(int width, int height)
{
	for(int i=0;i<NUMBERSofBOX;i++)lB.push_back(new Box(rand()%KINDofKEYCODE, width, height));
}

int mBox::Ask(int x, int y)
{
	iB = lB.begin();
	while (iB != lB.end()) {
		if ((*iB)->Ask(x, y) == 1) return 1;
		++iB;
	}

	return 0;
}
