#include "ImplFollowEye.h"
#include <cassert>
#include <cmath>
#include <algorithm>

void ImplFollowEye::Initialize()
{
	//インプット
	pInput_ = Input::GetInstance();
	//変数
	rotateSpeed_ = (30.0f / 360.0f) * pi_ * DeltaTimeManager::GetInstance()->GetDeltaTime(0);
}

void ImplFollowEye::Update(const Vector3& translate)
{
	if (!eye_) {
		//カメラをセットしてない
		assert(0);
	}

	//カメラ操作
	if (pInput_->PushKey(DIK_UP)) {
		theta_.x += rotateSpeed_;
	}
	if (pInput_->PushKey(DIK_DOWN)) {
		theta_.x -= rotateSpeed_;
	}
	if (pInput_->PushKey(DIK_RIGHT)) {
		theta_.y -= rotateSpeed_;
	}
	if (pInput_->PushKey(DIK_LEFT)) {
		theta_.y += rotateSpeed_;
	}

	//クランプ
	theta_.x = std::clamp<float>(theta_.x, -pi_ / 2.0f, pi_ / 2.0f);

	//カメラの回転を算出
	Vector3 rotate = {};
	rotate.x = theta_.x;
	rotate.y = theta_.y;

	//回転行列を作成
	Vector3 base = { 0,0,1 };
	Matrix4x4 rotateMatrix = Matrix4x4::RotateXMatrix(rotate.x) * Matrix4x4::RotateYMatrix(rotate.y) * Matrix4x4::RotateZMatrix(rotate.z);
	
	//向きを求める
	Vector3 direction = FMath::Transform(base, rotateMatrix);
	
	Vector3 targetPosition = {};
	targetPosition.Lerp(oldTargetPosition_, translate, 0.05f);

	//座標を求める
	Vector3 eyePosition = -direction.Normalize() * distance_ + targetPosition;
	

	/// カメラに座標をセット
	eye_->SetRotate(rotate);
	eye_->SetTranslate(eyePosition);

	oldTargetPosition_ = targetPosition;
}
