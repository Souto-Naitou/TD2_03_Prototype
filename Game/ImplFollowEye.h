#pragma once
#include <Features/Input/Input.h>
#include <Features/GameEye/GameEye.h>
#include <Features/DeltaTimeManager/DeltaTimeManager.h>
class ImplFollowEye
{
public:
	void Initialize();

	void Update(const Vector3& translate);

	//setter
	void SetEye(GameEye* eye) { eye_ = eye; }

private:
	//入力
	Input* pInput_ = nullptr;
	//計算に使うカメラポインタ
	GameEye* eye_;

	const float pi_ = 3.14f;
	//カメラとプレイヤーの距離
	float distance_ = 20.0f;
	//角度
	Vector2 theta_ = {};
	//回転の速さ
	float rotateSpeed_ = 0.0f;

};

