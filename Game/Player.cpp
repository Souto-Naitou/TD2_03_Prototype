#include "Player.h"
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

void Player::Draw()
{
}

void Player::InputCommand()
{
	if (pInput_->PushKey(DIK_W)) {
		velocity_ = implFollowEye_->GetDirection().Normalize() * speed_;
		//earthのVelocityにセット
		earth_->SetVelocity(velocity_);
	}
}
