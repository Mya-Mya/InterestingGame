#include "MyaSpaceVI.h"
#include"DxLib.h"
#include <stdlib.h> 
#include <time.h>
#include<vector>
#include<math.h>

void Mya::SpaceVI(int windowwidth, int windowheight, char * Kind, char * Name,char *Message)
{
	//�����_������܂�
	unsigned int now = (unsigned int)time(0);
	srand(now);

	//�t�H���g�n���h���ƐF���쐬
	int LargeFont = CreateFontToHandle("���C���I", 50, 6, DX_FONTTYPE_ANTIALIASING);
	int LargeColor = GetColor(30, 30, 30);
	int MiddleFont = CreateFontToHandle("���C���I", 30, 3, DX_FONTTYPE_ANTIALIASING);
	int MiddleColor = GetColor(100, 100, 100);
	int SmallFont = CreateFontToHandle("���C���I", 15, 6, DX_FONTTYPE_ANTIALIASING);
	int SmallColor = GetColor(160, 160, 160);

	//�p�[�e�B�N���̃N���X���쐬
	mRingParticle instRingParticle;

	//���W�ʒu�L�^�̂��߂̍\����
	struct sCharacterPos {
		int width;
		int height;
		int x;
		int y;
	};

	//�����̕\�����W�v�Z
	sCharacterPos Center;
	Center.width = GetDrawFormatStringWidthToHandle(LargeFont,"::");
	Center.x = (windowwidth / 2) - (Center.width / 2);
	Center.height = GetDrawFormatStringWidthToHandle(LargeFont, "��");
	Center.y = (windowheight / 2) - (Center.height / 2);
	
	sCharacterPos Left;
	Left.width = GetDrawFormatStringWidthToHandle(LargeFont, "Mya ");
	Left.x = Center.x - Left.width;
	Left.height = GetDrawFormatStringWidthToHandle(LargeFont, "��");
	Left.y = (windowheight / 2) - (Left.height / 2);

	sCharacterPos Right;
	Right.width = GetDrawFormatStringWidthToHandle(LargeFont, " %s",Kind);
	Right.x = Center.x+Center.width ;
	Right.height = GetDrawFormatStringWidthToHandle(LargeFont, "��");
	Right.y = (windowheight / 2) - (Right.height / 2);

	sCharacterPos Middle;
	Middle.width = GetDrawFormatStringWidthToHandle(MiddleFont, "%s", Name);
	Middle.x = (windowwidth / 2) - (Middle.width / 2);
	Middle.height = GetDrawFormatStringWidthToHandle(MiddleFont, "��");
	Middle.y = (windowheight / 2) - (Middle.height / 2)+Center.height+5;

	sCharacterPos Bottom;
	Bottom.width = GetDrawFormatStringWidthToHandle(SmallFont, "%s", Message);
	Bottom.x = (windowwidth / 2) - (Bottom.width / 2);
	Bottom.height = GetDrawFormatStringWidthToHandle(MiddleFont, "��");
	Bottom.y = (windowheight / 2) -(Bottom.height/2)+ Middle.height + Center.height + 40;

	//���[�v���p�ϐ�
	int clock = 0;
	int distance = 0;

	while (ScreenFlip() == 0 && ProcessMessage()==0 && ClearDrawScreen() == 0) {
		//�A���t�@�u�����h����
		{
			if ( 0 <= clock && clock < 10) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 25*clock);
			if (10 == clock) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (150 <= clock)SetDrawBlendMode(DX_BLENDMODE_ALPHA, 1250-5*clock);
		}

		//�w�i�`��
		DrawBox(0, 0, windowwidth, windowheight, GetColor(220, 220, 220), TRUE);

		//�p�[�e�B�N���`��
		if (clock==30) instRingParticle.Sprash(windowwidth / 2, windowheight / 2);
		instRingParticle.DO();

		//�����`��̃A�j���[�V�����v�f
		{
			if (0 <= clock && clock < 30) distance = (pow((clock - 30), 6))/1000000;
			if (30 <= clock) distance = 0;
		}
		//�����`��
		DrawFormatStringToHandle(Center.x, Center.y, LargeColor, LargeFont, "::");
		DrawFormatStringToHandle(Left.x-distance, Left.y, LargeColor, LargeFont, "Mya ");
		DrawFormatStringToHandle(Right.x+distance, Right.y, LargeColor, LargeFont, " %s",Kind);
		DrawFormatStringToHandle(Middle.x, Middle.y+distance/2, MiddleColor, MiddleFont, " %s", Name);
		DrawFormatStringToHandle(Bottom.x, Bottom.y + distance, SmallColor, SmallFont, " %s", Message);

		//�N���b�N��i�߂�
		clock++;
		if (clock == 250) { SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); return; }
	}
}

#define RINGPARTICLE_PosRedundancy 20
#define RINGPARTICLE_ColorRedundancy 170 + rand() % 65

Mya::iRingParticle::iRingParticle(int x, int y)
{
	inx = x + RINGPARTICLE_PosRedundancy - rand() % RINGPARTICLE_PosRedundancy*2;
	iny = y + RINGPARTICLE_PosRedundancy - rand() % RINGPARTICLE_PosRedundancy*2;
	r = 0;
	vr = 1+rand() % 3;
	limr = 70 + rand() % 70;
	color = GetColor(RINGPARTICLE_ColorRedundancy, RINGPARTICLE_ColorRedundancy, RINGPARTICLE_ColorRedundancy);
}

int Mya::iRingParticle::DO()
{
	DrawCircle(inx, iny, r, color, TRUE);

	r += vr;
	if (r > limr) return 1;
	return 0;
}

Mya::mRingParticle::mRingParticle()
{
}

void Mya::mRingParticle::DO()
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

void Mya::mRingParticle::Sprash(int x, int y)
{
	for (int i = 0; i<8; i++) lP.push_back(new iRingParticle(x, y));
}

