#pragma once
#include "BasePlanet.h"
class Jupiter : public BasePlanet
{
public:
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//終了
	void Finalize() override;
};

