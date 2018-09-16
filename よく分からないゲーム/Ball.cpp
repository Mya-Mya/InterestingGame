#include "Ball.h"
#include"DxLib.h"
#define VXspan 7
#define VYspan 7
#define NUMBERSofBALL 10

Ball::Ball(int width, int height)
{
	vx = -VXspan + rand() % VXspan*2;
	vy = -VYspan + rand() % VYspan*2;
	inwidth = width;
	inheight = height;
}

int Ball::GetX()
{
	return x;
}

int Ball::GetY()
{
	return y;
}

void Ball::DO()
{
	//�`��
	DrawCircle(x, y, 3, GetColor(120, 120, 120), TRUE);
	
	//���˕Ԃ�
	if (x <= 0) vx *= -1, x = 0;///��
	if (inwidth <= x) vx *= -1, x = inwidth;///�E
	if (y <= 0)vy *= -1, y = 0;///��
	if (inheight <= y)vy *= -1, y = inheight;///��

	 //�ʒu�ړ�
	x += vx;
	y += vy;
}

mBall::mBall(int width, int height)
{
	inwidth = width;
	inheight = height;
	pmB = new mBox(width, height);
	pmP = new mParticle();
	for (int i = 0; i < NUMBERSofBALL; i++)lB.push_back(new Ball(width, height));
	Font00 = CreateFontToHandle("���C���I", 70, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void mBall::DO()
{
	ballnum = 0;

	//�{�[���̕`��Əꍇ�ɂ���č폜
	iB = lB.begin();
	while (iB != lB.end()) {
		//�`��
		(*iB)->DO();

		//�{�b�N�X�͈͓��ɂ��邩�ǂ������ׂ�
		if (pmB->Ask((*iB)->GetX(), (*iB)->GetY()) == 1) {
			pmP->Sprash((*iB)->GetX(), (*iB)->GetY());//�p�[�e�B�N���쐬
			lB.erase(iB);
			
			//�R���e�i���g�p�����p�[�e�B�N���C���X�^���X�Ǘ��ɂ���
			//�r���C���X�^���X�폜���������Ă���A��while�������ɂĂ��ׂẴC���X�^���X��
			//���s�������ꍇ�́A�폜��ɃC�e���[�^�������ɒ��while���������X�^�[�g����B
			iB = lB.begin();
			continue;
		}
		++iB;
		ballnum += 1;
	}

	//�p�[�e�B�N���̎��s
	pmP->DO();

	//���̕`��
	pmB->DO();

	if (ballnum == 0) END();
}

void mBall::END() {
	SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
	if(rand()%30==0)pmP->Sprash(rand()%inwidth,rand()%inheight);//�p�[�e�B�N���쐬
	DrawStringToHandle((inwidth/2)-200, (inheight/2)-50, "Game Clear", GetColor(255, 255, 255), Font00);
}