#pragma once
#include <Features/GameEye/GameEye.h>
class ImplFollowEye
{
public:

	void Update();

	//setter
	void SetEye();

private:
	//計算に使うカメラポインタ
	GameEye* eye;

};

