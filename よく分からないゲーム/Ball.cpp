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
	//描画
	DrawCircle(x, y, 3, GetColor(120, 120, 120), TRUE);
	
	//跳ね返り
	if (x <= 0) vx *= -1, x = 0;///左
	if (inwidth <= x) vx *= -1, x = inwidth;///右
	if (y <= 0)vy *= -1, y = 0;///上
	if (inheight <= y)vy *= -1, y = inheight;///下

	 //位置移動
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
	Font00 = CreateFontToHandle("メイリオ", 70, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void mBall::DO()
{
	ballnum = 0;

	//ボールの描画と場合によって削除
	iB = lB.begin();
	while (iB != lB.end()) {
		//描画
		(*iB)->DO();

		//ボックス範囲内にいるかどうか調べる
		if (pmB->Ask((*iB)->GetX(), (*iB)->GetY()) == 1) {
			pmP->Sprash((*iB)->GetX(), (*iB)->GetY());//パーティクル作成
			lB.erase(iB);
			
			//コンテナを使用したパーティクルインスタンス管理について
			//途中インスタンス削除が発生しても一連のwhile処理内にてすべてのインスタンスを
			//実行したい場合は、削除後にイテレータを初頭に定めwhile処理をリスタートする。
			iB = lB.begin();
			continue;
		}
		++iB;
		ballnum += 1;
	}

	//パーティクルの実行
	pmP->DO();

	//箱の描画
	pmB->DO();

	if (ballnum == 0) END();
}

void mBall::END() {
	SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
	if(rand()%30==0)pmP->Sprash(rand()%inwidth,rand()%inheight);//パーティクル作成
	DrawStringToHandle((inwidth/2)-200, (inheight/2)-50, "Game Clear", GetColor(255, 255, 255), Font00);
}