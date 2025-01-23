#include "Player.h"

void Player::Initialize()
{
	//インプット
	pInput_ = Input::GetInstance();
	//生成
	implFollowEye_ = std::make_unique<ImplFollowEye>();
	implFollowEye_->Initialize();

}

void Player::Update()
{
	//

	//操作
	InputCommand();

}

void Player::Draw()
{
}

void Player::InputCommand()
{
	if (pInput_->TriggerKey(DIK_SPACE)) {

	}


}
