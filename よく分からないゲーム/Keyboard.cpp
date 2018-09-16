#include "Keyboard.h"
#include"DxLib.h"

void Keyboard::Update()
{
	char tmpKey[256];             // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey);  // 全てのキーの入力状態を得る
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			m_Key[i]++;   // 加算
		}
		else {              // 押されていなければ
			m_Key[i] = 0; // 0にする
		}
	}
}

int Keyboard::Get(int KeyCode)
{
	return m_Key[KeyCode]; // KeyCodeの入力状態を返す
}
