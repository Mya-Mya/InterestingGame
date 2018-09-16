#pragma once

template <typename _T>
class Singleton {

protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};

};

class Keyboard : public Singleton<Keyboard> {

	friend Singleton< Keyboard >;

public:
	//キーの入力状態を更新
	void Update();

	//引数のキーコードのキーの入力状態を返す
	int Get(int KeyCode);

private:
	int m_Key[256];  // キーの入力状態格納用変数
};