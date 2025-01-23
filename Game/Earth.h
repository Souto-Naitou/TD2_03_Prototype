#pragma once
#include <Features/Input/Input.h>
#include "BasePlanet.h"
class Earth : public BasePlanet
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

	//getter
	const Vector3& GetWorldTranslate() { return model_->GetTranslate(); }

	//setter
	//Vector3 SetEyeDirection

private:
	//インプット
	Input* pInput_ = nullptr;
	//カメラの向き
	Vector3 eyeDirection_ = {};
	//

};

