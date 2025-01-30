#include "Player.h"
#include <Features/DeltaTimeManager/DeltaTimeManager.h>
#include <cassert>

void Player::Initialize()
{
	//インプット
	pInput_ = Input::GetInstance();
	//生成
	implFollowEye_ = std::make_unique<ImplFollowEye>();
	implFollowEye_->Initialize();

	//変数の初期化
	velocity_ = {};
	oldVelocity_ = {};

}

void Player::Update()
{
	//セット確認
	if (!earth_) {
		assert(0);  //地球未セット
	}
	if (!implFollowEye_->GetEye()) {
		assert(0);  //ゲームカメラ未セット
	}

	//implFollowEyeの更新(カメラの情報を参照するのでこれを最初に処理する)
	implFollowEye_->Update(earth_->GetWorldTranslate());

	//操作
	InputCommand();

	///※移動や当たり判定はEarth側でやるのでここには書かない

}

void Player::PostUpdate()
{
	//前フレームの速度保存←これを反射処理の直後にかく必要がある
	oldVelocity_ = earth_->GetVelocity();
}

void Player::Draw()
{
}

void Player::InputCommand()
{
	if (pInput_->PushKey(DIK_W)) {
		//最新速度決定
		Vector3 newVelocity_ = implFollowEye_->GetDirection().Normalize() * speed_;
		//速度補完
		velocity_.Lerp(oldVelocity_, newVelocity_, 0.05f);
		//earthのVelocityにセット
		earth_->SetVelocity(velocity_);
	}
}
