#include "ImplFollowEye.h"
#include <cassert>
#include <cmath>

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
		theta_ -= rotateSpeed_;
	}
	if (pInput_->PushKey(DIK_DOWN)) {
		theta_ += rotateSpeed_;
	}

	//カメラの回転を算出
	Vector3 rotate;
	rotate.x = theta_;

	//カメラの座標を算出
	Vector3 eyePosition;
	Matrix4x4 worldMatrix = Matrix4x4::AffineMatrix({1.0f, 1.0f, 1.0f}, rotate, )


	/// カメラに座標をセット
	eye_->SetRotate(rotate);
	eye_->SetTranslate(eyePosition);
}
